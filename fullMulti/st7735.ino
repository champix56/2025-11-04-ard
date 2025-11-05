#include "config.h"
#ifdef _SCREEN_ST7735
#include <Adafruit_GFX.h>     // Core graphics library
#include <Adafruit_ST7735.h>  // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h>  // Hardware-specific library for ST7789
#include <SPI.h>
#include "ST7735_positions.h"
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
void screenSetup() {
  tft.initR(INITR_BLACKTAB);  // Init ST7735S chip, black tab
  tft.fillScreen(ST7735_BG_COLOR);
}
void screenLoop() {
#ifdef _TEMP
  tft.fillRect(ST7735_TEMP_X, ST7735_TEMP_Y, ST7735_TEMP_W, 8 * ST7735_TEMP_SIZE, ST7735_BG_COLOR);
  tft.setCursor(ST7735_TEMP_X, ST7735_TEMP_Y);
  tft.setTextSize(ST7735_TEMP_SIZE);
  tft.print(datas.temp);
#endif
}
void staticViewContainer() {
#ifdef _TEMP
  tft.setCursor(ST7735_TEMP_ANNOUNCE_X, ST7735_TEMP_ANNOUNCE_Y);
  tft.setTextSize(ST7735_TEMP_SIZE);
  tft.print(ST7735_TEMP_ANNOUNCE);
#endif
}
#endif