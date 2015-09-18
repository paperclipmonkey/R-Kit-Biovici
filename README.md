#R-Kit Biovici Reader
This project works in collaboration with the R-Kit server.
It is designed to mock a Biovici reader device to work with the R-Kit Android App.

It requires an Arduino as well as a HC-06 Bluetooth module to work. Full parts requirements can be found in the parts.md file.

![Image of fritzing board](https://github.com/paperclipmonkey/R-Kit-Biovici/blob/master/Arduino_bb.png?raw=true)

##Build
To build the project you'll need access to a computer to program the Arduino and a soldering iron to solder pins on to the Arduino nano.

1. Assemble the device as in the fritzing image.
2. Install Arduino studio
3. Install any additional libraries needed by Arduino Studio to compile
4. Upload the code to the Arduino

##Run
Pair with the device from Android using pin 1234