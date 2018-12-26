//
// Created by daniel on 20/12/18.
//

#ifndef PROJECT_PRINTCOMMAND_H
#define PROJECT_PRINTCOMMAND_H

#include "Command.h"
#include "Maps.h"

class PrintCommand : public Command{
public:
    PrintCommand();
    virtual void doCommand(vector<string>);};


#endif //PROJECT_PRINTCOMMAND_H
