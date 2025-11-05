#include "config.h"
#ifdef  _SCREEN_LCD1602_I2C
#include <LiquidCrystal_I2C.h>
#define _LCD1602_TEMP_X 8
#define _LCD1602_TEMP_Y 1
#define _LCD1602_TEMP_W 5 

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void screenSetup(){
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
}
void screenLoop(){
  #ifdef _TEMP

  lcd.setCursor(_LCD1602_TEMP_X, _LCD1602_TEMP_Y);
  for(int i=0;i<_LCD1602_TEMP_W;i++){
    lcd.print(' ');
  }
  lcd.setCursor(_LCD1602_TEMP_X, _LCD1602_TEMP_Y);
  lcd.print(datas.temp);
  #endif
}
#endif