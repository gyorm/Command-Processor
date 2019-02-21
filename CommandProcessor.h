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
        /**
         * Constructor: Creates CommandList,
         * Loops through the Commands table, Creates Command
         * objects, adds them to the list.
        */
        CommandProcessor();
        /**
         * Destructor: Clears the CommandList
        */
        ~CommandProcessor();
        /**
         * If there is incoming data on the Serial port, records it
         * as a command string. '\r' character indicates the end of
         * the command. The command string the would be sent to 
         * the Process() function to Process, and execute it if 
         * possible.
         */
        void Run();
        /**
         * Goes through the CommandList and prints all the details 
         * on the Serial port (used for debugging)
         */
        void ListCommands();
        /**
         * Processes a given CommandString, determining its command
         * type, if it has paremeters, if it has enough parameters,
         * if it is a valid command in the first place. Executes the
         * command if it can be executed.
        */
		bool Process(char *Command);
    private:
        /**
         * Determines if the command is the "HELP" string. Returns true
         * if it is.
        */
        bool isHelp(char *Command);
		/**
         * Takes a string and converts every character in it to an 
         * upper case letter.
        */
        bool upperCase(char *str);
        /**
         * Prints an error message to the Serial port.
        */
		void error();

        /**
         * Linked list containing all the Commands the processor can
         * handle.
        */
		LinkedList<Command> *CommandList;
        /**
         * Structure containing all the necessary information to build
         * a Command() object.
        */
        typedef struct ExtCmd{
            char *CommandText;
            void(*CmdFunction)();
            char *DefaultParameters;
            char *HelpText;
        };
        /**
         * Table containing all the Commands. Add own commands here,
         * after incrementing COMMAND_COUNT. Command functions must be
         * pre-declared in this header, and defined in CommandProcessor.cpp
        */
		struct ExtCmd Commands[COMMAND_COUNT]{
            {"HELP",		GeneralHelp,		nullptr,	    "\nHELP -> List all the commands with their respective parameters"},
            {"PORT",		Port,   	    	"12,1",		    "\nPORT=a,b -> Set Pin to high, or low - a: PIN number, b: Value"}
        };
        /**
         * Buffer string to record incoming commands on Serial port.
        */
        char incomingCommand[50];
        /**
         * Reading Serial port by characters, the position must be recorded
         * in order to record the incoming characters in the proper order.
        */
        int incomingCmdPos;
};

#endif