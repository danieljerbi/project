//
// Created by lidor1atias on 12/20/18.
//

#include "Div.h"
Div::Div(Expression* newLeftExp, Expression* newRightExp):BinaryExpression(newLeftExp, newRightExp){
}

double Div::calculate(){
    return leftExp->calculate() / rightExp->calculate();
}