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
        Command(char *cmdText, char *helpStr, char *defParams);
        ~Command();
        char *ToString();
    private:
        char CommandText[20];
        char HelpStr[100];
        char DefaultParams[20];
        char UserParams[20];

        // Így most működni látszik, ki kell bővíteni...
};

#endif