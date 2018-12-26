//
// Created by daniel on 26/12/18.
//

#include "GarbageVector.h"
GarbageVector::GarbageVector() {

}
GarbageVector *GarbageVector::garbage_instance = 0;
GarbageVector* GarbageVector:: instance() {
    if (!garbage_instance) {
        garbage_instance = new GarbageVector;
    }
    return garbage_instance;
}

void GarbageVector::deleteAll() {
    for (int i = garbage.size() - 1; i >= 0 ; i--) {
        delete(garbage.at(i));
    }
}