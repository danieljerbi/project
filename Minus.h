//
// Created by lidor1atias on 12/20/18.
//

#ifndef FLIGHT_SIMULATOR_PROJECT_MINUS_H
#define FLIGHT_SIMULATOR_PROJECT_MINUS_H

#include "BinaryExpression.h"

class Minus : public BinaryExpression{
public:
    Minus(Expression* newLeftExp, Expression* newRightExp);

    double calculate();
};
#endif //FLIGHT_SIMULATOR_PROJECT_MINUS_H