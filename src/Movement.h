#pragma once

#include <Arduino.h>
#include "Ps4Controller.h"
#include <ESP32_Servo.h>
#include "DriveMotors/DriveMotorInterface.h"
#include "DriveMotors/Esc.h"
#include "../Config.h"

class Movement
{
    public:
        void init(Ps4Controller* controller);
        void run(DriveMotorInterface* driveMotor);
    private:
        Ps4Controller* controller;
        Servo steeringServo;
        void moveServo(int32_t value);
};
