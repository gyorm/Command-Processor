#include "Command.h"

Command::Command(){

}

Command::Command(char *cmdText, void (*funPtr)(), char *defParams, char *helpStr){
    strcpy(CommandText, cmdText);
    strcpy(HelpStr, helpStr);
    strcpy(DefaultParams, defParams);
    CmdFunction = funPtr;
    UserParams[0] = '\0';
}

Command::~Command(){
    
}

char *Command::GetName(){
    return CommandText;
}

char* Command::ToString(){
    return HelpStr;
}

void Command::Execute(){
	CmdFunction();
}