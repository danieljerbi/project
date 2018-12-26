//
// Created by daniel on 26/12/18.
//

#include "GlobalMutex.h"
GlobalMutex::GlobalMutex() {

}
GlobalMutex *GlobalMutex::globalMutex_instance = 0;
GlobalMutex* GlobalMutex:: instance() {
    if (!globalMutex_instance) {
        globalMutex_instance = new GlobalMutex;
    }
    return globalMutex_instance;
}
