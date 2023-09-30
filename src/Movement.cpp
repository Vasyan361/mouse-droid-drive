#include "Movement.h"

void Movement::init(Ps4Controller* controller, DriveMotorInterface* driveMotor)
{
    Movement::controller = controller;
    driveMotor->init();

    steeringServo.attach(SERVO_PIN);
    steeringServo.write(centerAngle);
}

void Movement::run(DriveMotorInterface* driveMotor)
{
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
        steeringServo.write(constrain(map(value, -512, 0, MIN_SERVO_ANGLE, centerAngle), MIN_SERVO_ANGLE, centerAngle));
        
    }  else if (value > STICK_DEADZONE)
    {
        steeringServo.write(constrain(map(value, 0, 512, centerAngle, MAX_SERVO_ANGLE), centerAngle, MAX_SERVO_ANGLE));
    }
}

void Movement::handleButtons()
{
    if (centerAngle > 0  && controller->l1ButtonHold() && controller->dPadRightClick())
    {
        centerAngle--;
    }

    if (centerAngle < 180 && controller->l1ButtonHold() && controller->dPadLeftClick())
    {
        centerAngle++;
    }
}

void Movement::readConfigFromEeprom()
{
}

void Movement::saveConfigToEeprom()
{
}