//
// Created by daniel on 20/12/18.
//

#include "SetCommand.h"
#include "GlobalNewSockfd.h"
#include "iostream"

#include "DataReaderServer.h"
#include "GlobalNewSockfd.h"

#include <string.h>
#include <unistd.h>
#include "GlobalMutex.h"

SetCommand::SetCommand() {

}
void SetCommand::doCommand(vector<string> strings) {
   // GlobalMutex::instance()->getMutex()->lock();
    globMutex.lock();

    Maps::instance()->updateSymbolTable(strings[0], stod(strings[1]));

    string path = Maps::instance()->getPathByVar(strings[0]);
    if (path != "") {
        string setVar = "set " + path + " " + strings[1];
        char buf[400];
        strcpy(buf, setVar.c_str());
        int i = 0;
        while (buf[i] != '\0') {
            i++;
        }
        buf[i] = '\r';
        i++;
        buf[i] = '\n';
        i++;
        buf[i] = '\0';
// Send message to the server

        int n = write(GlobalNewSockfd::instance()->getSockClient(), buf, strlen(buf));
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
    }
    //GlobalMutex::instance()->getMutex()->unlock();
    globMutex.unlock();

}
