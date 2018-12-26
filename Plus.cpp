//
// Created by lidor1atias on 12/20/18.
//

#include "Plus.h"
Plus::Plus(Expression* newLeftExp, Expression* newRightExp):BinaryExpression(newLeftExp, newRightExp){
}

double Plus::calculate(){
    return leftExp->calculate() + rightExp->calculate();
}