/*
  Arduino (Pro Mini) based LED Wind Chime - tilt-switch test 1
  
  - written by Matt Standish (Thurstan/ksp) with help from Dan Kernan (Techno)
  - Released under Apache License v2.0 (see LICENCE file)
*/

boolean debug = true;

String progName = "TiltSwitchTest1";
String progVers = "0.01";
String initMsg;

int mainLoopDelay = 10;

const int switchPin = 2;
int switchState = 0;
const int LEDPin = 13;
boolean led13State = LOW;      // on-board LED


void setup(){
  Serial.begin(9600);
  if (debug){
    initMsg = String(progName + " vers." + progVers + " initialised");       
    Serial.println(".");  
    Serial.println(".");
    Serial.println(initMsg);
    Serial.println("."); 
    Serial.println(".");
  }
  
  // sensors
  pinMode(switchPin, INPUT);
  
  // LEDs
  pinMode(LEDPin, OUTPUT);
  
  setupComplete();
}  // END setup

void loop(){
  if (debug){Serial.println(".");}
  
  switchState = digitalRead(switchPin);
  if (switchState == LOW) {     
    // turn LED on:    
    digitalWrite(LEDPin, HIGH);
    if (debug){Serial.println("switch state = LOW");}
  } 
  else {
    // turn LED off:
    digitalWrite(LEDPin, LOW);
    if (debug){Serial.println("switch state = HIGH");}
  }
  
  delay(mainLoopDelay);
}  // END loop


void setupComplete() {
  digitalWrite(LEDPin, LOW);
  delay(1000);
  digitalWrite(LEDPin, HIGH);
  delay(1000);
  digitalWrite(LEDPin, LOW);
  delay(1000);
  LEDTripleFlash();
  if (debug){Serial.println("setup complete");}
}

void LEDTripleFlash() {
  // triple flash(flip) the onboard LED
  for (int flashFlip = 0; flashFlip < 6; flashFlip++) {
    delay(250);
    led13State = !led13State;
    digitalWrite(LEDPin, led13State);
  }
  delay(1);
}
