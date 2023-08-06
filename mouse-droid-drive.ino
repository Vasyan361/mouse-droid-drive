#pragma once

#include <Arduino.h>
#include "src/Bluepad.h"
#include "src/Sounds.h"
// #include <ESP32_Servo.h>

Sounds sounds;

// Servo myservo;
// Servo esc;

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

void setup()
{
    Serial.begin(115200);
    bluepadInit();
    sounds.init(&controller);

    // myservo.attach(14);
    // esc.attach(12);
    // esc.writeMicroseconds(1550);
}

void loop()
{
    bluepadUpdate();
    sounds.handle();
    
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