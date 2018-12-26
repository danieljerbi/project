//
// Created by daniel on 16/12/18.
//

#include "ConnectCommand.h"
#include "Client.h"
#include "thread"

void openClient(vector<string> input){
    Client client = Client(input[0], stoi(input[1]));
    client.openClient();
}

ConnectCommand::ConnectCommand() {

}

void ConnectCommand::doCommand(vector<string> strings) {
    if(strings.size() != 2){
        throw "wrong amount of inputs";
    }
    char* convertTester2;
    strtol(strings[1].c_str(), &convertTester2, 10);
    if (*convertTester2) {
        throw "one or more of the arguments isn't a number";
    }
    else {
        thread client(openClient,strings);
        client.join();
    }
}
