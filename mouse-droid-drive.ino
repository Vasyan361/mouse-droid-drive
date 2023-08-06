#pragma once

#include <Arduino.h>
#include "Config.h"
#include <Bluepad32.h>
#include "src/Ps4Controller.h"
#include "src/Sounds.h"
#include "src/Movement.h"
#include "src/DriveMotors/Esc.h"

GamepadPtr myGamepads[1];
Ps4Controller controller;
Sounds sounds;
Movement movement;

#ifdef ESC_DRIVE
Esc esc;
#endif

uint32_t timer;

void setup()
{
    Serial.begin(115200);
    sounds.init(&controller);
    movement.init(&controller);
    BP32.setup(&onConnectedGamepad, &onDisconnectedGamepad);
}

void loop()
{
    if (millis() - timer > 20) {
        timer = millis();

        BP32.update();

        controller.setGamepadProperties(myGamepads[0]);
        controller.update();

        #ifndef LOOP_MUSIC
        sounds.playSound();
        #endif
        sounds.volume();
    }
}

void onConnectedGamepad(GamepadPtr gp) {
    if (myGamepads[0] == nullptr) {
        GamepadProperties properties = gp->getProperties();
        myGamepads[0] = gp;

        #ifdef LOOP_MUSIC
        sounds.loop();
        #endif

        #ifdef ESC_DRIVE
        movement.run(&esc);
        #endif
    }
}

void onDisconnectedGamepad(GamepadPtr gp) {
    if (myGamepads[0] == gp) {
        myGamepads[0] = nullptr;
    }
}