#pragma once

#include <Arduino.h>
#include <DFRobotDFPlayerMini.h>
#include "SoundPlayerInterface.h"
#include "../../Config.h"

class DfPlayerMini : public SoundPlayerInterface
{
    private:
        void init();
        void playFile();
    private:
        DFRobotDFPlayerMini player;
        uint8_t volumeLevel = 15;
        uint16_t loopTimeout = 0;
        uint32_t loopTimer = 0;
};