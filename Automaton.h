//
// Created by Kyle Gwilliam on 1/25/21.
//

#ifndef PROJECT1_LEXER_AUTOMATON_H
#define PROJECT1_LEXER_AUTOMATON_H

//#pragma once
#include <string>
#include "Token.h"

using namespace std;

class Automaton {

protected:
    int inputRead = 0;
    int newLines = 0;
    TokenType type;

public:
    Automaton(){}

    Automaton(TokenType type) {
        this->type = type;
    }

    virtual TokenType getType(){
        return type;
    }

// Start the automaton and return the number of characters read
// read == 0 indicates the input was rejected
// read > 0 indicates the input was accepted

    virtual int Start(const std::string& input) = 0; // not in the right class?

    Token* CreateToken(std::string input, int lineNumber) {
        //return new Token(TokenType type, string inputChar, int lineNumber);
        return new Token(type, input, lineNumber);
    }

    virtual int NewLinesRead() const {
        return newLines;
    }
};



//class MatcherAutomaton : public Automaton {

//class StringAutomton : public Automaton { put the logic in automiton.cpp. example is in matcherautomiton.cpp.


//private:

//    std::string toMatch;

//public:

//    MatcherAutomaton(std::string toMatch, TokenType tokenType);

//    int Start(const std::string& input);

//    int newLines();

//    string createTokens();
//};

#endif //PROJECT1_LEXER_AUTOMATON_H

