#include "Ps4Controller.h"

void Ps4Controller::setGamepadProperties(GamepadPtr gamepadProperties)
{
    Ps4Controller::gamepadProperties = gamepadProperties;
}


void Ps4Controller::update()
{
    if (gamepadProperties && gamepadProperties->isConnected()) {
        tick(D_PAD);
        tick(BUTTONS);
    }
}

bool Ps4Controller::dPadUpClick()
{
    if (buttonClics[D_PAD][D_PAD_UP]) {
        buttonClics[D_PAD][D_PAD_UP] = false;

        return true;
    }
    
    return false;
}

bool Ps4Controller::dPadDownClick()
{
    if (buttonClics[D_PAD][D_PAD_DOWN]) {
        buttonClics[D_PAD][D_PAD_DOWN] = false;

        return true;
    }
    
    return false;
}

bool Ps4Controller::dPadLeftClick()
{
    if (buttonClics[D_PAD][D_PAD_LEFT]) {
        buttonClics[D_PAD][D_PAD_LEFT] = false;

        return true;
    }
    
    return false;
}

bool Ps4Controller::dPadRightClick()
{
    if (buttonClics[D_PAD][D_PAD_RIGHT]) {
        buttonClics[D_PAD][D_PAD_RIGHT] = false;

        return true;
    }
    
    return false;
}

bool Ps4Controller::croossButtonClick()
{
    if (buttonClics[BUTTONS][CROSS]) {
        buttonClics[BUTTONS][CROSS] = false;

        return true;
    }
    
    return false;
}

bool Ps4Controller::squareButtonClick()
{
    if (buttonClics[BUTTONS][SQUARE]) {
        buttonClics[BUTTONS][SQUARE] = false;

        return true;
    }
    
    return false;
}

bool Ps4Controller::triangleButtonClick()
{
    if (buttonClics[BUTTONS][TRIANGLE]) {
        buttonClics[BUTTONS][TRIANGLE] = false;

        return true;
    }
    
    return false;
}

bool Ps4Controller::circleButtonClick()
{
    if (buttonClics[BUTTONS][CIRCLE]) {
        buttonClics[BUTTONS][CIRCLE] = false;

        return true;
    }
    
    return false;
}

bool Ps4Controller::l1ButtonClick()
{
    if (buttonClics[BUTTONS][L1]) {
        buttonClics[BUTTONS][L1] = false;

        return true;
    }
    
    return false;
}

bool Ps4Controller::l3ButtonClick()
{
    if (buttonClics[BUTTONS][L3]) {
        buttonClics[BUTTONS][L3] = false;

        return true;
    }
    
    return false;
}

bool Ps4Controller::r1ButtonClick()
{
    if (buttonClics[BUTTONS][R1]) {
        buttonClics[BUTTONS][R1] = false;

        return true;
    }
    
    return false;
}

bool Ps4Controller::r3ButtonClick()
{
    if (buttonClics[BUTTONS][R3]) {
        buttonClics[BUTTONS][R3] = false;

        return true;
    }
    
    return false;
}

bool Ps4Controller::dPadUpHold()
{
    return buttonHolds[D_PAD][D_PAD_UP];
}

bool Ps4Controller::dPadDownHold()
{
    return buttonHolds[D_PAD][D_PAD_DOWN];
}

bool Ps4Controller::dPadLeftHold()
{
    return buttonHolds[D_PAD][D_PAD_LEFT];
}

bool Ps4Controller::dPadRightHold()
{
    return buttonHolds[D_PAD][D_PAD_RIGHT];
}

bool Ps4Controller::croossButtonHold()
{
    return buttonHolds[BUTTONS][CROSS];
}

bool Ps4Controller::squareButtonHold()
{
    return buttonHolds[BUTTONS][SQUARE];
}

bool Ps4Controller::triangleButtonHold()
{
    return buttonHolds[BUTTONS][TRIANGLE];
}

bool Ps4Controller::circleButtonHold()
{
    return buttonHolds[BUTTONS][CIRCLE];
}

bool Ps4Controller::l1ButtonHold()
{
    return buttonHolds[BUTTONS][L1];
}

bool Ps4Controller::l3ButtonHold()
{
    return buttonHolds[BUTTONS][L3];
}

bool Ps4Controller::r1ButtonHold()
{
    return buttonHolds[BUTTONS][R1];
}

bool Ps4Controller::r3ButtonHold()
{
    return buttonHolds[BUTTONS][R3];
}

int32_t Ps4Controller::getLeftX()
{
    if (gamepadProperties && gamepadProperties->isConnected())
    {
        return gamepadProperties->axisX();
    }
    
    return 0;
}

int32_t Ps4Controller::getLeftY()
{
    if (gamepadProperties && gamepadProperties->isConnected())
    {
        return gamepadProperties->axisY();
    }
    
    return 0;
}

int32_t Ps4Controller::getRightX()
{
    if (gamepadProperties && gamepadProperties->isConnected())
    {
        return gamepadProperties->axisRX();
    }
    
    return 0;
}

int32_t Ps4Controller::getRightY()
{
    if (gamepadProperties && gamepadProperties->isConnected())
    {
        return gamepadProperties->axisRY();
    }
    
    return 0;
}




void  Ps4Controller::tick(uint8_t buttonType)
{
    uint16_t receivedValue = buttonType == D_PAD ? gamepadProperties->dpad() : gamepadProperties->buttons();
    
    for (uint8_t i = 0; i < (sizeof(buttonCodes[buttonType]) / sizeof(buttonCodes[0][0])); i++) {
        if (receivedValue == buttonCodes[buttonType][i] && !buttonFlags[buttonType][i]) {
            buttonsHoldTimeout[buttonType][i] = millis();
            
            buttonFlags[buttonType][i] = true;
            buttonClics[buttonType][i] = true;
        }

        if (receivedValue != buttonCodes[buttonType][i] && buttonFlags[buttonType][i]) {
            buttonFlags[buttonType][i] = false;
            buttonClics[buttonType][i] = false;
            buttonHoldFlags[buttonType][i] = false;
            buttonHolds[buttonType][i] = false;
        }

        if (receivedValue == buttonCodes[buttonType][i] && !buttonHoldFlags[buttonType][i] && (millis() - buttonsHoldTimeout[buttonType][i] >= 500)) {
            buttonsHoldTimeout[buttonType][i] = millis();

            buttonHoldFlags[buttonType][i] = true;
            buttonHolds[buttonType][i] = true;
        }
    }
}