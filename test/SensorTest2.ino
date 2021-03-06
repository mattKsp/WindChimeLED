/*
  Arduino (Pro Mini) based LED Wind Chime - sensor test 2 (array test)
  
  - written by Matt Standish (Thurstan/ksp) 
  - Released under Apache License v2.0 (see LICENCE file)
*/


int mainLoopDelay = 100;
const int numberOfSensors = 2;
const int numberOfSensorsA = A2;

int sensorValue[numberOfSensors];
int sensorValueMap[numberOfSensors];
boolean sensorTriggered[numberOfSensors];


void setup(){
  Serial.begin(9600);
  //pinMode(A0, INPUT);
  
  for(int i = A0; i < numberOfSensorsA; i++){
    pinMode(i, INPUT);
    sensorValue[i - 14] = 0;
    sensorValueMap[i - 14] = 0;
    sensorTriggered[i - 14] = false;
    Serial.print(i);
    Serial.println(" setup");
  }
  
  pinMode(3, OUTPUT);
}

void loop(){
  for(int i = A0; i < numberOfSensorsA; i++){
    sensorValue[i - 14] = (analogRead(i));
    
    Serial.println(sensorValue[i - 14]);
  }
  
  //sensorValue = (analogRead(A0));
  /*if (sensorValue > 0){
    
  sensorValueMap = map(sensorValue, 0, 1023, 0, 255);
  }
  analogWrite(3, sensorValueMap);*/
  
  /*Serial.print(sensorValue);
  Serial.print(" | ");
  Serial.println(sensorValueMap);*/
  delay(mainLoopDelay);
}
