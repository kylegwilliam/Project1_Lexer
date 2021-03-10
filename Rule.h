//
// Created by Kyle Gwilliam on 2/19/21.
//

#ifndef PROJECT1_LEXER_RULE_H
#define PROJECT1_LEXER_RULE_H
#include "Parameter.h"
#include "Predicate.h"

class Rule {

private:
    Predicate* headPredicate;
    vector <Predicate*> bodyPredicate;

public:

    void headPredicateFunction(Predicate* newHeadPred);

    void bodyPredicateFunction(vector <Predicate*> newBodyPred);

    string toString();




};


#endif //PROJECT1_LEXER_RULE_H
