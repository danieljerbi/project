//
// Created by daniel on 21/12/18.
//

#ifndef PROJECT_ENTERIFWHILE_H
#define PROJECT_ENTERIFWHILE_H


class EnterIfWhile {
private:
    bool enter;
    static EnterIfWhile *enterIfWhile_instance;
public:
    EnterIfWhile();
    void setEnter(bool enter){
        this->enter = enter;
    }
    bool getEnter(){
        return this->enter;
    }
    static EnterIfWhile *instance();

};


#endif //PROJECT_ENTERIFWHILE_H
