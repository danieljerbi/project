#include <iostream>
#include <thread>
#include "map"
#include "DataReaderServer.h"
#include "Client.h"
#include "Interpreter.h"
#include "chrono"
#include<iostream>
#include<fstream>
#include "GarbageVector.h"

#include <unistd.h>



using namespace std;

int main()
{
    Interpreter interpreter = Interpreter();
    string str;
    std::ifstream myfile("test.txt");
    try {
        if (myfile.is_open())
        {
            while (getline (myfile,str))
            {
                vector<string> strings = interpreter.lexer(str);
                if(str.substr(0 , str.find(' ')) != "while" && (str.substr(0 , str.find(' ')) != "if")) {
                    interpreter.parser(strings);
                }
                else if (strings.at(0) == "if" || strings.at(0) == "while") {
                    vector<string> whileIfcommands;
                    while(str != "}") {
                        whileIfcommands.push_back(str);
                        if((str.at(str.size() - 1) == '}')) {
                            break;
                        }
                        getline(myfile, str);
                    }
                    interpreter.parser(whileIfcommands);
                }
            }
            myfile.close();
        }
    }
    catch (exception exception1) {
        cout<<exception1.what();
    }
    close(GlobalNewSockfd::instance()->getSockClient());
    close(GlobalNewSockfd::instance()->getSockServer());
    GarbageVector::instance()->deleteAll();
    return 0;

}
