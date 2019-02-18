#ifndef ARDUINO_h
    #define ARDUINO_h
    #include <Arduino.h>
#endif
#ifndef COMMAND_DB_h
    #define COMMAND_DB_h

void GeneralHelp();

typedef struct ExtCmd {
	char *CmdText;
	void (*CmdFunction)();
	char *DefParams;
	char *HelpStr;
};

struct ExtCmd cmdTable[]{
	//CmdText				CmdFunction				DefParams				HelpStr
	{"HELP",				GeneralHelp,			nullptr,				"\nHELP -> List all the commands with their respective parameters"},
};

void GeneralHelp(){
	for(ExtCmd cmd : cmdTable) {
		Serial.print(cmd.HelpStr);
	}
}

#endif