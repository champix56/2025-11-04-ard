#include "config.h"
#ifdef _TEMP_DS18B20
//#include "config_pin.h"
#include <OneWire.h>
#include <DallasTemperature.h>



// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);
void tempSetup() {
  sensors.begin();
}
void tempLoop() {
  sensors.requestTemperatures();  // Send the command to get temperatures
  float tempC = sensors.getTempCByIndex(0);

  // Check if reading was successful
  if (tempC != DEVICE_DISCONNECTED_C) {

    //...
  }
}
#endif