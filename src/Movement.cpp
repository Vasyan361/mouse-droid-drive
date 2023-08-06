#include "Movement.h"

void Movement::init(Ps4Controller* controller)
{
    Movement::controller = controller;

    steeringServo.attach(SERVO_PIN);
    steeringServo.write(90);
}

void Movement::run(DriveMotorInterface* driveMotor)
{
}

void Movement::moveServo(int32_t value)
{
    if (value > -25 && value < 25)
    {
        steeringServo.write(90);
    } else {
        steeringServo.write(map(value, -128, 128, 0, 180));
    }
}