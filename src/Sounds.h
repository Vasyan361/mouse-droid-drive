#pragma once

#include <Arduino.h>
#include <DFRobotDFPlayerMini.h>
#include "Ps4Controller.h"
#include "../Config.h"

class Sounds
{
    public:
        void init(Ps4Controller* controller);
        void loop();
        void volume();
        void playSound();
    private:
        DFRobotDFPlayerMini player;
        Ps4Controller* controller;
        uint8_t volumeLevel = 15;
        uint32_t loopTimer = 0;
};
