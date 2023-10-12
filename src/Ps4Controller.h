#pragma once

#include <Arduino.h>
#include <Bluepad32.h>

#define D_PAD_COUNT 4
#define BUTTONS_COUNT 8

class Ps4Controller
{
    public:
        void setGamepadProperties(GamepadPtr gamepadProperties);
        void update();

        bool dPadUpClick();
        bool dPadDownClick();
        bool dPadLeftClick();
        bool dPadRightClick();
        bool croossButtonClick();
        bool squareButtonClick();
        bool triangleButtonClick();
        bool circleButtonClick();
        bool l1ButtonClick();
        bool l3ButtonClick();
        bool r1ButtonClick();
        bool r3ButtonClick();

        bool dPadUpHold();
        bool dPadDownHold();
        bool dPadLeftHold();
        bool dPadRightHold();
        bool croossButtonHold();
        bool squareButtonHold();
        bool triangleButtonHold();
        bool circleButtonHold();
        bool l1ButtonHold();
        bool l3ButtonHold();
        bool r1ButtonHold();
        bool r3ButtonHold();

        int32_t getLeftX();
        int32_t getLeftY();
        int32_t getRightX();
        int32_t getRightY();

        void blinkGreen();
    private:
        GamepadPtr gamepadProperties;

        enum {D_PAD, BUTTONS} buttonTypes;
        enum {D_PAD_UP, D_PAD_DOWN, D_PAD_LEFT, D_PAD_RIGHT} dPadMap;
        enum {CROSS, SQUARE, TRIANGLE, CIRCLE, L1, L3, R1, R3} buttonsMap;

        uint16_t buttonCodes[2][8] = {
            {
                0x01, // d-pad up
                0x02, // d-pad down
                0x08, // d-pad left
                0x04  // d-pad right
            },
            {
                0x0001, // cross
                0x0004, // square
                0x0008, // triangle
                0x0002, // circle
                0x0010, // L1
                0x0100, // L3
                0x0020, // R1
                0x0200  // R3
            }
        };
        bool buttonFlags[2][8] = {
            {
                false, // d-pad up
                false, // d-pad down
                false, // d-pad left
                false  // d-pad right
            },
            {
                false, // cross
                false, // square
                false, // triangle
                false, // circle
                false, // L1
                false, // L3
                false, // R1
                false  // R3
            },
        };
        bool buttonClics[2][8] = {
            {
                false, // d-pad up
                false, // d-pad down
                false, // d-pad left
                false  // d-pad right
            },
            {
                false, // cross
                false, // square
                false, // triangle
                false, // circle
                false, // L1
                false, // L3
                false, // R1
                false  // R3
            },
        };
        bool buttonHoldFlags[2][8] = {
            {
                false, // d-pad up
                false, // d-pad down
                false, // d-pad left
                false  // d-pad right
            },
            {
                false, // cross
                false, // square
                false, // triangle
                false, // circle
                false, // L1
                false, // L3
                false, // R1
                false  // R3
            },
        };
        uint32_t buttonsHoldTimeout[2][8] = {
            {
                0, // d-pad up
                0, // d-pad down
                0, // d-pad left
                0  // d-pad right
            },
            {
                0, // cross
                0, // square
                0, // triangle
                0, // circle
                0, // L1
                0, // L3
                0, // R1
                0  // R3
            },
        };
        bool buttonHolds[2][8] = {
            {
                false, // d-pad up
                false, // d-pad down
                false, // d-pad left
                false,  // d-pad right
                false,
                false,
                false,
                false
            },
            {
                false, // cross
                false, // square
                false, // triangle
                false, // circle
                false, // L1
                false, // L3
                false, // R1
                false  // R3
            },
        };
        void tick(uint8_t buttonType);
        void setRedColorLed();
        void setGreenColorLed();
        void setBlueColorLed();
        void changeColorLedIfAnyButtonHold();
};

