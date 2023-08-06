#pragma once

class DriveMotorInterface
{
    public:
        void virtual init() = 0;
        void virtual run(int32_t value) = 0;
};