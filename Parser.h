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
#include "Rule.h"
#include "DatalogProgram.h"
#include "newExpression.h"
#include "simpleParameter.h"

using namespace std;



class Parser {
private:

    int locationToken = 0;
    vector<Token*> tokens;
    DatalogProgram finalOutput;
public:
    DatalogProgram getFinalOutput();

private:


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

    void scheme();

    void fact();

    void rule();

    void query();

//

    Predicate* headPredicate();

    void predicate(Predicate& newPred);

//

    void predicateList(vector <Predicate*>& newVectPred);

    void parameterList(vector <Parameter*>& queryOrRuleList);

    void stringList(vector <Parameter*>& groupsOfString);

    void idList(vector<Parameter*>& predicateList);

//

    Parameter* parameter(vector <Parameter*>& queryOrRuleList);

    Parameter* expression(vector <Parameter*>& queryOrRuleList);

    string operator1(vector <Parameter*>& queryOrRuleList);




};


#endif //PROJECT1_LEXER_PARSER_H
