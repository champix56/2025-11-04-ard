#ifndef _CONFIG_
#define _CONFIG_

//composants actifs 
  #define _TEMP_DS18B20
  #define _RTC_DS1307
  #define _ACCEL_MPU6050
  //#define _ACCEL_ADXL345
  //#define _SCREEN_ST7735
  #define _SCREEN_LCD1602_I2C
//configuration des composant
  #ifdef _TEMP_DS18B20
  // Data wire is plugged into port 2 on the Arduino
  #define ONE_WIRE_BUS 2
  #define _TEMP
  #endif
  #ifdef _RTC_DS1307
    #define _TIME
  #endif
  #ifdef _ACCEL_MPU6050
    #define _ACCEL
  #endif
  #ifdef _ACCEL_ADXL345
    #define _ACCEL
  #endif
  #ifdef _SCREEN_LCD1602_I2C
    #define _SCREEN
  #endif
  #ifdef _SCREEN_ST7735
    #define _SCREEN
    #define TFT_CS        10
    #define TFT_RST        9 // Or set to -1 and connect to Arduino RESET pin
    #define TFT_DC         8
  #endif
  #include <TimeLib.h>
  struct S_float3D {
    float x, y, z;
  };
  typedef struct {
    #ifdef _TEMP
      float temp;
    #endif
    #ifdef _ACCEL
      struct S_float3D accel;
      struct S_float3D angle;
    #endif
    #ifdef _TIME
      tmElements_t tm;
    #endif
  }S_Datas ; 
#endif
