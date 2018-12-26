//
// Created by daniel on 21/12/18.
//

#include "EnterIfWhile.h"
EnterIfWhile::EnterIfWhile() {

}
EnterIfWhile *EnterIfWhile::enterIfWhile_instance = 0;
EnterIfWhile* EnterIfWhile:: instance() {
    if (!enterIfWhile_instance) {
        enterIfWhile_instance = new EnterIfWhile;
    }
    return enterIfWhile_instance;
}