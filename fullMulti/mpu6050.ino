#include "config.h"
#ifdef _ACCEL_MPU6050
#include <Arduino.h>
#include <TinyMPU6050.h>

/*
 *  Constructing MPU-6050
 */
MPU6050 mpu (Wire);

void accelSetup() {
    mpu.Initialize();
    mpu.Calibrate();

}
void accelLoop() {
    mpu.Execute();

  datas.accel.x =mpu.GetAccX();
  datas.accel.y = mpu.GetAccY();
  datas.accel.z = mpu.GetAccZ();

  datas.angle.x=mpu.GetAngX();
  datas.angle.y=mpu.GetAngY();
  datas.angle.z=mpu.GetAngZ();
}

#endif
