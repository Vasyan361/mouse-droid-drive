#include "DfPlayerMini.h"

void DfPlayerMini::init()
{
    Serial2.begin(9600);

    if (!player.begin(Serial2, true, false)) {
        #ifdef DEBUG
            Serial.println(F("Unable to begin:"));
            Serial.println(F("1.Please recheck the connection!"));
            Serial.println(F("2.Please insert the SD card!"));
        #endif
        
        while(true){
            delay(0);
        }
    }

    #ifdef DEBUG
        Serial.println(F("DFPlayer Mini online."));
    #endif
    
    player.setTimeOut(500);
    player.volume(volumeLevel);
    player.stop();
}

void DfPlayerMini::playFile()
{

}