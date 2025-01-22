#pragma once

#include <Arduino.h>
#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#include "../../Config.h"

class Mpu6050
{
    public:
        void init();
        void calculate();
    private:
        MPU6050 mpu;
        uint8_t fifoBuffer[45];         // буфер
};

