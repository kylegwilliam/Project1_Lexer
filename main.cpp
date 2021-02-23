#include <iostream>
#include "Lexer.h"
#include "Token.h"
#include "Parser.h"
#include "MatcherAutomaton.h"
//#include "Automaton.h"
#include <fstream>


//Should verify commandline arguments, instantiate instance of the Lexer class, and pass the input to Lexer
//and let it run. For this project, your main will then need to get the Tokens from the
//Lexer and print them out in a specified format (so the pass-off driver can check it
//for correctness). At the end, your main function should perform any clean up (e.g.
//de-allocation of memory).

int main(int argc, char* argv[]) {

    string answerString;
    char c;

    ifstream infile;
    infile.open(argv[1]);

    if(infile.fail()) {
        cout << "Your file didn't work." << endl;
    }
    else{

        while(!infile.eof()) {

            while(infile.get(c)) {
                answerString.push_back(c);
            }
        }

        //string tb;
        //while(getline(infile, tb)) {
        //    cout << tb << endl;
        //}





        infile.close();
        //EOF
        //cout << answerString << endl;
    }


    Lexer lexer;
    lexer.Run(answerString);
    //lexer.Print();

    lexer.RemoveCommentToken();
    vector<Token*> newTokens;
    newTokens = lexer.getTokens();

    /// loop throught newTokens vector and remove COMMENTS from the vector

    Parser parse(newTokens);

    parse.Parse();


    ///try
    ///Run
    ///catch


    return 0;

};
