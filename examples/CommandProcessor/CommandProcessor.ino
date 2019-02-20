#ifndef ARDUINO_h
    #define ARDUINO_h
    #include <Arduino.h>
#endif

#include "CommandProcessor.h"

CommandProcessor cmdp;

void setup(){
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);

}

void loop(){
    cmdp.ListCommands();
    Blink();
}

void Blink(){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
}