#include "config.h"
#ifdef _ACCEL_ADXL345
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

/* Assign a unique ID to this sensor at the same time */
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);
void accelSetup() {
  accel.begin();
  accel.setRange(ADXL345_RANGE_16_G);
}
void accelLoop() {
  sensors_event_t event;
  accel.getEvent(&event);
  datas.accel.x=event.acceleration.x;
  datas.accel.y=event.acceleration.y;
  datas.accel.z=event.acceleration.z;
}
#endif