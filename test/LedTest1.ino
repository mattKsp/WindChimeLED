/*
  Arduino (Pro Mini) based LED Wind Chime - LED test 1
  
  - written by Matt Standish (Thurstan/ksp) 
  - Released under Apache License v2.0 (see LICENCE file)
*/

const int numberOfLEDs = 1;
int startPin = 11;  // 3
int brightness[numberOfLEDs];

void setup()  { 
  Serial.begin(9600);
  for(int i = 0; i < numberOfLEDs; i++){
    pinMode(i + startPin, OUTPUT);
    brightness[i] = 0;
  }
} 

void loop()  { 
  
  for(int i = 0; i < numberOfLEDs; i++){
    Serial.print("pin ");
    Serial.println(i + startPin);
    
    for(int f = 0; f < 256; f++){
      //analogWrite(i + 3, brightness[i]); 
      //Serial.print(brightness[i]);
      analogWrite(i + startPin, f); 
      Serial.println(f);
      //brightness[i] = f;
      //brightness[i] = brightness[i] + 25;
      if (f >= 255){
        //brightness[i] = 0;
        //f = 10;  // breaks the loop
        analogWrite(i + startPin, 0);
      }
      delay(10);
    }
    
  }
  
  Serial.println(".");
  delay(100);                            
}
