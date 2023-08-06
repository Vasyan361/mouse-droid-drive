#include "Sounds.h"

void Sounds::init(Ps4Controller* controller)
{
    Sounds::controller = controller;
    Serial2.begin(9600);

    if (!player.begin(Serial2, true, false)) {
        // Serial.println(F("Unable to begin:"));
        // Serial.println(F("1.Please recheck the connection!"));
        // Serial.println(F("2.Please insert the SD card!"));
        while(true){
            delay(0);
        }
        Serial.println(F("DFPlayer Mini online."));
    
        player.setTimeOut(500);
        player.volume(volumeLevel);
    }
}

void Sounds::handle()
{
    playSound();
    volume();
}

void Sounds::loop()
{
    player.loop(16);
}

void Sounds::volume()
{
    if (volumeLevel < 30 && controller->l1ButtonHold() && controller->dPadUpClick())
    {
        volumeLevel++;
        player.volume(volumeLevel);
    }

    if (volumeLevel > 0 && controller->l1ButtonHold() && controller->dPadDownClick())
    {
        volumeLevel--;
        player.volume(volumeLevel);
    }
}

void Sounds::playSound()
{
    if (!controller->l1ButtonHold() && !controller->r1ButtonHold() && controller->dPadDownClick())
    {
        player.play(1);
    }

    if (!controller->l1ButtonHold() && !controller->r1ButtonHold() && controller->dPadLeftClick())
    {
        player.play(2);
    }

    if (!controller->l1ButtonHold() && !controller->r1ButtonHold() && controller->dPadUpClick())
    {
        player.play(3);
    }

    if (!controller->l1ButtonHold() && !controller->r1ButtonHold() && controller->dPadRightClick())
    {
        player.play(4);
    }

    if (controller->croossButtonClick())
    {
        player.play(5);
    }

    if (controller->squareButtonClick())
    {
        player.play(6);
    }

    if (controller->triangleButtonClick())
    {
        player.play(7);
    }

    if (controller->circleButtonClick())
    {
        player.play(8);
    }

    if (controller->l3ButtonClick())
    {
        player.play(9);
    }

    if (controller->r3ButtonClick())
    {
        player.play(10);
    }

    if (controller->l1ButtonHold() && controller->dPadLeftClick())
    {
        player.play(11);
    }

    if (controller->l1ButtonHold() && controller->dPadRightClick())
    {
        player.play(12);
    }

    if (controller->r1ButtonHold() && controller->dPadDownClick())
    {
        player.play(13);
    }

    if (controller->r1ButtonHold() && controller->dPadLeftClick())
    {
        player.play(14);
    }

    if (controller->r1ButtonHold() && controller->dPadUpClick())
    {
        player.play(15);
    }
}