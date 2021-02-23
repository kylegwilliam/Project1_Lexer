//
// Created by Kyle Gwilliam on 1/25/21.
//

#include "Lexer.h"


void Lexer::Print() {

    int numTokens = 0;

    for (unsigned int i = 0; i < tokens.size(); i++ ) {

        tokens.at(i)->outputString();
        numTokens += 1;


        }
    cout << "Total Tokens = " << numTokens << endl;

}
