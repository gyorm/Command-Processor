#include "CommandProcessor.h"

CommandProcessor::CommandProcessor(){
    CommandList = new LinkedList<Command>();
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

char *upperCase(char *str){
	int i = 0;
	while(str[i] != '\0'){
		toupper(str[i]);
		i++;
	}
	
}

bool isHelp(char *Command){
	if(strcmp(upperCase(Command), "HELP") == 0) return true;
	else return false;
}

bool CommandProcessor::Process(char *Command){
	if(isHelp(Command)){
		CommandList->Get(0)->data.Execute(); //->Get(0).Execute() lenne jó --> LinkedList.h
	}
}
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

//::::::::::::::::::::::::::::::CmdFunctions::::::::::::::::::::::::::::::

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

void Port(){

}

void GeneralHelp(){

}