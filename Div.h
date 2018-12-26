//
// Created by lidor1atias on 12/20/18.
//

#ifndef FLIGHT_SIMULATOR_PROJECT_DIV_H
#define FLIGHT_SIMULATOR_PROJECT_DIV_H
#include "BinaryExpression.h"

class Div : public BinaryExpression{
public:
    Div(Expression* newLeftExp, Expression* newRightExp);

    double calculate();
};
#endif //FLIGHT_SIMULATOR_PROJECT_DIV_H