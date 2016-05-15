# WindChimeLED

Arduino based LED reactive wind chime.

### Premis
- the wind chime center weight swings and knocks the tubes
- sensors pick up knocks and trigger the led's
- led's quick on, then fade off
- led's brightness determined by knock value

### Equipment
- Wind chime (6-tubes/bamboo)
- Arduino (Pro Mini)
- Accelerometer
- 6 sensors
- 6 LED's
- Copper tape

### Setup
- LED's are mounted in the bottom of the tubes (i drilled a hole through from the top)
- knocks on the tubes are picked up by 
  * (a) piezo sensors mounted on the tubes, 
  * (b) tilt-switches mounted on the tubes, 
  * (c) corresponding copper strips on both the center weight and the tubes (connecting to make circuit), 
  * (d) piezo strip mounted around the center weight (triggered by collision with tubes), 
  * (e) accelerometer chips mounted on the tubes.

### Testing
- Sensors tested
  * piezo, 
  * tilt-switch, 
  * copper strips (connecting with center weight)
- Sensors NOT tested (more expensive)
  * piezo strip with weight, 
  * accelerometer chip


### Licence
- written by Matt Standish (Thurstan/ksp) with help from Dan Kernan (Techno)
- Released under Apache License v2.0 (see LICENCE file)
