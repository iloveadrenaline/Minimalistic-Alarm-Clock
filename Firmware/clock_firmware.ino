#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h> // Change to Adafruit_SH1106.h if your OLED uses SH1106

// --- PIN DEFINITIONS (Based on your Schematic) ---
#define PIN_SW1  0  // D0
#define PIN_SW2  1  // D1
#define PIN_SW3  2  // D2
#define PIN_SW4  3  // D3

#define PIN_SCL  4  // D4 (OLED SCL / I2C Clock)
#define PIN_SDA  8  // D8 (OLED SDA / I2C Data)
#define PIN_BZ1  7  // D7 (Passive Buzzer)

// OLED display settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// --- TIME & ALARM VARIABLES ---
int hours = 12;
int minutes = 0;
int seconds = 0;

int alarmHours = 7;
int alarmMinutes = 0;
bool alarmEnabled = true;
bool alarmTriggered = false;

// Millis tracking for internal clock
unsigned long previousMillis = 0;
const long interval = 1000; // 1 second

// UI States
enum State {
  STATE_NORMAL,
  STATE_SET_TIME,
  STATE_SET_ALARM
};
State currentState = STATE_NORMAL;
int editCursor = 0; // 0: Hours, 1: Minutes

void setup() {
  // Initialize Serial for debugging (optional)
  Serial.begin(115200);

  // Initialize Pins
  pinMode(PIN_SW1, INPUT_PULLUP);
  pinMode(PIN_SW2, INPUT_PULLUP);
  pinMode(PIN_SW3, INPUT_PULLUP);
  pinMode(PIN_SW4, INPUT_PULLUP);
  pinMode(PIN_BZ1, OUTPUT);

  // Initialize I2C with custom pins for XIAO ESP32-C3
  Wire.begin(PIN_SDA, PIN_SCL);

  // Initialize OLED Display
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.print("XIAO Clock Initialized");
  display.display();
  delay(1000);
}

void loop() {
  handleTimekeeping();
  handleButtons();
  checkAlarm();
  updateDisplay();
}

// --- TIMEKEEPING ---
void handleTimekeeping() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    seconds++;
    if (seconds >= 60) {
      seconds = 0;
      minutes++;
      if (minutes >= 60) {
        minutes = 0;
        hours++;
        if (hours >= 24) {
          hours = 0;
        }
      }
    }
  }
}

// --- BUTTON HANDLING ---
/* 
   SW1 (D0): Mode / Select (Cycles Normal -> Set Time -> Set Alarm)
   SW2 (D1): Increment / Value Up (+)
   SW3 (D2): Decrement / Value Down (-)
   SW4 (D3): Snooze / Stop Alarm / Toggle Alarm On/Off
*/
void handleButtonPress(int button) {
  switch (currentState) {
    case STATE_NORMAL:
      if (button == 1) { // SW1: Switch to Set Time mode
        currentState = STATE_SET_TIME;
        editCursor = 0;
      } else if (button == 4) { // SW4: Toggle Alarm On/Off
        alarmEnabled = !alarmEnabled;
        if (alarmTriggered) {
          alarmTriggered = false; // Stop active alarm
          noTone(PIN_BZ1);
        }
      }
      break;

    case STATE_SET_TIME:
      if (button == 1) { // SW1: Move cursor or exit
        editCursor++;
        if (editCursor > 1) {
          currentState = STATE_SET_ALARM; // Move to set alarm next
          editCursor = 0;
        }
      } else if (button == 2) { // SW2: Increment (+<h4>)
        if (editCursor == 0) hours = (hours + 1) % 24;
        else if (editCursor == 1) minutes = (minutes + 1) % 60;
      } else if (button == 3) { // SW3: Decrement (-)
        if (editCursor == 0) hours = (hours - 1 + 24) % 24;
        else if (editCursor == 1) minutes = (minutes - 1 + 60) % 60;
      } else if (button == 4) { // SW4: Quick exit back to normal
        currentState = STATE_NORMAL;
      }
      break;

    case STATE_SET_ALARM:
      if (button == 1) { // SW1: Return to Normal mode
        currentState = STATE_NORMAL;
      } else if (button == 2) { // SW2: Increment Alarm
        if (editCursor == 0) alarmHours = (alarmHours + 1) % 24;
        else if (editCursor == 1) alarmMinutes = (alarmMinutes + 1) % 60;
      } else if (button == 3) { // SW3: Decrement Alarm
        if (editCursor == 0) alarmHours = (alarmHours - 1 + 24) % 24;
        else if (editCursor == 1) alarmMinutes = (alarmMinutes - 1 + 60) % 60;
      } else if (button == 4) { // SW4: Toggle Alarm Hour/Minute cursor
        editCursor = (editCursor + 1) % 2;
      }
      break;
  }
}

// Simple debounce and button reader
void handleButtons() {
  static unsigned long lastDebounceTime = 0;
  unsigned long debounceDelay = 200;

  if (millis() - lastDebounceTime > debounceDelay) {
    if (digitalRead(PIN_SW1) == LOW) { lastDebounceTime = millis(); handleButtonPress(1); }
    else if (digitalRead(PIN_SW2) == LOW) { lastDebounceTime = millis(); handleButtonPress(2); }
    else if (digitalRead(PIN_SW3) == LOW) { lastDebounceTime = millis(); handleButtonPress(3); }
    else if (digitalRead(PIN_SW4) == LOW) { lastDebounceTime = millis(); handleButtonPress(4); }
  }
}

// --- ALARM & BUZZER LOGIC ---
void checkAlarm() {
  if (alarmEnabled && !alarmTriggered) {
    if (hours == alarmHours && minutes == alarmMinutes && seconds == 0) {
      alarmTriggered = true;
    }
  }

  // Play buzzer pattern if alarm is triggered
  if (alarmTriggered) {
    // Simple beep pattern using passive buzzer
    unsigned long currentMillis = millis();
    if ((currentMillis / 500) % 2 == 0) {
      tone(PIN_BZ1, 1000); // 1kHz tone
    } else {
      noTone(PIN_BZ1);
    }
  }
}

// --- DISPLAY ROUTINE ---
void updateDisplay() {
  display.clearDisplay();

  // Header / Status bar
  display.setTextSize(1);
  display.setCursor(0, 0);
  if (currentState == STATE_NORMAL) {
    display.print(alarmEnabled ? "ALARM: ON" : "ALARM: OFF");
  } else if (currentState == STATE_SET_TIME) {
    display.print("> SET TIME <");
  } else if (currentState == STATE_SET_ALARM) {
    display.print("> SET ALARM <");
  }

  // Draw Time (Large text)
  display.setTextSize(2);
  display.setCursor(10, 20);
  if (hours < 10) display.print("0");
  display.print(hours);
  display.print(":");
  if (minutes < 10) display.print("0");
  display.print(minutes);
  display.print(":");
  if (seconds < 10) display.print("0");
  display.print(seconds);

  // Draw Alarm Info at bottom
  display.setTextSize(1);
  display.setCursor(0, 50);
  display.print("Alarm: ");
  if (alarmHours < 10) display.print("0");
  display.print(alarmHours);
  display.print(":");
  if (alarmMinutes < 10) display.print("0");
  display.print(alarmMinutes);

  if (alarmTriggered) {
    display.setCursor(75, 50);
    display.print("[WAKE UP!]");
  }

  display.display();
}