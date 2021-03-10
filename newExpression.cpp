//
// Created by Kyle Gwilliam on 2/26/21.
//

#include "newExpression.h"



string newExpression::toString() {

    /**
    if (leftParam == nullptr && rightParam == nullptr) {
        return "(" + operatorAddMult + ")";
    }

    else if(leftParam == nullptr) {
        return "(" + operatorAddMult + rightParam->toString() + ")";
    }

    else if (rightParam == nullptr) {
        return "(" + leftParam->toString() + operatorAddMult + ")";
    }

**/

    return "(" + leftParam->toString() + operatorAddMult + rightParam->toString() + ")";
    //return "";
}
