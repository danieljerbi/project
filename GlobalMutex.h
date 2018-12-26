//
// Created by daniel on 26/12/18.
//

#ifndef PROJECT_GLOBALMUTEX_H
#define PROJECT_GLOBALMUTEX_H

#include <mutex>
using namespace std;

class GlobalMutex {
private:
    mutex* globalMutex1;
    static GlobalMutex *globalMutex_instance;
public:
    GlobalMutex();
    mutex* getMutex(){
        return this->globalMutex1;
    }
    static GlobalMutex *instance();

};


#endif //PROJECT_GLOBALMUTEX_H
