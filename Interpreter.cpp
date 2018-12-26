//
// Created by daniel on 16/12/18.
//

#include "Interpreter.h"
#include "iostream"
#include <chrono>
#include <vector>
#include <queue>
#include <stack>
#include "OpenServerCommand.h"
#include "ConnectCommand.h"
#include "Maps.h"
#include "Number.h"
#include "Div.h"
#include "Mul.h"
#include "Plus.h"
#include "Minus.h"
#include "string.h"
#include "stdio.h"
#include "GarbageVector.h"

using namespace std;
Interpreter::Interpreter() {
    mapCommand["openDataServer"] = new OpenServerCommand();
    mapCommand["connect"] = new ConnectCommand();
    mapCommand["Print"] = new PrintCommand();
    mapCommand["Var"] = new VarCommand();
    mapCommand["Set"] = new SetCommand();
    mapCommand["If"] = new IfWhileCommand();
    expressionParser = new ExpressionParser();
    for (std::map<string,Command*>::iterator it=mapCommand.begin(); it!=mapCommand.end(); ++it) {
        GarbageVector::instance()->push(it->second);
    }
    GarbageVector::instance()->push(expressionParser);
}

vector<string> Interpreter::lexer(string line){
    vector<string> strings;
    string curStr = "";
    string leftExp = "";
    string rightExp = "";
    string curExp = "";

    int i = 0;
    int spaceCounter = 0;
    while (i<line.length() && line.at(i) == '\t') {
        for (int j = 0; j < line.length() - 1; ++j) {
            line.at(j) = line.at(j + 1);
        }
        line = line.substr(0, line.length() - 1);
        i++;
    }
    for(i = 0; i < line.length(); i++){
        if(line.at(i) == ' '){
            spaceCounter++;
        }
    }
    for(i = 0; i < line.length(); i++){
        if(line.at(i) == ' '){
            if(curStr != ""){
                strings.push_back(curStr);
                curStr = "";
            }
        } else if(line.at(i) == '=' && line.at((i+1)) != '=' && line.at((i-1)) != '=' && line.at((i-1)) != '!' && line.at((i-1)) != '>' && line.at((i-1)) != '<' && line.find("bind") == string::npos){
            int flag = 0;
            for (int j = 0; j < strings.size(); ++j) {
                if(curStr == strings.at(j)){
                    flag = 1;
                }
            }
            if(flag == 0 && curStr != "") {
                strings.push_back(curStr);
            }
            strings.push_back("="); //add
            i++;
            while(i < line.length() && line.at(i) != '}'){
                curExp += line.at(i);
                i++;
            }
            string postFix = expressionParser->shunting_yard(curExp);
            strings.push_back(to_string(expressionParser->postToExp(postFix)->calculate()));
        } else if ((line.at(i) == '=' && line.at((i+1)) == '=') || (line.at(i) == '!' && line.at((i+1)) == '=') || (line.at(i) == '>' && line.at((i+1)) == '=') || (line.at(i) == '<' && line.at((i+1)) == '=')) {
            if(curStr != "") {
                strings.push_back(curStr);
            }
            string str(1,line.at(i));
            str = str + "" + line.at(i+1);
            strings.push_back(str);
            i++;
            curStr = "";
        } else if (line.at(i) == '>' || line.at(i) == '<'){
            int flag = 0;
            for (int j = 0; j < strings.size(); ++j) {
                if(curStr == strings.at(j)){
                    flag = 1;
                }
            }
            if(flag == 0 && curStr != "") {
                strings.push_back(curStr);
            }
            string str(1,line.at(i));
            strings.push_back(str);
            curStr = "";
        } else{
            curStr += line.at(i);
        }
    }
    int flag2 = 0;
    for (int j = 0; j < strings.size(); ++j) {
        if(curStr == strings.at(j)){
            flag2 = 1;
        }
    }
    if(flag2 == 0 && curStr != "") {
        strings.push_back(curStr);
    }
    if(line.length() > 1) {
        if (line.at(line.length() - 2) == '}') {
            strings.push_back("}");
        }
    }
    int k = 1;
    if(strings.at(0) == "while" || strings.at(0) == "if") {
        while (strings.at(k) != "==" && strings.at(k) != "!=" && strings.at(k) != ">" && strings.at(k) != "<" && strings.at(k) != ">=" && strings.at(k) != "<=") {
            leftExp = leftExp + strings.at(k);
            k++;
        }
        k++;
        if(strings.at(strings.size() - 1) == "{") {
            while (k < strings.size() - 1) {
                rightExp = rightExp + strings.at(k);
                k++;
            }
        } else {
            while (k < strings.size()) {
                rightExp = rightExp + strings.at(k);
                k++;
            }
        }
        vector<string> strings2;
        strings2.push_back(strings.at(0));
        strings2.push_back(to_string(expressionParser->postToExp(expressionParser->shunting_yard(leftExp))->calculate()));
        for (int j = 0; j < strings.size(); ++j) {
            if(strings.at(j) == "==" || strings.at(j) == "!=" || strings.at(j) == ">" || strings.at(j) == "<" || strings.at(j) == ">=" || strings.at(j) == "<=") {
                strings2.push_back(strings.at(j));
            }
        }
        strings2.push_back(to_string(expressionParser->postToExp(expressionParser->shunting_yard(rightExp))->calculate()));
        if (strings.at(strings.size() - 1) == "{") {
            strings2.push_back("{");
        }
        strings2.push_back(line);
        return strings2;
    }
    return strings;
}

void Interpreter::parser(vector<string> strings) {
    string str = strings[0];
    vector<string> argu;
    if (str == "openDataServer") {
        argu.push_back(strings.at(1));
        argu.push_back(strings.at(2));
        this->mapCommand.at("openDataServer")->doCommand(argu);
    } else {
        if (str == "connect") {
            argu.push_back(strings.at(1));
            argu.push_back(strings.at(2));
            this->mapCommand.at("connect")->doCommand(argu);
        } else {
            if (str == "var") {
                    for (int i = 1; i < strings.size() ; ++i) {
                        argu.push_back(strings[i]);
                    }
                    mapCommand.at("Var")->doCommand(argu);

            } else {
                if (str == "print") {
                    for (int i = 1; i < strings.size(); ++i) {
                        argu.push_back(strings[i]);
                    }
                    mapCommand.at("Print")->doCommand(argu);
                }else {
                    if ( Maps::instance()->getSymbolTable().count(str) == 1) {
                        argu.push_back(strings[0]);
                        argu.push_back(strings[2]);
                        mapCommand.at("Set")->doCommand(argu);
                    } else {
                        if(str.substr(0,str.find(' ')) == "if") {
                            vector<string> lex = lexer(str);
                            mapCommand["If"]->doCommand(lex);
                            if(EnterIfWhile::instance()->getEnter()) {
                                for (int i = 1; i < strings.size(); ++i) {
                                    if (strcmp(strings.at(i).c_str(),"}") != 0) {
                                        mapCommand["If"]->doCommand(lexer(strings.at(i)));
                                    }
                                }
                            }
                        } else {
                            if(str.substr(0,str.find(' ')) == "while") {
                                vector<string> lex = lexer(str);
                                mapCommand["If"]->doCommand(lex);
                                while(EnterIfWhile::instance()->getEnter()){
                                    for (int i = 1; i < strings.size(); ++i) {
                                        if (strcmp(strings.at(i).c_str(),"}") != 0) {
                                            mapCommand["If"]->doCommand(lexer(strings.at(i)));
                                        }
                                    }
                                    mapCommand["If"]->doCommand(lexer(strings.at(0)));
                                }
                            } else {
                                if (str == "sleep"){
                                    chrono::microseconds(stoi(strings[1]));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
