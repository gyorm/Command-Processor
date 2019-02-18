#ifndef ARDUINO_h
    #define ARDUINO_h
    #include <Arduino.h>
#endif

#include "CommandProcessor.h"

Command cmd("CMD", "CMDHELP", "1,1");
Command cmd2("CMD2", "CMD2 Help", "0,2");

CommandProcessor cmdp;

LinkedList<Command> *cmdList = new LinkedList<Command>();
Node<Command> *curr = new Node<Command>();

void setup(){
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);

    cmdp.AddCommand(cmd);
    cmdp.AddCommand(cmd2);
}

void loop(){
    Serial.print("\n\nCommand List:\n");
    cmdp.ListCommands();
    Blink();
}

void Blink(){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
}