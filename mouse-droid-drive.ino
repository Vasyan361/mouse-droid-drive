#pragma once

#include <Arduino.h>
#include "src/Bluepad.h"
// #include <Ps3Controller.h>
// #include <ESP32_Servo.h>
// #include <DFRobotDFPlayerMini.h>


// int battery = 0;
// Servo myservo;
// Servo esc;
// DFRobotDFPlayerMini myDFPlayer;

// void notify()
// {
//     int xValue = Ps3.data.analog.stick.lx;
//     int yValue = Ps3.data.analog.stick.ly;

//     if (xValue > -25 && xValue < 25)
//     {
//         myservo.write(90);
//     } else {
//         myservo.write(map(xValue, -128, 128, 0, 180));
//     }

//     if (yValue > -25 && yValue < 25)
//     {
//         esc.writeMicroseconds(1550);
//     } else {
//         esc.writeMicroseconds(map(yValue, -128, 128, 800, 2300));
//     }
    
//     //---------------- Analog stick value events ---------------
//    if( abs(Ps3.event.analog_changed.stick.lx) + abs(Ps3.event.analog_changed.stick.ly) > 2 ){
//        Serial.print("Moved the left stick:");
//        Serial.print(" x="); Serial.print(Ps3.data.analog.stick.lx, DEC);
//        Serial.print(" y="); Serial.print(Ps3.data.analog.stick.ly, DEC);
//        Serial.println();
       
//     }

//     if( Ps3.event.button_down.up ) {
//         myDFPlayer.playFolder(1, 1);
//         Serial.println("Started pressing the up button");
//     }

//     if( Ps3.event.button_down.down ) {
//         myDFPlayer.playFolder(1, 2);
//         Serial.println("Started pressing the up button");
//     }

//     if( Ps3.event.button_down.right ) {
//         myDFPlayer.playFolder(1, 3);
//         Serial.println("Started pressing the up button");
//     }
    
//    //---------------------- Battery events ---------------------
//     if( battery != Ps3.data.status.battery ){
//         battery = Ps3.data.status.battery;
//         Serial.print("The controller battery is ");
//         if( battery == ps3_status_battery_charging )      Serial.println("charging");
//         else if( battery == ps3_status_battery_full )     Serial.println("FULL");
//         else if( battery == ps3_status_battery_high )     Serial.println("HIGH");
//         else if( battery == ps3_status_battery_low)       Serial.println("LOW");
//         else if( battery == ps3_status_battery_dying )    Serial.println("DYING");
//         else if( battery == ps3_status_battery_shutdown ) Serial.println("SHUTDOWN");
//         else Serial.println("UNDEFINED");
//     }

// }

// void onConnect(){
//     Serial.println("Connected.");
//     myservo.write(90);
// }

void setup()
{
    Serial.begin(115200);
    bluepadInit();
    // Serial2.begin(9600);

    // Ps3.attach(notify);
    // Ps3.attachOnConnect(onConnect);
    // Ps3.begin("ec:62:60:9d:89:e2");

    // Serial.println("Ready.");
    // Serial.println(!Serial);
    // Serial.println(!Serial2);
    // Serial.println(!myDFPlayer.begin(Serial2));

    // myservo.attach(14);
    // esc.attach(12);
    // esc.writeMicroseconds(1550);


    // if (!myDFPlayer.begin(Serial2, true, false)) {  //Use softwareSerial to communicate with mp3.
    //     Serial.println(F("Unable to begin:"));
    //     Serial.println(F("1.Please recheck the connection!"));
    //     Serial.println(F("2.Please insert the SD card!"));
    //     while(true){
    //     delay(0); // Code to compatible with ESP8266 watch dog.
    //     }
    // }
    // Serial.println(F("DFPlayer Mini online."));


    
    // // myDFPlayer.setTimeOut(500);
    // myDFPlayer.volume(30);  //Set volume value. From 0 to 30
    // // myDFPlayer.playFolder(1, 1);
}

void loop()
{
    bluepadUpdate();
    // if(!Ps3.isConnected())
    //     return;

    // delay(2000);
    // for (int pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // // in steps of 1 degree
    //     myservo.write(pos);              // tell servo to go to position in variable 'pos'
    //     delay(15);                       // waits 15ms for the servo to reach the position
    // }
    // for (int pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    //     myservo.write(pos);              // tell servo to go to position in variable 'pos'
    //     delay(15);                       // waits 15ms for the servo to reach the position
    // }
}