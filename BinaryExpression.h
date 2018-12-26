//
// Created by lidor1atias on 12/20/18.
//

#ifndef FLIGHT_SIMULATOR_PROJECT_BINARYEXPRESSION_H
#define FLIGHT_SIMULATOR_PROJECT_BINARYEXPRESSION_H

#include "Expression.h"

class BinaryExpression : public Expression{
protected:
    Expression* leftExp;
    Expression* rightExp;
public:
    BinaryExpression(Expression* newLeftExp, Expression* newRightExp);
    virtual double calculate() = 0;
};
#endif //FLIGHT_SIMULATOR_PROJECT_BINARYEXPRESSION_H