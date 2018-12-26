//
// Created by lidor1atias on 12/22/18.
//

#include <stack>
#include <tuple>
#include <queue>
#include "ExpressionParser.h"
#include "Number.h"
#include "Div.h"
#include "Mul.h"
#include "Plus.h"
#include "Minus.h"
#include "Maps.h"
#include "GarbageVector.h"

ExpressionParser::ExpressionParser() {

}
string ExpressionParser::preProcess(string str){
    string returnStr = "";
    int i;
    //remove spaces
    for(i = 0; i < str.length(); i++){
        if(str.at(i) != ' '){
            returnStr += str.at(i);
        }
    }

    //trade variable names with their values
    string curVal = "";
    for(i = returnStr.find("=") + 1; i < returnStr.length(); i++){
        if(!isdigit(returnStr.at(i)) && !isOperator(returnStr.at(i)) && returnStr.at(i) != '(' && returnStr.at(i) != ')'){
            while(i < returnStr.length() && !isOperator(returnStr.at(i)) && returnStr.at(i) != '(' && returnStr.at(i) != ')'){
                curVal += returnStr.at(i);
                i++;
            }
            if(Maps::instance()->getSymbolTable().count(curVal) == 1) {
                int startPos = returnStr.find(curVal);
                string valueOfVar = to_string(Maps::instance()->getValueByVar(curVal));
                returnStr.replace(startPos, curVal.length(), valueOfVar);
                curVal = "";
                i = returnStr.find(valueOfVar) + valueOfVar.length();
            }
        }
    }
    //insert zeros before each minus (negative) to convert it to binary expression
    if(returnStr.at(0) == '-'){
        returnStr.insert(0, "0");
    }
    for(i = 1; i < returnStr.length(); i++){
        if(returnStr.at(i) == '-' && !isdigit(returnStr.at(i-1))){
            returnStr.insert(i, "(0");
            i = i + 3; // skip the indexes of "(0-"
            while(i < returnStr.length()){
                if(isdigit(returnStr.at(i))){
                    i++;
                } else{
                    break;
                }
            }
            returnStr.insert(i, ")");
        }
    }
    return returnStr;
}
/*
string ExpressionParser::preProcess(string str){
    string returnStr = "";
    int i;
    //remove spaces
    for(i = 0; i < str.length(); i++){
        if(str.at(i) != ' '){
            returnStr += str.at(i);
        }
    }

    //trade variable names with their values
    string curVal = "";
    for(i = returnStr.find("=") + 1; i < returnStr.length(); i++){
        if(!isdigit(returnStr.at(i)) && !isOperator(returnStr.at(i)) && returnStr.at(i) != '(' && returnStr.at(i) != ')'){
            while(i < returnStr.length() && !isOperator(returnStr.at(i)) && returnStr.at(i) != '(' && returnStr.at(i) != ')'){
                curVal += returnStr.at(i);
                i++;
            }
            if(Maps::instance()->getSymbolTable().count(curVal) == 1) {
                int startPos = returnStr.find(curVal);
                string valueOfVar = to_string(Maps::instance()->getValueByVar(curVal));
                returnStr.replace(startPos, curVal.length(), valueOfVar);
                curVal = "";
                i = returnStr.find(valueOfVar) + valueOfVar.length();
            }
        }
    }
    //insert zeros before each minus (negative) to convert it to binary expression
    if(returnStr.at(0) == '-'){
        returnStr.insert(0, "0");
    }

    for(i = 1; i < returnStr.length(); i++){
        if(returnStr.at(i) == '-' && !isdigit(returnStr.at(i-1))){
            returnStr.insert(i, "0");
        }
    }

    return returnStr;
}


/*bool ExpressionParser::isOperatorGreater(string op1, string op2){
    if((op1 == "+" || op1 == "-") && (op2 == "*" || op2 == "/" )){
        return true;
    }
    return false;
}*/

//checks if op2 >= op1
bool ExpressionParser::isOperatorGreaterOrEqual(string op1, string op2){
    if(op2 == "END" || op2 == "("){
        return false;
    } else if (op1 == "+" || op1 == "-" || op2 == "*" || op2 == "/"){
        return true;
    }
    return false;
}

string ExpressionParser::shunting_yard(string exp){
    queue<string> queue;
    stack<string> stack;
    string output;
    stack.push("END");

    string newExp = preProcess(exp);
    int i = 0;
    string curNum;
    while(i < newExp.length()){
        if(isdigit(newExp.at(i)) || newExp.at(i) == '.'){
            curNum += newExp.at(i);
        } else if (newExp.at(i) == '('){
            stack.push("(");
        } else if (newExp.at(i) == ')'){
            if(curNum != ""){
                if(curNum.length() == 1){
                    queue.push(curNum);
                } else{
                    queue.push("(" + curNum + ")");
                }
                curNum = "";
            }

            while(stack.top() != "("){
                queue.push(stack.top());
                stack.pop();
            }
            stack.pop();
        } else{
            if(curNum != ""){
                if(curNum.length() == 1){
                    queue.push(curNum);
                } else{
                    queue.push("(" + curNum + ")");
                }
                curNum = "";
            }

            if(isOperatorGreaterOrEqual(newExp.substr(i, 1), stack.top())){
                queue.push(stack.top());
                stack.pop();
            }
            stack.push(newExp.substr(i, 1));
        }
        i++;
    }

    if(curNum != ""){
        if(curNum.length() == 1){
            queue.push(curNum);
        } else{
            queue.push("(" + curNum + ")");
        }
        curNum = "";
    }

    while(stack.top() != "END"){
        queue.push(stack.top());
        stack.pop();
    }
    queue.push("END");

    while(queue.front() != "END"){
        output = output + queue.front();
        queue.pop();
    }
    return output;
    //string::iterator end_pos = remove(exp.begin(), exp.end(), ' ');
    //exp.erase(end_pos, exp.end());
}

bool ExpressionParser::isOperator(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/'){
        return true;
    }
    return false;
}

double ExpressionParser::calculateFirstNum(const string& exp, unsigned long &index) {
    if (exp[index] != '(') {
        return (exp[index] - '0');
    }
    string val = "";
    ++index;
    while (exp[index] != ')') {
        val += exp[index];
        index++;
    }
    if (val.find('.') == string::npos)
        return (double) atoi(val.c_str());
    val.erase(val.find_last_not_of('0') + 1, string::npos);
    double number = atof(val.c_str());

    return number;
}

/**
 * @param type the sign
 * @param left expression.
 * @param right expression.
 * @return the expression with the currenct sign.
 */
Expression* ExpressionParser::createExpression(char type, Expression *left, Expression *right){
    Expression* exp;
    switch (type) {
        case '+':
            exp = new Plus(left, right);
            GarbageVector::instance()->push(exp);
            return exp;
        case '-':
            exp = new Minus(left, right);
            GarbageVector::instance()->push(exp);
            return exp;
        case '*':
            exp = new Mul(left, right);
            GarbageVector::instance()->push(exp);
            return exp;
        case '/':
            exp = new Div(left, right);
            GarbageVector::instance()->push(exp);
            return exp;
    }
}

/**
 * @param string in postfix .
 * @return the result of this expression.
 */
Expression* ExpressionParser::postToExp(const string& exp){
    Expression * retExp;
      if (exp.length() != 1){
          if(exp.at(0) == '(' && exp.at(exp.size() - 1) == ')') {
              if (isInt(exp.substr(1, exp.length() - 2))) {
                  retExp = new Number(stoi(exp.substr(1, exp.length() - 2)));
                  GarbageVector::instance()->push(retExp);
                  return retExp;
              } else if (isDouble(exp.substr(1, exp.length() - 2))) {
                  retExp =  new Number(stod(exp.substr(1, exp.length() - 2)));
                  GarbageVector::instance()->push(retExp);
                  return retExp;
              }
          }
      } else {
          if (isInt(exp)) {
              retExp =   new Number(stoi(exp));
              GarbageVector::instance()->push(retExp);
              return retExp;
          }
      }

    stack<tuple<double, unsigned int>> numStack;
    stack<tuple<Expression *, unsigned int> > expStack;
    unsigned int time = 0;
    unsigned long index = 0;
    while (exp[index]) {
        // add new Number:
        if (!isOperator(exp[index])) {
            numStack.push(tuple<double,unsigned int>(calculateFirstNum(exp,index),time));
            ++index;
            ++time;
            // take two expressions and create one with them:
        } else if (expStack.size() >= 2 && ((numStack.empty() || ((time - get<1>(expStack.top()) == 1)
                                                                  && (time - get<1>(numStack.top()) > 2))))) {
            Expression *ex2 = get<0>(expStack.top());
            expStack.pop();
            Expression *ex1 = get<0>(expStack.top());
            expStack.pop();
            expStack.push(tuple<Expression *, unsigned int>(createExpression(exp[index], ex1, ex2), time));
            ++index;
            ++time;
        } else {
            // take first two numbers and push new Expression:
            if ((expStack.empty() || time - get<1>(expStack.top()) > 2) && !numStack.empty()) {
                double v2 = get<0>(numStack.top());
                numStack.pop();
                double v1 = get<0>(numStack.top());
                numStack.pop();
                Expression* expV1 = new Number(v1);
                Expression* expV2 = new Number(v2);
                GarbageVector::instance()->push(expV1);
                GarbageVector::instance()->push(expV2);
                expStack.push(tuple<Expression *, unsigned int>(createExpression(exp[index], expV1,
                                                                                 expV2), time));
                ++index;
                ++time;
            } else {
                tuple<double, unsigned int> numberTup = numStack.top();
                double val = get<0>(numberTup); // value
                numStack.pop();
                tuple<Expression *, unsigned int> expressionTup = expStack.top();
                Expression *expression = get<0>(expressionTup); // expression
                expStack.pop();
                // check who came first, if number, number will be on left side of the new operator. else right side
                Expression * expVal = new Number(val);
                GarbageVector::instance()->push(expVal);
                if (get<1>(numberTup) > get<1>(expressionTup)) {
                    expStack.push(tuple<Expression *, unsigned int>(createExpression(exp[index], expression,
                                                                                     expVal), time));
                } else {
                    expStack.push(tuple<Expression *, unsigned int>(createExpression(exp[index], expVal,
                                                                                     expression), time));
                }
                ++index;
                ++time;
            }
        }
    }
    while(!numStack.empty()) {
        tuple<double, unsigned int> numberTup = numStack.top();
        double val = get<0>(numberTup); // value
        numStack.pop();
        Expression *expression;
        Expression * expVal = new Number(val);
        GarbageVector::instance()->push(expVal);
        if(!expStack.empty()) {
            tuple<Expression *, unsigned int> expressionTup = expStack.top();
            expression = get<0>(expressionTup);
            expStack.pop();
            char sign = '-';
            if(val < 0 ) sign= '+';
            expStack.push(tuple<Expression *, unsigned int>(createExpression(sign, expression,
                                                                             expVal), time));
        }// expression
        else {
            double val2 = get<0>(numStack.top());
            numStack.pop();
            expression = new Number(val2);
            GarbageVector::instance()->push(expression);
            expStack.push(tuple<Expression *, unsigned int>(createExpression('+', expression,
                                                                             expVal), time));
        }
    }
    return get<0>(expStack.top()); // the full exp is at the top of the stack
}

bool ExpressionParser::isInt(string str){
    for (int i = 0; i < str.length(); ++i) {
        if(!isdigit(str.at(i))){
            return false;
        }
    }
    return true;
}
bool ExpressionParser::isDouble(string str) {
    int countPoint = 0;
    if(!isdigit(str.at(0)) && !isdigit(str.at(str.length() - 2))){
        return false;
    }
    for (int i = 0; i < str.length(); ++i) {
        if(!isdigit(str.at(i)) && countPoint == 1){
            return false;
        }
        if(str.at(i) == '.') {
            countPoint++;
        }
    }
    if(countPoint == 1) {
        return true;
    } else {
        return false;
    }
}

