/* Imitate a Biovi reader using Arduino.
** Code Michael Waterworth
**
*/
#include "Timer.h"

Timer t;
int ledPin = 13;  // use the built in LED on pin 13 of the Uno
int state = 0;
int last = 0;

const int calibrationButtonPin = 2;
const int readingButtonPin = 3;

//Used to store data about the previous pin values
int calibrationStateLast = 0;
int readingStateLast = 0;

void setup() {
    // sets the pins as outputs:
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);
    Serial.begin(9600); // Default connection rate for my BT module
    
    // initialize the pushbutton pin as an input:
    pinMode(calibrationButtonPin, INPUT);   
    pinMode(readingButtonPin, INPUT);
}

void loop() {
    t.update();
    int calibrationState = digitalRead(calibrationButtonPin);
    int readingState = digitalRead(readingButtonPin);
    
    if(calibrationState != calibrationStateLast){
      sendStartCalibration();
      calibrationStateLast = calibrationState;
      t.after(3000, sendEndCalibration);
    } else {
      calibrationStateLast == 0;
    }
    
    if(readingState != readingStateLast){
      sendReading();
      readingStateLast = readingState;
    } else {
      readingStateLast == 0;
    }
}

void sendStartCalibration(){
    Serial.println("Calibration started");
}

void sendEndCalibration(){
    Serial.println("Calibration finished");
}

void sendReading(){
    Serial.println("Reading: 11");
}
