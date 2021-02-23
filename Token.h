//
// Created by Kyle Gwilliam on 1/25/21.
//

#ifndef PROJECT1_LEXER_TOKEN_H
#define PROJECT1_LEXER_TOKEN_H

//#pragma once
#include <string>
using namespace std;

// It should contain an enumerated type that defines the possible values for a token type
//(note we could use inheritance for this, but our tokens will essentially be handled all
//the same way).

enum TokenType {
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    COLON,
    COLON_DASH,
    MULTIPLY,
    ADD,
    FACTS,
    RULES,
    QUERIES,
    STRING,
    SCHEMES,
    COMMENT,
    ID,
    UNDEFINED,
    E_O_F


    // NEED TO HAVE EOF
};

class Token {

private:

//    TokenType token;
    int lineNumber;
    string value;


public:

    Token();
    Token(TokenType type, string input, int lineNumber);
    TokenType type;
    string tokenToString(TokenType token);
    //int lineNumber = 1;
    void toString();
    // need to make a if or a switch statment of every possible condition. If "," return comma, "<" , line number.
    // do all of that work in the Token.cpp under one function.
    void outputString();

    string outputValue() {
        return value;
    }

};




#endif //PROJECT1_LEXER_TOKEN_H
