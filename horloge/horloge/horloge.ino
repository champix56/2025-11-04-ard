//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 14

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

LiquidCrystal_I2C lcd(0x27, 16, 2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
uint8_t CHAR_DEG[8] = {
  B11100,
  B10100,
  B11100,
  0x0, 0x0, 0x0, 0X0
};
void setup() {
  lcd.init();  // initialize the lcd
  lcd.createChar(0, CHAR_DEG);
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3, 0);
  lcd.print("Demat breizh");
  delay(3000);
  lcd.clear();
  lcd.setCursor(14, 1);
  lcd.print('C');
  sensors.begin();
}
void loop() {
  tmElements_t tm;

  if (RTC.read(tm)) {
    char buff[9]="";
    lcd.setCursor(4, 0);
    sprintf(buff,"%02d:%02d:%02d",tm.Hour,tm.Minute,tm.Second);
    lcd.print(buff);
  }
  sensors.requestTemperatures();  // Send the command to get temperatures
  float tempC = sensors.getTempCByIndex(0);

  // Check if reading was successful
  if (tempC != DEVICE_DISCONNECTED_C) {
    lcd.setCursor(9, 1);
    lcd.print("     ");
    lcd.setCursor(9, 1);
    lcd.print(tempC);
  }
  delay(500);
}
