//
// Created by daniel on 20/12/18.
//

#include "IfWhileCommand.h"
#include "iostream"
#include "Interpreter.h"
#include "string.h"
#include "stdio.h"

IfWhileCommand::IfWhileCommand() {

}

bool twonum(string oper, double d1, double d2){
    if(oper == "==") {
        return d1 == d2;
    } else if (oper == "!=") {
        return d1 !=d2;
    } else if (oper == ">") {
        return d1 > d2;

    } else if (oper == "<") {
        return d1 < d2;

    } else if(oper == ">=") {
        return d1 >=  d2;

    } else if(oper == "<=") {
        return d1 <= d2;
    }
}

void IfWhileCommand::doCommand(vector<string> line) {
    if (line.at(0) == "if" || line.at(0) == "while") {
        double val1 = stod(line[1]);
        double val2 = stod(line[3]);
        EnterIfWhile::instance()->setEnter(twonum(line[2],val1,val2));
    }  else {
        if (EnterIfWhile::instance()->getEnter()) {
            if (strcmp(line.at(line.size() - 1).c_str(),"}") == 0) {
                line.pop_back();
            }
            Interpreter interpreter = Interpreter();
            interpreter.parser(line);
        }
    }
}