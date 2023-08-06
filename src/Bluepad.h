#include <Bluepad32.h>
#include "Ps4Controller.h"

GamepadPtr myGamepads[1];

Ps4Controller controller;

uint32_t timer;

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

void bluepadInit() {
  BP32.setup(&onConnectedGamepad, &onDisconnectedGamepad);
}

void bluepadUpdate() {
    if (millis() - timer > 20) {
        timer = millis();

        BP32.update();

        controller.setGamepadProperties(myGamepads[0]);
        controller.update();
    }
    
}
