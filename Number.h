//
// Created by lidor1atias on 12/20/18.
//

#ifndef FLIGHT_SIMULATOR_PROJECT_NUMBER_H
#define FLIGHT_SIMULATOR_PROJECT_NUMBER_H

#include "Expression.h"

class Number : public Expression{
private:
    double value;
public:
    Number(double newVal);

    double calculate();
};
#endif //FLIGHT_SIMULATOR_PROJECT_NUMBER_H