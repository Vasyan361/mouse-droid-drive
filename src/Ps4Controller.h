#pragma once

#include <Arduino.h>
#include <Bluepad32.h>

class Ps4Controller
{
    public:
        void setGamepadProperties(GamepadPtr gamepadProperties);
        void update();
    private:
        GamepadPtr gamepadProperties;
};

