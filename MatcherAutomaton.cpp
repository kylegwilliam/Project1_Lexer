//
// Created by Kyle Gwilliam on 2/3/21.
//

#include "MatcherAutomaton.h"

int MatcherAutomaton::Start(const std::string& input) {

    bool isMatch = true;
    inputRead = 0; // member variable inherited from Automaton class
    for (int i = 0; i < (int)toMatch.size() && isMatch; i++) {
        if (input[i] != toMatch[i]) {
            isMatch = false;
        }
    }
    if (isMatch) {
        inputRead = toMatch.size();
    }
    return inputRead;

}

int StringAutomaton::Start(const std:: string& input) {

    int stringPlacement = 0;
    newLines = 0;
    if (input.size() == 0) {
        return 0;
    }

    if (input.at(0) == '\'') {

        stringPlacement += 1;

        for (unsigned int i = 1; i < input.size(); i++) {


            //stringPlacement += 1;

            if (input.at(i) == '\'') {
                stringPlacement += 1;

                if (i == input.size() - 1) {
                    stringPlacement += 1;
                    return stringPlacement;
                }

                if (input.at(i + 1) == '\'') {
                    i++;
                    stringPlacement += 1;
                } else {
                    //stringPlacement += 1;
                    return stringPlacement;
                }
            }
            else {
                stringPlacement += 1;
                if (input.at(i) == '\n'){
                    newLines++;
                }
            }
        }
    }

    else {
        return 0;

    }
    

    this->type = UNDEFINED;
    return stringPlacement;


}




int CommentAutomaton::Start(const std::string &input) {

    int CommentSize = 0;

    if (input.size() == 0) {
        return 0;
    }
    newLines = 0;
    if (input.at(0) == '#') {

        if (input.at(1) != '|') {
            for (unsigned int i = 0; i < input.size(); i++) {

                if (input.at(i) == EOF || input.at(i) == '\n') {
                    //newLines++;
                    return CommentSize;
                }
                CommentSize += 1;
            }
        }

        else {
            for (unsigned int i = 0; i < input.size(); i++) {
                //CommentSize += 1;

                if (input.at(i) == '|' && input.at(i + 1) == '#') {
                    CommentSize = CommentSize + 2;
                    return CommentSize;
                }
                else {
                    if (input.at(i) == '\n') {
                        newLines++;
                    }
                    CommentSize += 1;;
                }
            }
        }
    }

    else {
        return 0;
    }

    this->type = UNDEFINED;
    return CommentSize;
}

int IDAutomaton::Start(const std::string &input) {

    int IDSize = 0;
    string keyWord;

    if (input.size() == 0) {
        return 0;
    }

    if (isalpha(input.at(0))) {


        for (unsigned int i = 0; i < input.size(); i++) {
            if (isalnum(input.at(i))) {
                IDSize += 1;
                keyWord.push_back(input.at(i));
            }
            else{
                if (keyWord == "Schemes" || keyWord == "Facts" || keyWord == "Rules" || keyWord == "Queries") {
                    return 0;
                }

                return IDSize;
            }
        }

        if (keyWord == "Schemes" || keyWord == "Facts" || keyWord == "Rules" || keyWord == "Queries") {
            return 0;

        }

        else {
            return IDSize;
        }
    }

    else {
        return 0;
    }


}

