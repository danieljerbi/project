//
// Created by lidor1atias on 12/22/18.
//

#ifndef FLIGHT_SIMULATOR_PROJECT_EXPRESSIONPARSER_H
#define FLIGHT_SIMULATOR_PROJECT_EXPRESSIONPARSER_H

#include <string>
#include "Expression.h"

using namespace std;

class ExpressionParser{
public:
    ExpressionParser();

    string preProcess(string str);

    bool isOperator(char c);

    bool isOperatorGreaterOrEqual(string op1, string op2);

    string shunting_yard(string exp);

    double calculateFirstNum(const string& exp, unsigned long &index);

    Expression* createExpression(char type, Expression *left, Expression *right);

    Expression* postToExp(const string& exp);

    bool inputCheck(const string& str);

    bool isInt(string);
    bool isDouble(string);
};
#endif //FLIGHT_SIMULATOR_PROJECT_EXPRESSIONPARSER_H