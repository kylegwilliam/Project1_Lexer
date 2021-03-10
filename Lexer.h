//
// Created by Kyle Gwilliam on 1/25/21.
//

#ifndef PROJECT1_LEXER_LEXER_H
#define PROJECT1_LEXER_LEXER_H

#include <vector>
#include <string>

//#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Automaton.h"
#include "Lexer.h"
#include "MatcherAutomaton.h"
#include "Token.h"

using namespace std;



//a class that contains the Tokenizer and all Tokens which it generates (consider
//using a vector<Token> or vector<Token*>). The logic of when to call getNextToken()
//should be contained here.

class Lexer {
    //the Lexer class should store a collection of finite-state automata.
    //It also needs to store all the generated tokens.

    //Return the list of all Tokens to the main

private:
        vector<Token*> tokens;
        vector<Automaton*> automata;

        //string inputString = answerString;

public:

    vector<Token*> getTokens() {
        return tokens;
    }


        Lexer() {

            //automata.push_back(new MatcherAutomaton("'", TokenType::STRING));
            automata.push_back(new MatcherAutomaton(",", TokenType::COMMA));
            automata.push_back(new MatcherAutomaton(".", TokenType::PERIOD));
            automata.push_back(new MatcherAutomaton("?", TokenType::Q_MARK));
            automata.push_back(new MatcherAutomaton("(", TokenType::LEFT_PAREN));
            automata.push_back(new MatcherAutomaton(")", TokenType::RIGHT_PAREN));
            automata.push_back(new MatcherAutomaton(":", TokenType::COLON));
            automata.push_back(new MatcherAutomaton(":-", TokenType::COLON_DASH));
            automata.push_back(new MatcherAutomaton("*", TokenType::MULTIPLY));
            automata.push_back(new MatcherAutomaton("+", TokenType::ADD));
            automata.push_back(new MatcherAutomaton("Schemes", TokenType::SCHEMES));
            automata.push_back(new MatcherAutomaton("Facts", TokenType::FACTS));
            automata.push_back(new MatcherAutomaton("Rules", TokenType::RULES));
            automata.push_back(new MatcherAutomaton("Queries", TokenType::QUERIES));


            automata.push_back(new IDAutomaton(TokenType::ID));
            automata.push_back(new StringAutomaton(TokenType::STRING));
            automata.push_back(new CommentAutomaton(TokenType::COMMENT));
            //automata.push_back(new MatcherAutomaton("UNDEFINED", TokenType::UNDEFINED));
            //automata.push_back(new MatcherAutomaton("EOF", TokenType::EOF));



        }

    void RemoveCommentToken() {
        for (unsigned int i = 0; i < tokens.size(); i++) {
            if (tokens.at(i)->type == COMMENT) {
                tokens.erase(tokens.begin()+i);
                i--;
            }
        }
    }

        void Run(string answerString) {
            int lineNumber = 1;
            string inputString = answerString;



            while (inputString.size() > 0) {
                int maxRead = 0;
                Automaton* maxAutomaton;
                maxAutomaton = automata.at(0);

                while (isspace(inputString[0])) {

                    if (inputString.at(0) == '\n') {
                        lineNumber += 1;
                        //inputString.erase(0,1);
                    }

                    inputString.erase(0,1);

                }

                if (inputString == "") {
                    break;
                }




                //Automaton* maxAutomaton = automata.at(1); // not sure about this line?

                int inputRead = 0;

                for (unsigned int i = 0; i < automata.size(); i++) {
                    //Automaton* maxAutomaton;



                    inputRead = automata.at(i)->Start(inputString);



                    if (inputRead > maxRead) {
                        maxRead = inputRead;
                        //cout << maxAutomaton->getType() << endl;
                        maxAutomaton = automata.at(i); // not sure what to do for this part. I had new TokenType(automata.at(i))
                        //cout << maxAutomaton->getType() << "1" << endl;
                    }

                }

                if (maxRead > 0) {
                    Token* newToken;
                    //cout << maxAutomaton->getType() << endl;
                    newToken = maxAutomaton->CreateToken(inputString.substr(0,maxRead), lineNumber);
                    lineNumber += maxAutomaton->NewLinesRead(); // add lineNumber?
                    tokens.push_back(newToken);

                }
                //inputRead.substr(startIndex, endIndex);
                else {
                    Token* newToken;
                    Token* invalidToken = new Token(TokenType::UNDEFINED, inputString.substr(0,1), lineNumber);
                    maxRead = 1;
                    newToken = invalidToken; // what is this invalid token?
                    tokens.push_back(newToken);
                }

                //update input

                //inputString = inputString.substr(maxRead);


                //inputRead.substr(startIndex, endIndex);
                //inputString = startIndex + inputString.size;
                //not sure if this is right?

                inputString.erase(0, maxRead);



            }

            //if(inputString.size() == 0) {
            Token* endOfFileToken = new Token(TokenType::E_O_F, inputString, lineNumber);
            tokens.push_back(endOfFileToken);

            //}
        }

        void Print();


};


#endif //PROJECT1_LEXER_LEXER_H