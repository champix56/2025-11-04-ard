#include "config.h"
#ifdef _RTC_DS1307
#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
void timeSetup() {
}

void timeLoop() {

  if (RTC.read(datas.tm)) {
  }
}
#endif