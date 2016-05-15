/*
  Arduino (Pro Mini) based LED Wind Chime - project 1
  
  - wind chime weight swings and knocks the tubes
  - 6 sensors pick up knocks and trigger 6 led's
  - led's quick on, then fade off
  - led's brightness determined by knock value

  - written by Matt Standish (Thurstan/ksp) with help from Dan Kernan (Techno)
  - Released under Apache License v2.0 (see LICENCE file)
*/

boolean debug = true;

String progName = "WindChime1";
String progVers = "0.93";
String initMsg;

int mainLoopDelay = 10;
const int numberOfSensors = 2;
const int sensorPinSpread[] = { 2, 4, 7, 8, 12, 13 };
const int numberOfLEDs = 2;
const int LEDPinSpread[] = { 3, 5, 6, 9, 10, 11 };

boolean sensorTriggered[numberOfSensors];
long lastSensorReadTime[numberOfSensors];
long sensorDebounceDelay[numberOfSensors];
int sensorState[numberOfSensors];

int LEDBrightness[numberOfLEDs];
int LEDDecayRate[numberOfLEDs];
int LEDBrightnessMapMin[numberOfLEDs];
int LEDBrightnessMapMax[numberOfLEDs];
int LEDBrightnessMin[numberOfLEDs];
int LEDBrightnessMax[numberOfLEDs];
boolean led13State = LOW;


void setup(){
  if (debug){
    Serial.begin(9600);
    initMsg = String(progName + " vers." + progVers + " initialised");       
    Serial.println(".");  
    Serial.println("."); 
    Serial.println("."); 
    Serial.println(initMsg);
    Serial.println("."); 
  }
  
  // sensors
  for (int i = 0; i < numberOfSensors; i++){
    pinMode(sensorPinSpread[i], INPUT);
    sensorTriggered[i] = false;    // setup initial sensor triggered spread
    lastSensorReadTime[i] = 0;
    sensorDebounceDelay[i] = 10;  // 100 // 150
    sensorState[i] = 0;  // LOW  // off initially until contact made
    if (debug){Serial.print("Digital INPUT "); Serial.print(i); Serial.print(" ["); Serial.print(sensorPinSpread[i]); Serial.println("] setup");}
  }
  
  // LEDs
  for (int i = 0; i < numberOfLEDs; i++){
    pinMode(LEDPinSpread[i], OUTPUT);        // setup led digital output pins. + 3 as using pins 3-8  (!!!! pin 2 is not PWM !!!!)
    LEDBrightness[i] = 0;            // 0 - setup initial LED brightness spread
    LEDDecayRate[i] = 2;              // 2 - setup initial LED decay rate spread
    LEDBrightnessMapMin[i] = 0;     // 0 /* used for map() */
    LEDBrightnessMapMax[i] = 255;   // 255
    LEDBrightnessMin[i] = 0;        /* used for constrain */
    LEDBrightnessMax[i] = 255;      // 10
    if (debug){Serial.print("LED OUTPUT "); Serial.print(i); Serial.print(" ["); Serial.print(LEDPinSpread[i]);  Serial.println("] setup");}
  }
  
  pinMode(13, OUTPUT);  // on-board LED !!! DISABLE if using all 6 LEDs in spread !!!
  
  setupComplete();
}  // END setup

void loop(){
  
  for (int i = 0; i < numberOfSensors; i++){
 
    // read and process sensor reading if allowed
    if ((millis() - lastSensorReadTime[i]) > sensorDebounceDelay[i]) {
      sensorState[i] = (digitalRead(sensorPinSpread[i]));
      delay(1);
      if (debug){Serial.print("sensorState "); Serial.print(i); Serial.print(" "); Serial.print(sensorState[i]); Serial.print(" | ");}
      lastSensorReadTime[i] = millis();
      if (sensorTriggered[i]){
      } else {
      }
      if (sensorState[i] == HIGH) {
        // set LEDs on bang
        //for (int i = 0; i < numberOfLEDs; i++){
          LEDBrightness[i] = map(255, 0, 255, LEDBrightnessMapMin[i], LEDBrightnessMapMax[i]);
          if (debug){Serial.print("LEDBrightness "); Serial.print(i); Serial.print(" "); Serial.print(LEDBrightness[i]); Serial.print(" | ");}
          analogWrite(LEDPinSpread[i], LEDBrightness[i]);
        //}
        sensorTriggered[i] = true;
      }
    } else {
      if (sensorTriggered[i]){
        if (debug){}
      } else {
      }
    }
    
  } // END sensors for loop
  if (debug){Serial.println(".");}
  
  // set LEDs. this is for the decay..
  for (int i = 0; i < numberOfLEDs; i++){
        
    if (sensorTriggered[i]){
    
        LEDBrightness[i] = LEDBrightness[i] - LEDDecayRate[i];
        analogWrite(LEDPinSpread[i], LEDBrightness[i]);
        if (LEDBrightness[i] < 2){
          analogWrite(LEDPinSpread[i], 0);
          LEDBrightness[i] = 0;
          sensorTriggered[i] = false;
        }
        
        if (debug){Serial.print(" | L "); Serial.println(LEDBrightness[i]);}
        delay(1);
        
    }  // END if sensorTriggered 
  }  // END for loop

  
   delay(mainLoopDelay);
}  // END main loop


void setupComplete() {
  digitalWrite(13, LOW);
  delay(1000);
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
  LEDTripleFlash();
  if (debug){Serial.println("setup complete");}
}

void LEDTripleFlash() {
  // triple flash(flip) the onboard LED
  for (int flashFlip = 0; flashFlip < 6; flashFlip++) {
    delay(250);
    led13State = !led13State;
    digitalWrite(13, led13State);
  }
  delay(1);
}
