//
// Created by Kyle Gwilliam on 2/19/21.
//

#ifndef PROJECT1_LEXER_PARAMETER_H
#define PROJECT1_LEXER_PARAMETER_H
#include <string>
using namespace std;

class Parameter {
private:
    //string varName;

public:

    //Parameter();

    //Parameter(string outputID);

    virtual void setParam(Parameter* outputParam) = 0;

    virtual void setOpp(string outputOpp) = 0;

    virtual string toString() = 0;
};


#endif //PROJECT1_LEXER_PARAMETER_H
