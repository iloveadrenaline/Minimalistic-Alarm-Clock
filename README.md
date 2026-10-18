# Minimalistic-Alarm-Clock

A 4-key alarm clock built by me on a Seeed XIAO Esp32-C3. Submitted to Hack Club's **Phantom** You Ship, We Ship program.

<img width="843" height="581" alt="Captură de ecran 2026-10-18 183512" src="https://github.com/user-attachments/assets/ee764963-3baf-4e60-a6ae-8652da0faae0" />



---

## Overview

This is a compact alarm clock designed by me, around the XIAO Esp32-C3. It has 4 MX-Cherry keys that are programmable into whatever you want. This project was made with the goal to design a modern alarm clock to digital detox.
**Project Link**: 

## Features

-4 Mechanical Switches
-2.25in TFT Screen for displaying the time of course
-Passive Buzzer for the sound
-60 degree angled display

## PCB Schematics
<img width="1123" height="674" alt="Captură de ecran 2026-10-17 223303" src="https://github.com/user-attachments/assets/28b49d7e-8888-46c5-8535-8cff021fca04" />
<img width="1183" height="781" alt="Captură de ecran 2026-10-17 223756" src="https://github.com/user-attachments/assets/14c901c2-40b0-4662-820c-11f3930e5ff5" />
<img width="1005" height="702" alt="Captură de ecran 2026-10-18 182551" src="https://github.com/user-attachments/assets/9272009d-acc9-4ddc-b274-dd93e06de209" />


## Bill of Materials (BOM)


1x Seeed XIAO Esp32-C3
1x 2.25in TFT Screen
4x MX-Style switches
4x white blank DSA keycaps
1x 3.3V piezo buzzer
1x Jumper wires female-female 20cm
8x Heatset insert M3x5x4
4x Screw M3x8mm
4x Screw M3x16mm

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






