#pragma once

#include <Arduino.h>
#include "DriveMotorInterface.h"
#include <Servo.h>
#include "../../Config.h"

class Esc : public DriveMotorInterface
{
    public:
        void init() override
        {
            esc.attach(ESC_PIN);
            esc.writeMicroseconds(1472);
        }

        void run(int32_t value) override
        {
            if (value > -50 && value < 50)
            {
                esc.writeMicroseconds(1472);
            } else {
                #ifdef REVERSE_DRIVE_MOTOR
                esc.writeMicroseconds(constrain(map(-value, -512, 512, 800, 2300), 544, 2400));
                #else
                esc.writeMicroseconds(constrain(map(value, -512, 512, 800, 2300), 544, 2400));
                #endif
            }
        }
    private:
        Servo esc;
};
