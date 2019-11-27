#ifndef ARDUINO_h
    #define ARDUINO_h
    #include <Arduino.h>
#endif

#include "CommandProcessor.h"

CommandProcessor cmdp;

void setup(){
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(28, OUTPUT);
    Serial.begin(115200);
    //Blink 5 Times:
    for(int i = 0; i < 5; i++)
        Blink();
    //Light up led:
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(28, HIGH);
    Serial.print("\nCommandProcessor started!\n");
}

void loop(){
    cmdp.Run();
}

void Blink(){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
}