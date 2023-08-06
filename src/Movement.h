#pragma once

#include <Arduino.h>
#include "Ps4Controller.h"
#include <Servo.h>
#include "DriveMotors/DriveMotorInterface.h"
#include "../Config.h"

class Movement
{
    public:
        void init(Ps4Controller* controller, DriveMotorInterface* driveMotor);
        void run(DriveMotorInterface* driveMotor);
    private:
        Ps4Controller* controller;
        Servo steeringServo;
        void moveServo(int32_t value);
};
