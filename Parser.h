//
// Created by Kyle Gwilliam on 2/11/21.
//

#ifndef PROJECT1_LEXER_PARSER_H
#define PROJECT1_LEXER_PARSER_H

#include "Token.h"
#include <vector>

#include <iostream>
#include "Predicate.h"
#include <iostream>

using namespace std;



class Parser {
private:

    int locationToken = 0;
    vector<Token*> tokens;

    //constructor or setter
    vector<Token*> newTokens;


public:

    Parser(vector<Token*> tokens);

    // So i want to get the token information from main and pass it into my Parser.h


    void MatchFunction(TokenType type);

    void Parse();

//

    void datalogProgram();

//

    void schemeList();

    void factList();

    void ruleList();

    void queryList();

//

    string scheme();

    void fact();

    void rule();

    void query();

//

    void headPredicate();

    void predicate();

//

    void predicateList();

    void parameterList();

    void stringList();

    void idList();

//

    void parameter();

    void expression();

    void operator1();




};


#endif //PROJECT1_LEXER_PARSER_H
