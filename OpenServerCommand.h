//
// Created by daniel on 16/12/18.
//

#ifndef PROJECT_OPENSERVERCOMMAND_H
#define PROJECT_OPENSERVERCOMMAND_H

#include "Command.h"
#include "vector"
#include "ExpressionParser.h"

class OpenServerCommand : public Command{
public:
    OpenServerCommand();
    virtual void doCommand(vector<string>);
};


#endif //PROJECT_OPENSERVERCOMMAND_H
