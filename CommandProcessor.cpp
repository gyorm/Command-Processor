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
    }
    Node<Command> *currNode = CommandList->head;
    while(currNode != nullptr){
        //Serial.print(currNode->data.toString());
        currNode = currNode->next;
    }
}

bool CommandProcessor::AddCommand(Command command){
    CommandList->Add(command);
}