#ifndef ARDUINO_h
    #define ARDUINO_h
    #include <Arduino.h>
#endif
#ifndef COMMAND_h
    #include "Command.h"
#endif
#ifndef COMMANDPROCESSOR_h
    #define COMMANDPROCESSOR_h
	#define COMMAND_COUNT 2

void GeneralHelp();
void Port();

class CommandProcessor{
    public:
        CommandProcessor();
        ~CommandProcessor();
        void ListCommands();
		bool Process(char *Command);
    private:
        bool isHelp(char *Command);
		char *upperCase(char *str);
		
		LinkedList<Command> *CommandList;
        typedef struct ExtCmd{
            char *CommandText;
            void(*CmdFunction)();
            char *DefaultParameters;
            char *HelpText;
        };
		struct ExtCmd Commands[COMMAND_COUNT]{
            {"HELP",		GeneralHelp,		nullptr,	    "\nHELP -> List all the commands with their respective parameters"},
            {"PORT",		Port,   	    	"12,1",		"\nPORT=a,b -> Set Pin to high, or low - a: PIN number, b: Value"}
        };
};

#endif