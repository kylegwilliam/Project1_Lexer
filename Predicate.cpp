//
// Created by Kyle Gwilliam on 2/19/21.
//

#include "Predicate.h"
using namespace std;



string Predicate::toString() {

    string output;


    output += predicateID;
    output += "(";
    for (unsigned int i = 0; i < predicateListOfParameters.size(); i++) {
        output += predicateListOfParameters.at(i)->toString();
        if (i < predicateListOfParameters.size() - 1) {
            output +=",";
        }
        else {
            output += "";
        }
    }

    output +=")";
    return output;

}

void Predicate::setPredicateID(string location) {
    predicateID = location;

}

void Predicate::setPredicateListOfParameters(vector<Parameter*> newString) {

    predicateListOfParameters = newString;

}

string Predicate::toStringFacts() {

    string newString;

    newString += predicateID;
    newString += "(";
    for (unsigned int i = 0; i < predicateListOfParameters.size(); i++) {
        newString += predicateListOfParameters.at(i)->toString();
        if (i < predicateListOfParameters.size() - 1) {
            newString += ",";
        } else {
            newString += "";
        }
    }
    newString += ")";
    newString += ".";
    return newString;

}

string Predicate::toStringQuery() {

    string newString;

    newString += predicateID;
    newString += "(";
    for (unsigned int i = 0; i < predicateListOfParameters.size(); i++) {
        newString += predicateListOfParameters.at(i)->toString();
        if (i < predicateListOfParameters.size() - 1) {
            newString += ",";
        } else {
            newString += "";
        }
    }
    newString += ")";
    newString += "?";
    return newString;

}

const vector<Parameter *> &Predicate::getPredicateListOfParameters() const {
    return predicateListOfParameters;
}
