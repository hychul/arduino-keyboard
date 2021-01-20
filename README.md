# Arduino Keyboard Project
![version](https://img.shields.io/badge/Version-1.0–SNAPSHOT-green.svg?style=flat-square) ![license](https://img.shields.io/badge/License-BEER–WARE-orange.svg?style=flat-square)

아두이노로 키보드 만들기

# Modules
- ~~Dreamer Nano~~  
- ~~74HC595 shift register~~
- Teensy 2.0
- KY-040 rotary encoder
- 0.91 inch oled I2C
- 1N4148 diode

<details>
<summary>The reason why Dreamer Nano and 74HC595 shift register were replaced with Teensy 2.0</summary>
<div markdown="1">

## Dreamer Nano

![Nano_drawing](https://user-images.githubusercontent.com/18159012/103922316-ebcc3c80-5156-11eb-921f-36098731bf51.png)

## 74HC595 shift register

드리머 나도 설명 페이지에 20개의 디지털 핌과 6개의 아날로그 핀이 존재한다고 하여 26개 핀이 존재하는 줄 알았다. 하지만 정확하게는 14개의 디지털 핀과 6개의 디지털 핀으로 사용할수 있는 아날로그 핀을 의미하여 사용할 수 있는 핀의 갯수는 20개였다.

만약 단순히 65% 배열의 키보드를 만들고 싶었다면 20개의 핀만으로 충분했겠지만, 로타리 인코더와 OLED 패널을 달고 싶었기 때문에 그러지 못했다. ㅠ

키보드 스위치를 위해 20 핀, 로타리 인코더를 위해 3 핀 그리고 OLED응 위해 2핀으로 총 25개의 핀이 필요하다. 그중 스위치 핀 20개 중 15개만 OUTPUT 핀으로 설정되고 나머지 핀들은 INPUT으로 설정되어야 한다. 

74HC595 쉬프트 레지터 모듈은 3개핀을 사용하여 8개의 OUTPUT 핀으로 사용할 수 있도록 하기 때문에 20개의 핀을 갖는 드리머 나노를 사용하여 25개 핀을 사용할 수 있도록 할 수 있다...고 믿었으나 쉬프트 레지스터 자체의 delay가 있는 것인지 제대로 동작을 하지 않았다...

</div>
</details>

## Teensy 2.0
![teensy 2 0 pin](https://user-images.githubusercontent.com/18159012/105130659-ca8e2780-5b2a-11eb-9fca-6a98ea71d7ab.png)


## KY-040 rotary encoder
![KY-040](https://user-images.githubusercontent.com/18159012/105130140-cdd4e380-5b29-11eb-9bc4-e8e5102cd608.jpg)

## 0.91 inch oled I2C
![OLED](https://user-images.githubusercontent.com/18159012/105130654-c7933700-5b2a-11eb-820e-b3490dd4c683.jpg)

## 1N4148 diode
![1N4148](https://user-images.githubusercontent.com/18159012/105130864-23f65680-5b2b-11eb-9553-2ddb55b57b7e.jpg)
