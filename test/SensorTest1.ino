/*
  Arduino (Pro Mini) based LED Wind Chime - sensor test 1
  
  - written by Matt Standish (Thurstan/ksp) 
  - Released under Apache License v2.0 (see LICENCE file)
*/


int mainLoopDelay = 100;
int sensorValue = 0;
int sensorValueMap = 0;
boolean sensorTriggered = false;

void setup(){
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(3, OUTPUT);
}

void loop(){
  sensorValue = (analogRead(A0));
  if (sensorValue > 0){
    
  sensorValueMap = map(sensorValue, 0, 1023, 0, 255);
  }
  analogWrite(3, sensorValueMap);
  
  Serial.print(sensorValue);
  Serial.print(" | ");
  Serial.println(sensorValueMap);
  delay(mainLoopDelay);
}
