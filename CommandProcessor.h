#ifndef ARDUINO_h
    #define ARDUINO_h
    #include <Arduino.h>
#endif
#ifndef COMMAND_h
    #include "Command.h"
#endif
#ifndef COMMANDPROCESSOR_h
    #define COMMANDPROCESSOR_h

class CommandProcessor{
    public:
        CommandProcessor();
        ~CommandProcessor();
        void ListCommands();
        bool AddCommand(Command command);
    private:
        LinkedList<Command> *CommandList;
};

#endif