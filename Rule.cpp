//
// Created by Kyle Gwilliam on 2/19/21.
//

#include "Rule.h"


void Rule::headPredicateFunction(Predicate* newHeadPred){
    headPredicate = newHeadPred;
}

void Rule::bodyPredicateFunction(vector <Predicate*> newBodyPred) {
    bodyPredicate = newBodyPred;

}

string Rule::toString() {

    string outputString;
    outputString += headPredicate->toString();

    outputString += " :- ";

    for (unsigned int i = 0; i < bodyPredicate.size(); i++) {

        outputString += bodyPredicate.at(i)->toString();

        if (i < bodyPredicate.size() - 1) {
            outputString += ",";

        } else {
            outputString += "";
        }
    }

    outputString += ".";

    return outputString;

}

