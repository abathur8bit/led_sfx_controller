# Overview
Controls a 5meter led strip (300 leds) and 8 pin sound board.

# Programming via servo
See [spreadsheet](https://docs.google.com/spreadsheets/d/1dWq5eDLXgElstz2D51x0PZAC7wyFrNt9LvLtejiKFjg/edit?gid=0#gid=0) 

# Giant LED
1 + red
2 - neg common
3 + green
4 + blue

```

 /-----\
|       |
|       |
---------
 | | | |
 | | | |
   | 
 1 2 3 4
```

# LED Strip 12v
Vcc Red
Data Green
Gnd White

# Servo
Pin 3 on a Futaba servo has the tab.

| Pin | Meaning | JR Color |
| --- | ------- | -------- |
| 1   | GND     | brown    |
| 2   | 5V      | red      |
| 3   | PWM     | orange   |

# Programming servo via REV Control Hub
[REV Control Hub](https://www.revrobotics.com/rev-31-1595/) [programming servos](https://docs.revrobotics.com/duo-control/hello-robot-java/part-1/programming-servos)
- 270deg of motion, -135deg - +135deg 
- 0135
- -135 = 0
- 0 = 0.5
- +135 = 1

| deg  | program | usec |
| ---- | ------- | ---- |
| -135 | 0       | 500  |
| 0    | 0.5     | 1500 |
| 135  | 1       | 2500 |


# ESP32 Board
[[Hiletgo ESP32 OLED WiFi Kit]]

![[esp32 oled wifikit 32 top1.png]]

# Stereo Amp
[Product page](https://www.adafruit.com/product/1752), [assembly learn page](https://learn.adafruit.com/adafruit-20w-stereo-audio-amplifier-class-d-max9744).
$20
Stereo 20W Class D Audio Amplifier - MAX9744
![[Amp-MAX9744.png]]

Draws about 30-50mA quiescent current, plus whatever it uses for amplifying. 
Can run on 4.5-12V DC
# Sound Board
[Product page](https://www.adafruit.com/product/2341), [learn page](https://learn.adafruit.com/adafruit-audio-fx-sound-board/triggering-audio).
$20
Adafruit Audio FX Mini Sound Board - WAV/OGG Trigger 16MB Flash
![[MiniSoundBoard.png]]

