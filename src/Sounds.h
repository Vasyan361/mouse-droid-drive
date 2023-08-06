#pragma once

#include <Arduino.h>
#include <DFRobotDFPlayerMini.h>
#include "Ps4Controller.h"

class Sounds
{
    public:
        void init(Ps4Controller* controller);
        void handle();
        void loop();
    private:
        DFRobotDFPlayerMini player;
        Ps4Controller* controller;
        uint8_t volumeLevel = 15;
        void volume();
        void playSound();
};
