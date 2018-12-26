//
// Created by daniel on 20/12/18.
//

#include "PrintCommand.h"
#include "iostream"

PrintCommand::PrintCommand() {

}
void PrintCommand::doCommand(vector<string> strings) {
    if (strings.size() == 1) {
        if (strings[0].at(0) == '"') {
            cout << strings[0].substr(1, strings[0].find_last_of('"') - 1) << endl;
        } else {
            try {
                double d = Maps::instance()->getValueByVar(strings[0].c_str());
                cout << d << endl;
            } catch(exception e){
            }

        }
    } else {
        if (strings[0].at(0) == '"') {
            cout << strings[0].substr(1, strings[0].length()) << " ";
            for (int i = 1; i < strings.size() - 1; ++i) {
                cout << strings[i] << " ";
            }
            cout << strings[strings.size() - 1].substr(0, strings[strings.size() - 1].find_last_of('"')) << endl;
        }
    }
}
