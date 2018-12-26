//
// Created by lidor1atias on 12/20/18.
//

#include "BinaryExpression.h"
#include "Expression.h"

BinaryExpression::BinaryExpression(Expression* newLeftExp, Expression* newRightExp){
    leftExp = newLeftExp;
    rightExp = newRightExp;
}