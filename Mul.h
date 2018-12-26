//
// Created by lidor1atias on 12/20/18.
//

#ifndef FLIGHT_SIMULATOR_PROJECT_MUL_H
#define FLIGHT_SIMULATOR_PROJECT_MUL_H
#include "BinaryExpression.h"

class Mul : public BinaryExpression{
public:
    Mul(Expression* newLeftExp, Expression* newRightExp);

    double calculate();
};
#endif //FLIGHT_SIMULATOR_PROJECT_MUL_H