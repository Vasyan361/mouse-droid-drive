#include "Ps4Controller.h"

void Ps4Controller::setGamepadProperties(GamepadPtr gamepadProperties)
{
    Ps4Controller::gamepadProperties = gamepadProperties;
}


void Ps4Controller::update()
{
  if (gamepadProperties && gamepadProperties->isConnected()) {
      // Serial.printf(
      //     "idx=%d, dpad: 0x%02x, buttons: 0x%04x, axis L: %4d, %4d, axis R: "
      //     "%4d, %4d, brake: %4d, throttle: %4d, misc: 0x%02x, gyro x:%6d y:%6d "
      //     "z:%6d, accel x:%6d y:%6d z:%6d\n",
      //     0,                        // Gamepad Index
      //     gamepadProperties->dpad(),        // DPAD
      //     gamepadProperties->buttons(),     // bitmask of pressed buttons
      //     gamepadProperties->axisX(),       // (-511 - 512) left X Axis
      //     gamepadProperties->axisY(),       // (-511 - 512) left Y axis
      //     gamepadProperties->axisRX(),      // (-511 - 512) right X axis
      //     gamepadProperties->axisRY(),      // (-511 - 512) right Y axis
      //     gamepadProperties->brake(),       // (0 - 1023): brake button
      //     gamepadProperties->throttle(),    // (0 - 1023): throttle (AKA gas) button
      //     gamepadProperties->miscButtons(), // bitmak of pressed "misc" buttons
      //     gamepadProperties->gyroX(),       // Gyro X
      //     gamepadProperties->gyroY(),       // Gyro Y
      //     gamepadProperties->gyroZ(),       // Gyro Z
      //     gamepadProperties->accelX(),      // Accelerometer X
      //     gamepadProperties->accelY(),      // Accelerometer Y
      //     gamepadProperties->accelZ()       // Accelerometer Z
      // );
    }
}