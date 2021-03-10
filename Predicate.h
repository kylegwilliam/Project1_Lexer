//
// Created by Kyle Gwilliam on 2/19/21.
//

#ifndef PROJECT1_LEXER_PREDICATE_H
#define PROJECT1_LEXER_PREDICATE_H

#include <string>
#include <vector>
#include "Parameter.h"

using namespace std;
#include <iostream>



class Predicate {
private:
    string predicateID;
    vector <Parameter*> predicateListOfParameters;

public:

    string toString();

    void setPredicateID(string location);

    void setPredicateListOfParameters(vector<Parameter*> newString);

    string toStringFacts();

    string toStringQuery();

    const vector<Parameter *> &getPredicateListOfParameters() const;
};


#endif //PROJECT1_LEXER_PREDICATE_H
