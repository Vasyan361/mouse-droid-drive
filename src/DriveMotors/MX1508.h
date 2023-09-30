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
            motor.setSpeed(0);
        }

        void run(int32_t value) override
        {
            #ifdef REVERSE_DRIVE_MOTOR
                value = -value;
            #endif
            
            if (value > -STICK_DEADZONE && value < STICK_DEADZONE)
            {
                motor.setSpeed(0);
            } else {
                motor.setSpeed(constrain(map(value, -512, 512, -255, 255), -255, 255));
            }
        }
    private:
        GMotor motor = GMotor(DRIVER2WIRE, IN_1_PIN, IN_2_PIN);
};
