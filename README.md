# Arduino Keyboard Project
![version](https://img.shields.io/badge/Version-1.0–SNAPSHOT-green.svg?style=flat-square) ![license](https://img.shields.io/badge/License-BEER–WARE-orange.svg?style=flat-square)

Custom keyboard based on arduino board.

# Modules
- Dreamer Nano
- KY-040 rotary encoder
- 0.91 inch oled I2C
- 1N4148 diode
- 74HC595 shift register

## Dreamer Nano

![Nano_drawing](https://user-images.githubusercontent.com/18159012/103922316-ebcc3c80-5156-11eb-921f-36098731bf51.png)

## 74HC595 shift register

Dreamer Nano product page said there are 20 digital pins and analog 6 exist but the 20 pin include 14 digital pins and 6 analog pins that can be used as digital pin.

If I want create only keyboard that has 65% keyboard layout, it could be enough to connect keys. But I want to connect knob and oled too.

The keyboard I want need 20 pins for key and 3 for knob and 2 for oled. Luckly only 5 pins of key pins are input and rest of them is output pins. **74HC595** take 3 pins to connect with arduino and add 8 more output. So I can use 25 pins consisting of 17 in-out and 8 output pins.
