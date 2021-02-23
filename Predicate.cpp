//
// Created by Kyle Gwilliam on 2/19/21.
//

#include "Predicate.h"
using namespace std;



string Predicate::toString() {
    cout << predicateID;
    cout << "(";
    for (unsigned int i = 0; i < predicateListOfParameters.size(); i++) {
        cout << predicateListOfParameters.at(i);
        cout << ", ";
    }
    cout << ")" << endl;

}

string Predicate::setPredicateID(string location) {
    predicateID = location;

}

string Predicate::setPredicateListOfParameters(vector<Parameter*> newString) {

    predicateListOfParameters = newString;

}