//
// Created by daniel on 20/12/18.
//

#ifndef PROJECT_SETCOMMAND_H
#define PROJECT_SETCOMMAND_H

#include "Command.h"
#include "Maps.h"
class SetCommand : public Command{
public:
    SetCommand();
    virtual void doCommand(vector<string>);
};


#endif //PROJECT_SETCOMMAND_H
