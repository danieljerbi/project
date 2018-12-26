//
// Created by daniel on 17/12/18.
//

#include "DataReaderServer.h"
#include "GlobalNewSockfd.h"

#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>

#include <sys/socket.h>
#include "iostream"
#include "GlobalMutex.h"
#include "Command.h"
using namespace std;

DataReaderServer::DataReaderServer(int server_port, int server_rate) {
    port = server_port;
    rate = server_rate;
}

void DataReaderServer::createServer(){
    char buffer[400];
    int  n;
    /* If connection is established then start communicating */
    bzero(buffer,400);
    int i = 0;
    double val = 0;
    int k = 0;
    string values = "";
    string leftVal  = "";
    int start = 0;
    int j = 0;
    while (true) {
        sleep(1/rate);
        start = leftVal.length();
        n = read(GlobalNewSockfd::instance()->getSockServer(), buffer + start, 399 - start);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        k= 0;
        values = "";
        while(buffer[k] != '\n'){
            values += buffer[k];
            k++;
        }

        k++;
        leftVal = "";
        if (buffer[k] != '\0') {
            while (buffer[k] != '\0') {
                leftVal += buffer[k];
                k++;
            }
            bzero(buffer, 400);
            for (int i = 0; i < leftVal.length(); ++i) {
                buffer[i] = leftVal.at(i);
            }
        } else {
            bzero(buffer, 400);
        }


        i = 0;
        string curValue = "";
        curValue = "";
        j = 0;
        while (j < 23 && i < values.length()) {
            curValue = "";
            while (i < values.length() && values.at(i) != ',') {
                curValue = curValue + values.at(i);
                i++;
            }
            try {
                val = stod(curValue);
            } catch (exception e) {

            }
           // GlobalMutex::instance()->getMutex()->lock();
           globMutex.lock();
            Maps::instance()->updatePathValue(Maps::instance()->getPathByIndex(j), val);
            try {
                Maps::instance()->updateSymbolTable(
                        Maps::instance()->getVarByPath(Maps::instance()->getPathByIndex(j)), val);
            } catch (exception e) {

            }
            globMutex.unlock();

            //GlobalMutex::instance()->getMutex()->unlock();
           j++;
            i++;
        }
    }
}
