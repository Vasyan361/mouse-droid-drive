#pragma once

#include <Arduino.h>
#include "DriveMotorInterface.h"
#include "../../Config.h"
#include <GyverMotor.h>


class MX1508 : public DriveMotorInterface
{
    public:
        void init() override
        {
            motor.setMode(AUTO);
        }

        void run(int32_t value) override
        {
            // if (value > -50 && value < 50)
            // {
            //     esc.writeMicroseconds(1472);
            // } else {
                #ifdef REVERSE_DRIVE_MOTOR
                motor.setSpeed(constrain(map(-value, -512, 512, -255, 255), -255, 255));
                #else
                motor.setSpeed(constrain(map(value, -512, 512, -255, 255), -255, 255));
                #endif
            // }
        }
    private:
        GMotor motor = GMotor(DRIVER2WIRE, IN_1_PIN, IN_2_PIN);
};
