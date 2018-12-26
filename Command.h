//
// Created by daniel on 16/12/18.
//

#ifndef PROJECT_COMMAND_H
#define PROJECT_COMMAND_H



#include <string>
#include "vector"
#include "mutex"
using namespace std;
static mutex globMutex;
class Command{
public:
    virtual void doCommand(vector<string>) = 0;
};

#endif //PROJECT_COMMAND_H
