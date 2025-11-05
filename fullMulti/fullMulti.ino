#include "config.h"

 S_Datas datas;

void setup() {
  // put your setup code here, to run once:
  #ifdef _SCREEN
    screenLoop();
  #endif
  #ifdef _ACCEL
    accelSetup();
  #endif
  #ifdef _TIME
    timeSetup();
  #endif
   #ifdef _TEMP
    tempSetup();
  #endif
}

void loop() {
  // put your main code here, to run repeatedly:
  #ifdef _ACCEL
    accelLoop();
  #endif
  #ifdef _TIME
    timeLoop();
  #endif
   #ifdef _TEMP
    tempLoop();
  #endif
  #ifdef _SCREEN
    screenLoop();
  #endif
}
