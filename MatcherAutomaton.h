//
// Created by Kyle Gwilliam on 2/3/21.
//

#ifndef PROJECT1_LEXER_MATCHERAUTOMATON_H
#define PROJECT1_LEXER_MATCHERAUTOMATON_H

#include <iostream>
#include "Token.h"
#include "Automaton.h"




class MatcherAutomaton : public Automaton {

private:

    int inputRead = 0;

    std::string toMatch;

    TokenType tokenType;

public:

    MatcherAutomaton(std::string toMatch, TokenType tokenType) : Automaton(tokenType) {

        this->toMatch = toMatch;
        //this->tokenType = tokenType;
    }




    int Start(const std::string& input);

    int newLines();

    string createTokens();

    TokenType getType(){
        return tokenType;
    }

};

class StringAutomaton : public Automaton {

private:


public:

    int Start(const std::string& input); // would that need to be string

    StringAutomaton(TokenType stringToken) {
        this->type = stringToken;
    }


};

class CommentAutomaton : public Automaton {
private:

public:
    int Start(const std::string& input);

    CommentAutomaton(TokenType commentToken) {
        this->type = commentToken;
    }

};

class IDAutomaton : public Automaton {
private:

public:
    int Start(const std::string& input);

    IDAutomaton(TokenType idToken) {
        this->type = idToken;
    }
};

#endif //PROJECT1_LEXER_MATCHERAUTOMATON_H
