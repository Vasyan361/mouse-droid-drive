#pragma once

#include <Arduino.h>
#include "Ps4Controller.h"
#include <Servo.h>
#include "DriveMotors/DriveMotorInterface.h"
#include "../Config.h"
#include <EEPROM.h>

#define INIT_ADDRESS 0
#define CONFIG_ADDRESS 1
#define MIN_SERVO_ANGLE 0
#define MAX_SERVO_ANGLE 180

struct movementConfig
{
    uint8_t centerAngle = 90;
};

class Movement
{
    public:
        void init(Ps4Controller* controller, DriveMotorInterface* driveMotor);
        void run(DriveMotorInterface* driveMotor);
    private:
        Ps4Controller* controller;
        Servo steeringServo;
        void moveServo(int32_t value);
        void handleButtons();
        void readConfigFromEeprom();
        void saveConfigToEeprom();
        void calculateLimits();
        uint8_t minAngle = 0;
        uint8_t centerAngle = 90;
        uint8_t maxAngle = 180;
        movementConfig config;
};
