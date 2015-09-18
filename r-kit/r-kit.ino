/* Imitate a Biovi reader using Arduino.
** Code Michael Waterworth
**
*/
#include "Timer.h"

Timer t;
int state = 0;
int last = 0;

const int calibrationButtonPin = 2;
const int readingButtonPin = 3;

//Used to store data about the previous pin values
int calibrationStateLast = 0;
int readingStateLast = 0;

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

/*
Setup the arduino device once on turn on
*/
void setup() {
    Serial.begin(9600); // Default connection rate for my BT module
    
    // initialize the pushbutton pin as an input:
    pinMode(calibrationButtonPin, INPUT);   
    pinMode(readingButtonPin, INPUT);
}

/*
Main loop
Checks the states of buttons
as well as responding to a line of text coming in over Serial
*/
void loop() {
    t.update();
    int calibrationState = digitalRead(calibrationButtonPin);
    int readingState = digitalRead(readingButtonPin);
    
    if(calibrationState != calibrationStateLast){
      sendStartCalibration();
      calibrationStateLast = calibrationState;
      t.after(5000, sendEndCalibration);
    } else {
      calibrationStateLast == 0;
    }
    
    if(readingState != readingStateLast){
      sendStartReading();
      readingStateLast = readingState;
      t.after(5000, sendEndReading);
    } else {
      readingStateLast == 0;
    }
    
    if (stringComplete) {
      if(inputString == "isBiovici"){
        Serial.println("isBiovici:true");
      } 
      // clear the string:
      inputString = "";
      stringComplete = false;
    }

}

/*
  SerialEvent occurs whenever data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    } else {
      inputString += inChar;
    }
  }
}

void sendStartCalibration(){
    Serial.println("Calibration started");
}

void sendEndCalibration(){
    Serial.println("Calibration finished");
}

void sendStartReading(){
    Serial.println("Reading started");
}

void sendEndReading(){
    Serial.println("Reading: 11");
}
