//
// Created by Kyle Gwilliam on 2/11/21.
//

#include "Parser.h"


void Parser::MatchFunction(TokenType type) {

    if (tokens.at(locationToken) -> type == type) {
        locationToken += 1;
    }
    else {
        throw tokens.at(locationToken);
    }


    //pass in token type
    //match will compare token type to the index (locationToken)

}

void Parser::Parse() {
    /// This one should just call the datalogProgram function and get things started!
    /// Try-catch block. 8:41 video
    /// the Try calls the parse function. Print out information of bad token and where.



    try {

        datalogProgram();
    }
    catch (Token* error) {
        cout << "Failure!" << endl;
        error->outputString();
        exit(0);
    }

    cout << "Success!" << endl;


}

//

void Parser::datalogProgram() {
    ///SCHEMES COLON scheme schemeList FACTS COLON factList RULES COLON ruleList QUERIES COLON query queryList EOF
    MatchFunction(SCHEMES);
    MatchFunction(COLON);
    scheme();
    schemeList();
    MatchFunction(FACTS);
    MatchFunction(COLON);
    factList();
    MatchFunction(RULES);
    MatchFunction(COLON);
    ruleList();
    MatchFunction(QUERIES);
    MatchFunction(COLON);
    query();
    queryList();
    MatchFunction(E_O_F);


}
//have an index variable in the private member. What index im at in that vector.
//

void Parser::schemeList() {
    ///scheme schemeList | lambda
    //cout << "schemeList" << endl;
    if (tokens.at(locationToken) -> type == ID) {
        scheme();
        schemeList();
    }
    else {}

}

void Parser::factList() {
    ///fact factList | lambda
    //cout << "factList" << endl;
    if (tokens.at(locationToken) -> type == ID) {
        fact();
        factList();
    }
    else {}

}

void Parser::ruleList() {
    ///rule ruleList | lambda
    //cout << "ruleList" << endl;
    if (tokens.at(locationToken) -> type == ID) {
        rule();
        ruleList();
    }
    else{}

}

void Parser::queryList() {
    ///query queryList | lambda
    //cout << "schemeList" << endl;
    if (tokens.at(locationToken) -> type == ID) {
        query();
        queryList();
    }
    else{};

}

string Parser::scheme() {
    ///ID LEFT_PAREN ID idList RIGHT_PAREN
    //cout << "scheme" << endl;

    Predicate temp;

    if (tokens.at(locationToken) -> type == ID) {
        MatchFunction(ID);
        //namepredicate = ID; setter function. make setter function;
        temp.setPredicateID(tokens.at(locationToken-1) -> outputValue());

        MatchFunction(LEFT_PAREN);
        MatchFunction(ID);
        //pass in vector of parameters. Pass vector to idList. Set to predicate.
        /// decalre new vectors of parameters and pass them into the IDLIST FUNCTION. by reference. (use &)
        vector <Parameter*> predicateList;
        string newString = tokens.at(locationToken - 1) -> outputValue();
        Parameter* listElement = new Parameter(newString);
        predicateList.push_back(listElement);

        /// go into id list and do a simialr thing as above
        idList();
        //make setter function to make vector of parameters
        temp.setPredicateListOfParameters(predicateList);

        MatchFunction(RIGHT_PAREN);

        return temp.toString();
    }
    else {
        throw tokens.at(locationToken);
    }

}
/// LOOK AT IF STATEMENT
void Parser::fact() {
    ///ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
    //cout << "fact" << endl;
    if (tokens.at(locationToken) -> type == ID) {
        MatchFunction(ID);
        MatchFunction(LEFT_PAREN);
        MatchFunction(STRING);
        stringList();
        MatchFunction(RIGHT_PAREN);
        MatchFunction(PERIOD);
    }
    else {
        throw tokens.at(locationToken);
    }


}

void Parser::rule() {
    ///headPredicate COLON_DASH predicate predicateList PERIOD
    //cout << "rule" << endl;
    headPredicate();
    MatchFunction(COLON_DASH);
    predicate();
    predicateList();
    MatchFunction(PERIOD);


}

void Parser::query() {
    ///predicate Q_MARK
    //cout << "query" << endl;
    predicate();
    MatchFunction(Q_MARK);


}


void Parser::headPredicate() {
    ///ID LEFT_PAREN ID idList RIGHT_PAREN
    //cout << "headPredicate" << endl;
    if (tokens.at(locationToken) -> type == ID) {
        MatchFunction(ID);
        MatchFunction(LEFT_PAREN);
        MatchFunction(ID);
        idList();
        MatchFunction(RIGHT_PAREN);
    }
    else {
        throw tokens.at(locationToken);
    }


}

void Parser::predicate() {
    ///ID LEFT_PAREN parameter parameterList RIGHT_PAREN
    //cout << "predicate" << endl;
    if (tokens.at(locationToken) -> type == ID) {
        MatchFunction(ID);
        MatchFunction(LEFT_PAREN);
        parameter();
        parameterList();
        MatchFunction(RIGHT_PAREN);
    }
    else {
        throw tokens.at(locationToken);
    }

}

void Parser::predicateList() {
    ///COMMA predicate predicateList | lambda
    //cout << "predicateList" << endl;
    if (tokens.at(locationToken) -> type == COMMA) {
        MatchFunction(COMMA);
        predicate();
        predicateList();
    }
    else{}

}

void Parser::parameterList() {
    ///COMMA parameter parameterList | lambda
    //cout << "parameterList" << endl;
    if (tokens.at(locationToken) -> type == COMMA) {
        MatchFunction(COMMA);
        parameter();
        parameterList();
    }
    else{}

}

void Parser::stringList() {
    ///COMMA STRING stringList | lambda
    //cout << "stringList" << endl;
    if (tokens.at(locationToken) -> type == COMMA) {
        MatchFunction(COMMA);
        MatchFunction(STRING);
        stringList();
    }
    else{}

}

void Parser::idList() {
    ///COMMA ID idList | lambda
    //cout << "idList" << endl;
    if (tokens.at(locationToken) -> type == COMMA) {
        MatchFunction(COMMA);
        MatchFunction(ID);
        idList();
    }
    else{}

}

//

void Parser::parameter() {
    ///STRING | ID | expression
    //cout << "parameter" << endl;
    if (tokens.at(locationToken)-> type == STRING) {
        MatchFunction(STRING);
    }
    else if (tokens.at(locationToken) -> type == ID) {
        MatchFunction(ID);
    }
    else if (tokens.at(locationToken) -> type == LEFT_PAREN) {
        expression();
    }
    else{
        throw tokens.at(locationToken);
    }

}

void Parser::expression() {
    ///LEFT_PAREN parameter operator parameter RIGHT_PAREN
    //cout << "expression" << endl;
    if (tokens.at(locationToken) -> type == LEFT_PAREN) {
        MatchFunction(LEFT_PAREN);
        parameter();
        operator1();
        parameter();
        MatchFunction(RIGHT_PAREN);
    }
    else {
        tokens.at(locationToken);
    }

}

void Parser::operator1() {
    ///ADD | MULTIPLY
    //cout << "operator1" << endl;
    if (tokens.at(locationToken) -> type == ADD) {
        MatchFunction(ADD);
    }
    else if (tokens.at(locationToken) -> type == MULTIPLY) {
        MatchFunction(MULTIPLY);
    }
    else{
        throw tokens.at(locationToken);
    }


}


Parser::Parser(vector<Token *> tokens) {
    this->tokens = tokens;
}

