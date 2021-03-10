//
// Created by Kyle Gwilliam on 2/26/21.
//

#ifndef PROJECT1_LEXER_SIMPLEPARAMETER_H
#define PROJECT1_LEXER_SIMPLEPARAMETER_H
#include "Parameter.h"
#include <string>
using namespace std;
#include <iostream>

class simpleParameter : public Parameter {
private:

public:

    string simpleNewString;

    string toString();

    simpleParameter(string newParamString) {
        simpleNewString = newParamString;
    }

    void setOpp(string outputOpp) {
        cout << "Error in setOpp simpleParameter" << endl;
    }

    void setParam(Parameter* outputParam) {
        cout << "Error in setParam SimpleParameter" << endl;
    }

    /// makes an id or a string
    /// make a bool to say what kind it is - maybe


};


#endif //PROJECT1_LEXER_SIMPLEPARAMETER_H
