//
// Created by daniel on 26/12/18.
//

#ifndef PROJECT_GARBAGEVECTOR_H
#define PROJECT_GARBAGEVECTOR_H

#include <vector>
using namespace std;

class GarbageVector {
private:
    vector<void*> garbage;
    static GarbageVector *garbage_instance;

public:
    GarbageVector();
    void push(void* gar) {garbage.push_back(gar);}
    void deleteAll();
    static GarbageVector *instance();

};


#endif //PROJECT_GARBAGEVECTOR_H
