#include "Movement.h"

void Movement::init(GamepadController* controller, DriveMotorInterface* driveMotor)
{
    readConfigFromEeprom();
    calculateLimits();
    Movement::controller = controller;
    driveMotor->init();

    steeringServo.attach(SERVO_PIN);
    steeringServo.write(centerAngle);
}

void Movement::run(DriveMotorInterface* driveMotor)
{
    Movement::driveMotor = driveMotor;
    handleButtons();
    moveServo(controller->getRightX());
    driveMotor->run(controller->getLeftY());
}

void Movement::moveServo(int32_t value)
{
    #ifdef REVERSE_SERVO
        value = -value;
    #endif

    if (value > -STICK_DEADZONE && value < STICK_DEADZONE)
    {
        steeringServo.write(centerAngle);
    } else if (value < -STICK_DEADZONE)
    {
        steeringServo.write(constrain(map(value, -512, 0, minAngle, centerAngle), MIN_SERVO_ANGLE, centerAngle));
        
    }  else if (value > STICK_DEADZONE)
    {
        steeringServo.write(constrain(map(value, 0, 512, centerAngle, maxAngle), centerAngle, MAX_SERVO_ANGLE));
    }
}

void Movement::handleButtons()
{
    if (centerAngle > MIN_SERVO_ANGLE  && controller->r1ButtonHold() && controller->dPadRightClick())
    {
        centerAngle--;
        calculateLimits();
    }

    if (centerAngle < MAX_SERVO_ANGLE && controller->r1ButtonHold() && controller->dPadLeftClick())
    {
        centerAngle++;
        calculateLimits();
    }

    if (controller->r1ButtonHold() && controller->dPadUpClick())
    {
        saveConfigToEeprom();
    }
}

void Movement::readConfigFromEeprom()
{
    EEPROM.begin(256);

    if (EEPROM.read(INIT_ADDRESS) != 'w') {
        movementConfig initConfig;
        config = initConfig;

        EEPROM.put(CONFIG_ADDRESS, config);
        EEPROM.write(INIT_ADDRESS, 'w');
        EEPROM.commit();
    } else {
        EEPROM.get(CONFIG_ADDRESS, config);
    }

    centerAngle = config.centerAngle;
}

void Movement::saveConfigToEeprom()
{
    config.centerAngle = centerAngle;
    EEPROM.put(CONFIG_ADDRESS, config);
    EEPROM.commit();
}

void Movement::calculateLimits()
{
    minAngle = constrain(centerAngle - SERVO_ANGLE_LIMIT, MIN_SERVO_ANGLE, centerAngle);
    maxAngle = constrain(centerAngle + SERVO_ANGLE_LIMIT, centerAngle, MAX_SERVO_ANGLE);
}