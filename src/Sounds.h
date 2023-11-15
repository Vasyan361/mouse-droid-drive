#pragma once

#include <Arduino.h>
#include <DFRobotDFPlayerMini.h>
#include "GamepadController.h"
#include "../Config.h"

class Sounds
{
    public:
        void init(GamepadController* controller);
        void loop();
        void volume();
        void playSound();
    private:
        DFRobotDFPlayerMini player;
        GamepadController* controller;
        uint8_t volumeLevel = 15;
        uint16_t loopTimeout = 0;
        uint32_t loopTimer = 0;
};
