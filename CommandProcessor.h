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

typedef class CommandProcessor;

//Declare Command functions here:

void GeneralHelp(CommandProcessor *cmdp);
void Port(int pin, int pinVal);

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
         * type, if it has paremeters, if it is a valid command in the 
         * first place. Executes the command if it can be executed.
        */
        bool Process(char *Command);
    private:
        /**
         * Searches for an '=' character in the cmdString. If it contains
         * '=' character, it means it has some parameters. Then it returns
         * true, else it returns false.
        */
        bool hasParams(char *cmdString);
        /**
         * Splits The command name, from the command parameters. They are
         * separated by an '=' character.
        */
        void splitCmdString(char *cmdString);
        /**
         * Loops through the Commandlist, and finds the command named 
         * int the parameter cmdName. returns the Command object if 
         * it exists, nullptr if it doesn't.
        */
        Command *getCommandByName(char *cmdName);
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

        //::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

        //:::::::::::::::::::::::::::Variables::::::::::::::::::::::::::::

        //::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

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
         * Commands should allways be UPPERCASE!
        */
		struct ExtCmd Commands[COMMAND_COUNT]{
            {"HELP",		nullptr,		nullptr,	    "\nHELP -> List all the commands with their respective parameters"},
            {"PORT",		Port(),   	    	"12,1",		    "\nPORT=a,b -> Set Pin to high, or low - a: PIN number, b: Value"}
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
        /**
         * String containing the command text.
        */
        char cmdText[20];
        /**
         * String containing command parameters, can be passed down for processing
         * to Command().
        */
        char cmdParams[10];
};

#endif