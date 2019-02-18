#include "Command.h"

Command::Command(){

}

Command::Command(char *cmdText, char *helpStr, char *defParams){
    strcpy(CommandText, cmdText);
    strcpy(HelpStr, helpStr);
    strcpy(DefaultParams, defParams);
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

    return CmdDesc;
}