#ifndef ARDUINO_h
    #define ARDUINO_h
    #include <Arduino.h>
#endif

#include "CommandProcessor.h"

Command cmd("CMD", "CMDHELP", "1,1");
Command cmd2("CMD2", "CMD2 Help", "0,2");

LinkedList<Command> *cmdList = new LinkedList<Command>();
Node<Command> *curr = new Node<Command>();

void setup(){
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);

    cmdList->Add(cmd);
    cmdList->Add(cmd2);

    curr = cmdList->head;
}

void loop(){
    Serial.print("\n\nObejct.ToString() --> ");
    Serial.print(curr->data.ToString());
    if(curr ->next == nullptr) curr = cmdList->head;
    else curr = curr->next;
    Blink();
}

void Blink(){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
}