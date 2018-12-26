//
// Created by daniel on 16/12/18.
//

#ifndef PROJECT_CONNECTCOMMAND_H
#define PROJECT_CONNECTCOMMAND_H

#include "Command.h"
#include "vector"
class ConnectCommand : public Command{
public:
    ConnectCommand();
    virtual  void doCommand(vector<string>);
};


#endif //PROJECT_CONNECTCOMMAND_H
