#pragma once

#include <Arduino.h>
#include <DFRobotDFPlayerMini.h>
#include "Ps4Controller.h"

class Sounds
{
    public:
        void init(Ps4Controller* controller);
        void volume();
        void playSound();
        void loop();
    private:
        DFRobotDFPlayerMini player;
        Ps4Controller* controller;
};
