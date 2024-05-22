#pragma once

#include <Arduino.h>
#include "Config.h"
#include "src/GamepadController.h"
#include "src/Sounds.h"
#include "src/Movement.h"

#ifdef ESC_DRIVE
#include "src/DriveMotors/Esc.h"
Esc esc;
#endif

#ifdef MX1508_DRIVE
#include "src/DriveMotors/MX1508.h"
MX1508 mx1508;
#endif


GamepadController controller;
Sounds sounds;
Movement movement;

void setup()
{
    Serial.begin(115200);
    controller.init();
    sounds.init(&controller);
    #ifdef ESC_DRIVE
        movement.init(&controller, &esc);
    #endif

    #ifdef MX1508_DRIVE
        movement.init(&controller, &mx1508);
    #endif
}

void loop()
{
    controller.update();

    #ifndef LOOP_MUSIC
        sounds.playSound();
    #endif

    #ifdef LOOP_MUSIC
        sounds.loop();
    #endif
    sounds.volume();

    #ifdef ESC_DRIVE
        movement.run(&esc);
    #endif

    #ifdef MX1508_DRIVE
        movement.run(&mx1508);
    #endif

    vTaskDelay(1);
}