//
// Created by daniel on 18/12/18.
//

#ifndef PROJECT_MAPS_H
#define PROJECT_MAPS_H

#include "iostream"
#include "mutex"

#include <map>
#include <string>
using namespace std;

class Maps{
private:
    map<string, string> bindMap1; //matches variable name with his path from the xml
    map<string, string> bindMap2; //matches path from the xml to variable name
    map<string, double> values; //matches each path with his value from the simulator
    map<string, double> symbolTable; //matches each variable with his value
    map<int, string> indexMap; //matches each index with his path
    static Maps *maps_instance;
    mutex globMutex;
public:
    Maps();
    void updatePathValue(string path, double value){
        values[path] = value;
    }
    void updtaeVarPath(string var, string path){
        bindMap1[var] = path;
    }
    void updtaePathVar(string path, string var){
        bindMap2[path] = var;
    }
    void updateSymbolTable(string var, double value){
        symbolTable[var] = value;
    }
    string getVarByPath(string path){
        return bindMap2.at(path);
    }
    double getValueByVar(string var){;
         return symbolTable[var];
    }
    map<string, double> getSymbolTable(){ return symbolTable;}
    map<string, string> getBindVarPathMap() {return bindMap1; }

    string getPathByVar(string var){
        return bindMap1[var];
    }
    string getPathByIndex(int i){return indexMap.at(i);}

    static Maps *instance();

};
#endif //PROJECT_MAPS_H
