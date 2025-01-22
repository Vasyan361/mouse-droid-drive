#pragma once

#include <Arduino.h>
#include "DriveMotorInterface.h"
#include <Servo.h>
#include "../../Config.h"

class SmoothEsc : public DriveMotorInterface
{
    public:
        void init() override
        { 
            esc.attach(ESC_PIN);
            esc.writeMicroseconds(CENTER_ESC_MICROSECONDS);
        }

        void run(int32_t value) override
        {
            value = calculateValue(value);
            #ifdef REVERSE_DRIVE_MOTOR
                value = -value;
            #endif

            if (value > -STICK_DEADZONE && value < STICK_DEADZONE) {
                esc.writeMicroseconds(CENTER_ESC_MICROSECONDS);
            } else if(value < 0) {
                esc.writeMicroseconds(constrain(map(value, -512, 0, MIN_ESC_MICROSECONDS, 1380), MIN_ESC_MICROSECONDS, 1400));
            } else {
                esc.writeMicroseconds(constrain(map(value, 0, 512, 1600, MAX_ESC_MICROSECONDS), 1650, MAX_ESC_MICROSECONDS));
            }
        }
    private:
        Servo esc;
        u_int32_t timer = 0;
        int32_t currentValue = 0;
        int32_t calculateValue(int32_t value) {
            if (millis() - timer > 20)
            {
                timer = millis();

                if (value > -STICK_DEADZONE && value < STICK_DEADZONE) {
                    currentValue = 0;
                } else if (abs(currentValue - value) < 4) {
                    currentValue = value;
                } else if (value < 0) {
                    currentValue-=4;
                } else {
                    currentValue+=4;
                }
            }
            
            return currentValue;
        }
};
