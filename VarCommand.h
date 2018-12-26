//
// Created by daniel on 20/12/18.
//

#ifndef PROJECT_VARCOMMAND_H
#define PROJECT_VARCOMMAND_H

#include "Command.h"
#include "Maps.h"
class VarCommand : public Command{
public:
    VarCommand();
    virtual void doCommand(vector<string>);
};


#endif //PROJECT_VARCOMMAND_H
