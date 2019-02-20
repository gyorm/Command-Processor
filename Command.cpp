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

char* Command::ToString(){
    char CmdDesc[200];
    CmdDesc[0] = '\0';
    strcat(CmdDesc, "\nCommand Name: ");
    strcat(CmdDesc, CommandText);
    strcat(CmdDesc, "\nCommand Help: ");
    strcat(CmdDesc, HelpStr);
    strcat(CmdDesc, "\n");
    return CmdDesc;
}

void Command::Execute(){
	CmdFunction();
}