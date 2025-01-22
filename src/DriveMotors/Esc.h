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
            esc.writeMicroseconds(CENTER_ESC_MICROSECONDS);
        }

        void run(int32_t value) override
        {
            #ifdef REVERSE_DRIVE_MOTOR
                value = -value;
            #endif

            if (value > -STICK_DEADZONE && value < STICK_DEADZONE)
            {
                esc.writeMicroseconds(CENTER_ESC_MICROSECONDS);
            } else if(value < 0) {
                esc.writeMicroseconds(constrain(map(value, -512, 0, MIN_ESC_MICROSECONDS, CENTER_ESC_MICROSECONDS), MIN_ESC_MICROSECONDS, CENTER_ESC_MICROSECONDS));
            } else {
                esc.writeMicroseconds(constrain(map(value, 0, 512, CENTER_ESC_MICROSECONDS, MAX_ESC_MICROSECONDS), CENTER_ESC_MICROSECONDS, MAX_ESC_MICROSECONDS));
            }
        }
    private:
        Servo esc;
};
