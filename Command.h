#ifndef ARDUINO_h
    #define ARDUINO_h
    #include <Arduino.h>
#endif
#ifndef LINKEDLIST_h
    #include "LinkedList.h"
#endif
#ifndef COMMAND_h
    #define COMMAND_h

class Command{
    public:
        Command();
        Command(char *cmdText, void (*funPtr)(), char *defParams, char *helpStr);
        ~Command();
        char *ToString();
        void Execute();
    private:
        char CommandText[30];
        char HelpStr[100];
        char DefaultParams[20];
        char UserParams[20];
        void (*CmdFunction)();

        // Így most működni látszik, ki kell bővíteni...
};

#endif