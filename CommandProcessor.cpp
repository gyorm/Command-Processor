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
    int cmdCount = 1;
    Serial.print("\n\nCommand List:\n");
    while(currNode != nullptr){
        Serial.print("\ncmd");
        Serial.print(cmdCount, DEC);
        Serial.print(":");
        Serial.print(currNode->data.ToString());
        currNode = currNode->next;
        cmdCount++;
    }
}

bool upperCase(char *str){
	int i = 0;
	while(str[i] != '\0'){
		toupper(str[i]);
		i++;
	}
    return true;
}

bool isHelp(char *Command){
	if(strcmp(upperCase(Command), "HELP") == 0) return true;
	else return false;
}

bool CommandProcessor::Process(char *Command){
	if(isHelp(Command)){
		CommandList->Get(0)->Execute();
	}
}

void CommandProcessor::error(){

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
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

//::::::::::::::::::::::::::::::CmdFunctions::::::::::::::::::::::::::::::

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

void Port(){

}

void GeneralHelp(){

}