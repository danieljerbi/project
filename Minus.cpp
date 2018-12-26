//
// Created by lidor1atias on 12/20/18.
//

#include "Minus.h"
Minus::Minus(Expression* newLeftExp, Expression* newRightExp):BinaryExpression(newLeftExp, newRightExp){
}

double Minus::calculate(){
    return leftExp->calculate() - rightExp->calculate();
}