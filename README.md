# Minimalistic-Alarm-Clock

A 4-key alarm clock built by me on a Seeed XIAO Esp32-C3. Submitted to Hack Club's **Phantom** You Ship, We Ship program.

<img width="843" height="581" alt="Captură de ecran 2026-10-18 183512" src="https://github.com/user-attachments/assets/ee764963-3baf-4e60-a6ae-8652da0faae0" />



---

## Overview

This is a compact alarm clock designed by me, around the XIAO Esp32-C3 microcontroller. We'll,  it's not the best but it's made by me.
It Features 4 mx-cherry switches with a TFT Display and a buzzer to play the sounds.
**CAD Link**: https://cad.onshape.com/documents/6fedfa32d8549fedebcc7a2f/w/9888169672ce6c286769ae5b/e/3693f4b94f23b41e8b603b94

## Features

-4 Mechanical Switches



-2.25in TFT Screen for displaying the time of course




-Passive 3.3v Buzzer for the sound



-60 degree angled display




## PCB Schematics
<img width="1123" height="674" alt="Captură de ecran 2026-10-17 223303" src="https://github.com/user-attachments/assets/28b49d7e-8888-46c5-8535-8cff021fca04" />
<img width="1183" height="781" alt="Captură de ecran 2026-10-17 223756" src="https://github.com/user-attachments/assets/14c901c2-40b0-4662-820c-11f3930e5ff5" />
<img width="1005" height="702" alt="Captură de ecran 2026-10-18 182551" src="https://github.com/user-attachments/assets/9272009d-acc9-4ddc-b274-dd93e06de209" />


## Bill of Materials (BOM)

| Qty | Item | Description | Approx. Unit Price | Vendor / Source Link |
| :---: | :--- | :--- | :---: | :---: |
| **1x** | **Seeed XIAO ESP32-C3** | Microcontroller with Wi-Fi & Bluetooth 5.0 | $4.90 | [Seeed Studio](https://www.seeedstudio.com/XIAO-ESP32C3-p-5432.html) |
| **1x** | **2.25" TFT Screen** | ST7789 / ST779 SPI Color LCD Display | $4.98 | [BuyDisplay](https://www.buydisplay.com/2-25-inch-tft-serial-spi-76x284-lcd-display-module-w-st7789p3) / [AliExpress](https://www.aliexpress.com) |
| **4x** | **MX-Style Switches** | Mechanical Switches (Cherry MX Kalih) | [Adafruit.com](https://www.adafruit.com/product/4954) |
| **4x** | **White Blank DSA Keycaps** | PBT/ABS Keycaps with DSA profile (1U size) | $0.695 | [Flashquark](https://flashquark.com) / [AliExpress](https://www.aliexpress.com) |
| **1x** | **3.3V Piezo Buzzer** | Active or Passive 3.3V Buzzer Module | ~$1.00 - $2.50 | [Adafruit](https://www.adafruit.com) / [Amazon](https://www.amazon.com) |
| **1x** | **Jumper Wires (Female-Female)** | 20cm Dupont cables (pack or individual strands) | ~$1.50 (pack) | [Amazon](https://www.amazon.com) / [AliExpress](https://www.aliexpress.com) |
| **8x** | **Heat-Set Inserts M3x5x4** | Brass threaded inserts for 3D prints (M3 inner, 5mm OD, 4mm L) | ~$0.10 ea | [CNC Kitchen](https://cnckitchen.store) / [Polt24](https://polt24.ee/en/threaded-inserts/496-heat-set-threaded-insert-m3x5x4mm-brass.html) |
| **4x** | **Screw M3x8mm** | M3 Button/Socket Head Cap Screws | ~$0.05 ea | [McMaster-Carr](https://www.mcmaster.com) / [Amazon](https://www.amazon.com) |
| **4x** | **Screw M3x16mm** | M3 Button/Socket Head Cap Screws | ~$0.05 ea | [McMaster-Carr](https://www.mcmaster.com) / [Amazon](https://www.amazon.com) |

> **Estimated Total Cost:** ~$15.00 – $22.00 USD (excluding bulk hardware packs and shipping).


## Firmware
The firmware is made in in INO that's all I can tell you , I'm very begginer to this so you can just Google it . Psst I recommend Claude 

## Repository Structure

```
Minimalistic-Alarm-Clock/
├── README.md
├── LICENSE
├── CAD/
│   ├──Alarm_Clock_Assembly.step  # full assembly
│   ├──Clock_Base.step
│   └── Clock_Top.step
├── PCB/
│   ├── clock.kicad_pro
│   ├── clock.kicad_sch
│   ├── clock.kicad_pcb
│   ├── Alarm_Clock_3D.step
│   └── Gerbers/
└── firmware/
│   └── clock_firmware
│
└── production/
    ├── Clock_Base.stl
    ├── Clock_Top.stl
    └──Gerbers.zip

```


## License

This project is released under the MIT License -- see in the repo

## Credits

- Built for [Hack Club's Phantom](https://phantom.hackclub.com) YSWS program
- MX switch / XIAO / TFT footprints from the Hackpad KiCad starter library
- Designed by [iloveadrenaline](https://github.com/iloveadrenaline)
- The software was made with minimal use of Antrophic Claude and with Google Gemini
  Peace out






