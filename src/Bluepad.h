#include <Bluepad32.h>
#include "Ps4Controller.h"

GamepadPtr myGamepads[1];

Ps4Controller controller;

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
    BP32.update();

    controller.setGamepadProperties(myGamepads[0]);
    controller.update();

    // The main loop must have some kind of "yield to lower priority task" event.
    // Otherwise the watchdog will get triggered.
    // If your main loop doesn't have one, just add a simple `vTaskDelay(1)`.
    // Detailed info here:
    // https://stackoverflow.com/questions/66278271/task-watchdog-got-triggered-the-tasks-did-not-reset-the-watchdog-in-time

    vTaskDelay(350);
    // delay(150);
}
