//
// Created by Kyle Gwilliam on 2/19/21.
//

#ifndef PROJECT1_LEXER_DATALOGPROGRAM_H
#define PROJECT1_LEXER_DATALOGPROGRAM_H


#include "Predicate.h"
#include "Rule.h"
#include "Parameter.h"
#include "Lexer.h"
#include <set>
using namespace std;

class DatalogProgram {
private:

    vector<Predicate*> scheme;
    vector<Predicate*> facts;
    vector<Predicate*> query;
    vector<Rule*> rule;
    //set<string> domainSet;

    //should have the 4 vectors in it.


public:

    set<string> domainSet;


    // make a setter to allow me to push back on vector.
    void setScheme(Predicate* newPredicate) {
        scheme.push_back(newPredicate);
    }

    void setFacts(Predicate* newFacts) {
        facts.push_back(newFacts);
    }

    void setQuery(Predicate* newQuery) {
        query.push_back(newQuery);
    }

    void setRule(Rule* newRule) {
        rule.push_back(newRule);
    }

    //makes some helper functions to add to them or to clear them. 
    //toString
    DatalogProgram();
    void toString();


};


#endif //PROJECT1_LEXER_DATALOGPROGRAM_H
