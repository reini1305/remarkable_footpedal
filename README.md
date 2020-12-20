# Remarkable 2 Foot Pedal

This repository contains schematics, a 3D model and code for a Teensy LC to connect a foot pedal switch to the pogo pins of a reMarkable 2.

## Pictures
Assembled and in action:

![Action](https://raw.githubusercontent.com/reini1305/remarkable_footpedal/main/action.jpg)

Pogo pin converter:

![Pogo](https://raw.githubusercontent.com/reini1305/remarkable_footpedal/main/converter.jpg)

Foot pedal:

![Foot pedal](https://raw.githubusercontent.com/reini1305/remarkable_footpedal/main/switch.jpg)

## Necessary Hardware
- Teensy LC (or better) [here](https://www.pjrc.com/teensy/teensyLC.html)
- Foot pedal (e.g. [from Digikey](https://www.digikey.at/product-detail/de/adafruit-industries-llc/423/1528-1137-ND/5353597))
- USB-A connector (e.g. [from Digikey](https://www.digikey.at/product-detail/de/on-shore-technology-inc/USB-A1HSW6/ED2989-ND/2677750))
- Pogo pins (e.g. [from Digikey](https://www.digikey.at/product-detail/de/mill-max-manufacturing-corp/815-22-005-30-001101/ED1232-05-ND/3913218))
- Small neodym magnets to hold the adapter to the RM2

## Schematics
The pinout of the pogo pins is described in the [remarkable wiki](https://remarkablewiki.com/tech/rm2_otg_pogo):
~~~
(left to right, closest to USB-C)  
  
GND, ID, D+, D-, VBUS
~~~
Connecting GND to ID will enable the OTG power supply. If you mount the USB-port upside/down, you can simply connect the pins 1:1 as the USB pinout is:
~~~
(right to left)  
  
GND, D+, D-, VBUS
~~~

For the foot pedal, connect the switch to ground and a pin on the Teensy (the example code uses pin 2).

## Software
The sketch for the Teensy reads the input from pin 2. If it is pressed only once within 300ms, "Arrow Right" will be sent as keypress, it it is pressed twice, "Arrow Left" will be sent. This allows you to move forward and back through the document.