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
            centerEscMicroseconds = MIN_ESC_MICROSECONDS + round((MAX_ESC_MICROSECONDS - MIN_ESC_MICROSECONDS) / 2);
            esc.attach(ESC_PIN);
            esc.writeMicroseconds(centerEscMicroseconds);
        }

        void run(int32_t value) override
        {
            #ifdef REVERSE_DRIVE_MOTOR
                value = -value;
            #endif


            if (value > -STICK_DEADZONE && value < STICK_DEADZONE)
            {
                esc.writeMicroseconds(centerEscMicroseconds);
            } else {
                esc.writeMicroseconds(constrain(map(value, -512, 512, MIN_ESC_MICROSECONDS, MAX_ESC_MICROSECONDS), MIN_ESC_MICROSECONDS, MAX_ESC_MICROSECONDS));
            }
        }
    private:
        Servo esc;
        uint16_t centerEscMicroseconds;
};
