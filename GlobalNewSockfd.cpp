//
// Created by daniel on 20/12/18.
//

#include "GlobalNewSockfd.h"
GlobalNewSockfd::GlobalNewSockfd() {

}
GlobalNewSockfd *GlobalNewSockfd::newSockfd_instance = 0;
GlobalNewSockfd* GlobalNewSockfd:: instance() {
    if (!newSockfd_instance) {
        newSockfd_instance = new GlobalNewSockfd;
    }
    return newSockfd_instance;
}