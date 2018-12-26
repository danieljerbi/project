//
// Created by daniel on 16/12/18.
//

#ifndef PROJECT_INTERPRETER_H
#define PROJECT_INTERPRETER_H

#include "OpenServerCommand.h"
#include "ConnectCommand.h"
#include "PrintCommand.h"
#include "VarCommand.h"
#include "SetCommand.h"
#include "IfWhileCommand.h"
#include "vector"
#include <map>
#include "Command.h"
#include "Expression.h"
#include "ExpressionParser.h"

using namespace std;
#include <map>
class Interpreter {
private:
    map <string,Command*> mapCommand;
    ExpressionParser* expressionParser;
public:
    Interpreter();
    vector< string> lexer(string);
    void parser(vector<string>);


};


#endif //PROJECT_INTERPRETER_H