#include "Movement.h"

void Movement::init(Ps4Controller* controller, DriveMotorInterface* driveMotor)
{
    Movement::controller = controller;
    driveMotor->init();

    steeringServo.attach(SERVO_PIN);
    steeringServo.write(90);
}

void Movement::run(DriveMotorInterface* driveMotor)
{
    moveServo(controller->getRightX());
    driveMotor->run(controller->getLeftY());
}

void Movement::moveServo(int32_t value)
{
    if (value > -50 && value < 50)
    {
        steeringServo.write(90);
    } else {
        #ifdef REVERSE_SERVO
        steeringServo.write(constrain(map(value, -512, 512, 180, 0), 180, 0));
        #else
        steeringServo.write(constrain(map(value, -512, 512, 0, 180), 0, 180));
        #endif
    }
}