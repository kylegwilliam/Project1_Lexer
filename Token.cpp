//
// Created by Kyle Gwilliam on 1/25/21.
//

#include "Token.h"
#include <string>
using namespace std;
#include <iostream>

//UNDEFINED


Token::Token() {}

Token::Token(TokenType type, string input, int lineNumber) {
    this->type = type;  //this->token = token;
    this->value = input; //this->value = value;
    this->lineNumber = lineNumber; //this->lineNumber = lineNumber;

}



string Token::tokenToString(TokenType token) {
    switch (token) {
        //case STRING:
        //    return "STRING";
        case COMMA:
            return "COMMA";
            break;
        case PERIOD:
            return "PERIOD";
            break;
        case Q_MARK:
            return "Q_MARK";
            break;
        case LEFT_PAREN:
            return "LEFT_PAREN";
            break;
        case RIGHT_PAREN:
            return "RIGHT_PAREN";
            break;
        case COLON:
            return "COLON";
            break;
        case COLON_DASH:
            return "COLON_DASH";
            break;
        case MULTIPLY:
            return "MULTIPLY";
            break;
        case SCHEMES:
            return "SCHEMES";
            break;
        case FACTS:
            return "FACTS";
            break;
        case ADD:
            return "ADD";
            break;
        case RULES:
            return "RULES";
            break;
        case QUERIES:
            return "QUERIES";
            break;
        case STRING:
            return "STRING";
            break;
        case ID:
            return "ID";
            break;
        case COMMENT:
            return "COMMENT";
            break;
        case UNDEFINED:
            return "UNDEFINED";
            break;
        case E_O_F:
            return "EOF";
            break;
    }
    return "error";
}

void Token::outputString(){


    cout << "("  <<  tokenToString(type) << "," << "\"" << value << "\"" << "," << lineNumber << ")" << endl;

    //return "( " + tokenToString(token) + ", " + value + ", " + to_string(lineNumber);
    //string class
    // make a function that goes thought all the token vectors. then it will use a 4 loop to go through all tokens
    //and have them go to the outputString function.
    }


