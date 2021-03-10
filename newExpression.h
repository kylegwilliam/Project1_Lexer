//
// Created by Kyle Gwilliam on 2/26/21.
//

#ifndef PROJECT1_LEXER_NEWEXPRESSION_H
#define PROJECT1_LEXER_NEWEXPRESSION_H
#include "Parameter.h"


class newExpression : public Parameter {
private:

public:

    string operatorAddMult;

    Parameter* leftParam;
    Parameter* rightParam;

    string toString();

    void setParam(Parameter* outputParam) {
        if (leftParam == nullptr) {
            leftParam = outputParam;
        }
        else {
            rightParam = outputParam;
        }
    }

    void setOpp(string outputOpp) {
        operatorAddMult = outputOpp;
    }

    newExpression(){
        leftParam = nullptr;
        rightParam = nullptr;
    }

};


#endif //PROJECT1_LEXER_NEWEXPRESSION_H
