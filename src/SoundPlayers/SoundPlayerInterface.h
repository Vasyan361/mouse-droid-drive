#pragma once

#include <Arduino.h>


class SoundPlayerInterface
{
    public:
        void virtual init() = 0;
        void virtual playFile() = 0;
};