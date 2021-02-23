//
// Created by Kyle Gwilliam on 2/19/21.
//

#ifndef PROJECT1_LEXER_DATALOGPROGRAM_H
#define PROJECT1_LEXER_DATALOGPROGRAM_H


#include <vector>
#include <string>

//#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "Predicate.h"
#include "Rule.h"
#include "Parameter.h"

class DatalogProgram {
private:

    vector<Predicate*> scheme;
    vector<Predicate*> parameter;
    vector<Predicate*> quieres;
    vector<Rule*> rule;

    //should have the 4 vectors in it.


public:

    //makes some helper functions to add to them or to clear them. 
    //toString
    string toString();


};


#endif //PROJECT1_LEXER_DATALOGPROGRAM_H
