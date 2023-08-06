#pragma once

#include <Arduino.h>
#include <Bluepad32.h>
#include "src/Ps4Controller.h"
#include "src/Bluepad.h"
#include "src/Sounds.h"

GamepadPtr myGamepads[1];
Ps4Controller controller;
Sounds sounds;

uint32_t timer;

void setup()
{
    Serial.begin(115200);
    sounds.init(&controller);
    BP32.setup(&onConnectedGamepad, &onDisconnectedGamepad);
}

void loop()
{
    if (millis() - timer > 20) {
        timer = millis();

        BP32.update();

        controller.setGamepadProperties(myGamepads[0]);
        controller.update();

        sounds.handle();
    }
}

void onConnectedGamepad(GamepadPtr gp) {
    if (myGamepads[0] == nullptr) {
        GamepadProperties properties = gp->getProperties();
        myGamepads[0] = gp;
    }
}

void onDisconnectedGamepad(GamepadPtr gp) {
    if (myGamepads[0] == gp) {
        myGamepads[0] = nullptr;
    }
}