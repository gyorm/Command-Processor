#include "CommandProcessor.h"

CommandProcessor::CommandProcessor(){
    CommandList = new LinkedList<Command>();
    incomingCmdPos = 0;
    for(int i = 0; i < COMMAND_COUNT; i++){
        Command newCmd(
            Commands[i].CommandText,
            Commands[i].CmdFunction,
        	Commands[i].DefaultParameters,
        	Commands[i].HelpText
        );
        CommandList->Add(newCmd);
    }
}

CommandProcessor::~CommandProcessor(){
    CommandList->Clear();
}

void CommandProcessor::ListCommands(){
    if(CommandList->head == nullptr){
        Serial.print("\n ERROR: CommandList is empty!");
        return;
    }
    Node<Command> *currNode = CommandList->head;
    Serial.print("\nAvailable Commands:\n");
    while(currNode != nullptr){
        Serial.print(currNode->data.ToString());
        currNode = currNode->next;
    }
}

void CommandProcessor::error(){
    Serial.print("\nERROR");
}

void CommandProcessor::Run(){
    if(Serial.available()){
        char buff = Serial.read();
        if(buff != '\r'){
            incomingCommand[incomingCmdPos] = buff;
            incomingCmdPos++;
        }
        else
        {
            incomingCommand[incomingCmdPos] = '\0';
            incomingCmdPos = 0;
            if(!Process(incomingCommand)) error();
            memset(incomingCommand, 0, 50);
        }
    }
}

bool CommandProcessor::Process(char *CmdString){
    upperCase(CmdString);
    if(hasParams(CmdString)){
        //split the command text from command params...
    }
    else
        strcpy(cmdText, CmdString);
    
	Command *cmd = getCommandByName(cmdText);
	if(cmd != nullptr)
	{
        if(isHelp(cmdText)){
            GeneralHelp(this);
            return true;
        }
        else{
            cmd->Execute();
    	    return true;
        }
	}
    return false;
}

Command *CommandProcessor::getCommandByName(char *cmdName){
	Node<Command> *currNode = CommandList->head;
	while(currNode != nullptr){
		if(strcmp(currNode->data.GetName(), cmdName) == 0)
			return &currNode->data;
		else currNode = currNode->next;
	}
	Serial.print("\ngetCommandByName(): failed");
	return nullptr;
}

bool CommandProcessor::hasParams(char *cmdString){
    int i = 0;
    while(cmdString[i] != '\0'){
        if(cmdString[i] == '=') return true;
        i++;
    }
    return false;
}

bool CommandProcessor::upperCase(char *str){
    int i = 0;
	while(str[i] != '\0'){
		char c = toupper(str[i]);
		str[i] = c;
		i++;
	}
    return true;
}

bool CommandProcessor::isHelp(char *Command){
    upperCase(Command);
	if(strcmp(Command, "HELP") == 0) return true;
	else return false;
}

void CommandProcessor::splitCmdString(char *cmdString){
    int i = 0;
    while(cmdString[i] != '\0'){
        
    }
    
}
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

//:::::::::::::::::::::::Definition of CmdFunctions:::::::::::::::::::::::

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

void Port(int pin, int pinVal){
    
    pinVal >= 1 ? pinVal = 1 : pinVal = 0;
    pinVal <= 0 ? pinVal = 0 : pinVal = 1;

    pinMode(pin, OUTPUT);
    digitalWrite(pin, pinVal);
}

void GeneralHelp(CommandProcessor *cmdp){
	cmdp->ListCommands();
}