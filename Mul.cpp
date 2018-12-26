//
// Created by lidor1atias on 12/20/18.
//

#include "Mul.h"
Mul::Mul(Expression* newLeftExp, Expression* newRightExp):BinaryExpression(newLeftExp, newRightExp){
}

double Mul::calculate(){
    return leftExp->calculate() * rightExp->calculate();
}