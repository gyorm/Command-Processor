#include "CommandProcessor.h"

CommandProcessor::CommandProcessor(){
    CommandList = new LinkedList<Command>();
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
    while(currNode != nullptr){
        Serial.print("\ncmd");
        Serial.print(cmdCount, DEC);
        Serial.print(":");
        Serial.print(currNode->data.ToString());
        currNode = currNode->next;
        cmdCount++;
    }
}

bool CommandProcessor::AddCommand(Command command){
    CommandList->Add(command);
}