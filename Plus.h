//
// Created by lidor1atias on 12/20/18.
//

#ifndef FLIGHT_SIMULATOR_PROJECT_PLUS_H
#define FLIGHT_SIMULATOR_PROJECT_PLUS_H

#include "BinaryExpression.h"

class Plus : public BinaryExpression{
public:
    Plus(Expression* newLeftExp, Expression* newRightExp);

    double calculate();
};
#endif //FLIGHT_SIMULATOR_PROJECT_PLUS_H