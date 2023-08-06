#pragma once

#include <Arduino.h>
#include "DriveMotorInterface.h"
#include <ESP32_Servo.h>
#include "../../Config.h"

class Esc : public DriveMotorInterface
{
    public:
        void init() override
        {
            esc.attach(ESC_PIN);
            esc.writeMicroseconds(1550);
        }

        void run(int32_t value) override
        {
            if (value > -25 && value < 25)
            {
                esc.writeMicroseconds(1550);
            } else {
                esc.writeMicroseconds(map(value, -128, 128, 800, 2300));
            }
        }
    private:
        Servo esc;
};
