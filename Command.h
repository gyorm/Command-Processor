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
        ~Command();

    private:
        char *CmdText;
        char *HelptStr;
        char *CommandText;
        char *DefaultParams;
        char *UserParams;

        LinkedList<char*> DefaultParamList;
        LinkedList<char*> UserParamList;
        
        void(*CmdFunction)();

};

#endif