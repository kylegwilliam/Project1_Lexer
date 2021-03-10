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
        cout << "  ";
        error->outputString();
        exit(0);
    }

    cout << "Success!" << endl;


}

//

void Parser::datalogProgram() {
    ///SCHEMES COLON scheme schemeList FACTS COLON factList RULES COLON ruleList QUERIES COLON query queryList EOF

    ///create the 4 vectors.

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

void Parser::scheme() {
    ///ID LEFT_PAREN ID idList RIGHT_PAREN
    //cout << "scheme" << endl;

    Predicate* temp = new Predicate;

    if (tokens.at(locationToken) -> type == ID) {
        MatchFunction(ID);
        //namepredicate = ID; setter function. make setter function;
        temp->setPredicateID(tokens.at(locationToken-1) -> outputValue());

        MatchFunction(LEFT_PAREN);
        MatchFunction(ID);
        //pass in vector of parameters. Pass vector to idList. Set to predicate.
        /// decalre new vectors of parameters and pass them into the IDLIST FUNCTION. by reference. (use &)
        vector <Parameter*> predicateList;
        string newString = tokens.at(locationToken - 1) -> outputValue();
        //cout << newString << " - new string" << endl;
        Parameter* listElement = new simpleParameter(newString);
        //cout << listElement << "- list element" << endl;
        predicateList.push_back(listElement);

        /// go into id list and do a simialr thing as above
        /// add to preicateList inside of my idList. pass by reference. &predicateList
        idList(predicateList);
        //make setter function to make vector of parameters
        temp->setPredicateListOfParameters(predicateList);

        MatchFunction(RIGHT_PAREN);

        /// push-back temp predicate onto scheme vector on DatalogProgram.
        finalOutput.setScheme(temp);
        ///Saying temp is a predicate but i want it to be a predicate*

        //return temp -> toString();
    }
    else {
        throw tokens.at(locationToken);
    }

}
/// LOOK AT IF STATEMENT
void Parser::fact() {
    ///ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD

    Predicate* temp = new Predicate;

    if (tokens.at(locationToken) -> type == ID) {
        MatchFunction(ID);
        temp->setPredicateID(tokens.at(locationToken-1) -> outputValue());

        MatchFunction(LEFT_PAREN);
        MatchFunction(STRING);
        vector <Parameter*> groupsOfString;
        string newString = tokens.at(locationToken - 1) -> outputValue();
        //cout << newString << " newString" << endl;
        Parameter* factElement = new simpleParameter(newString);
        //cout << factElement << " - factElement";
        groupsOfString.push_back(factElement);

        //
        stringList(groupsOfString);

        temp->setPredicateListOfParameters(groupsOfString);
        MatchFunction(RIGHT_PAREN);
        MatchFunction(PERIOD);

        //for (unsigned int i = 0; i < groupsOfString.size(); i++) {
        //    cout << groupsOfString.at(i) << endl;
        //}

        ///
        finalOutput.setFacts(temp);
        ///wants a predicate pointer and temp is a predicate
        //return temp -> toStringFacts();
    }
    else {
        throw tokens.at(locationToken);
    }


}

void Parser::rule() {
    ///headPredicate COLON_DASH predicate predicateList PERIOD
    //cout << "rule" << endl;

    Rule* temp = new Rule;

    Predicate* pred = new Predicate;
    vector <Predicate*> newVectPred;
    //headPredicate();
    temp->headPredicateFunction(headPredicate());

    MatchFunction(COLON_DASH);
    //temp.body pred function.


    predicate(*pred);
    newVectPred.push_back(pred);
    predicateList(newVectPred);

    temp->bodyPredicateFunction(newVectPred);


    MatchFunction(PERIOD);

    ///
    finalOutput.setRule(temp);
    ///

    //return temp->toString();

}

void Parser::query()  {
    ///predicate Q_MARK
    //cout << "query" << endl;
    ///not sure if i need it here or not.

    Predicate* temp = new Predicate;

    //vector <Parameter*> queryOrRuleList;


    predicate(*temp);
    MatchFunction(Q_MARK);


    //temp.setPredicateListOfParameters(queryOrRuleList);

    ///
    finalOutput.setQuery(temp);
    ///Predicate instead of Predicate*
    //return temp->toStringQuery();

    //setPredicateListOfParameters(queryOrRuleList);

    //return temp.toString();

}


Predicate* Parser::headPredicate() {
    ///ID LEFT_PAREN ID idList RIGHT_PAREN
    //cout << "headPredicate" << endl;

    Predicate* temp = new Predicate;

    if (tokens.at(locationToken) -> type == ID) {
        //vector<Parameter*> newVector;
        MatchFunction(ID);

        temp->setPredicateID(tokens.at(locationToken-1) -> outputValue());


        MatchFunction(LEFT_PAREN);
        MatchFunction(ID);

        vector <Parameter*> newParameters;
        string newString = tokens.at(locationToken-1) -> outputValue();
        Parameter* newElements = new simpleParameter(newString);
        newParameters.push_back(newElements);

        idList(newParameters);
        MatchFunction(RIGHT_PAREN);

        temp->setPredicateListOfParameters(newParameters);

        return temp;

    }
    else {
        throw tokens.at(locationToken);
    }


}

void Parser::predicate(Predicate& newPred) {
    ///ID LEFT_PAREN parameter parameterList RIGHT_PAREN
    //cout << "predicate" << endl;


    vector <Parameter*> queryOrRuleList;

    if (tokens.at(locationToken) -> type == ID) {
        MatchFunction(ID);

        newPred.setPredicateID(tokens.at(locationToken - 1) -> outputValue());

        MatchFunction(LEFT_PAREN);
        parameter(queryOrRuleList);
        parameterList(queryOrRuleList);

        newPred.setPredicateListOfParameters(queryOrRuleList);

        //newVectPred.push_back(temp);

        MatchFunction(RIGHT_PAREN);

    }
    else {
        throw tokens.at(locationToken);
    }


}

void Parser::predicateList(vector <Predicate*>& newVectPred) {
    ///COMMA predicate predicateList | lambda
    //cout << "predicateList" << endl;

    Predicate* temp = new Predicate;
    vector <Parameter*> queryOrRuleList;

    if (tokens.at(locationToken) -> type == COMMA) {
        MatchFunction(COMMA);
        predicate(*temp);
        newVectPred.push_back(temp);
        predicateList(newVectPred);

    }
    else{}

}

void Parser::parameterList(vector <Parameter*>& queryOrRuleList) {
    ///COMMA parameter parameterList | lambda
    //cout << "parameterList" << endl;
    if (tokens.at(locationToken) -> type == COMMA) {
        MatchFunction(COMMA);
        parameter(queryOrRuleList);
        parameterList(queryOrRuleList);
    }
    else{}

}

void Parser::stringList(vector <Parameter*>& groupsOfString) {
    ///COMMA STRING stringList | lambda
    //cout << "stringList" << endl;
    if (tokens.at(locationToken) -> type == COMMA) {
        MatchFunction(COMMA);
        MatchFunction(STRING);
        string factString = tokens.at(locationToken - 1) -> outputValue();
        //
        //cout << factString << "fact" << endl;

        Parameter* newFacts = new simpleParameter(factString);
        groupsOfString.push_back(newFacts);

        stringList(groupsOfString);
    }
    else{}

}

void Parser::idList(vector<Parameter*>& predicateList) {
    ///COMMA ID idList | lambda
    //cout << "idList" << endl;
    if (tokens.at(locationToken) -> type == COMMA) {
        MatchFunction(COMMA);
        MatchFunction(ID);
        string insideParen = tokens.at(locationToken - 1) -> outputValue();
        //cout << insideParen << " - insideParen" << endl;

        Parameter* newElements = new simpleParameter(insideParen);
        predicateList.push_back(newElements);
        //cout << newElements << " - NewElements" << endl;

        idList(predicateList);
    }
    else{}

}

//

Parameter* Parser::parameter(vector <Parameter*>& queryOrRuleList) {
    ///STRING | ID | expression
    //cout << "parameter" << endl;
    if (tokens.at(locationToken)-> type == STRING) {
        MatchFunction(STRING);
        string newQuery = tokens.at(locationToken - 1) -> outputValue();
        Parameter* queryElement = new simpleParameter(newQuery);

        queryOrRuleList.push_back(queryElement);

        return queryElement;

    }
    else if (tokens.at(locationToken) -> type == ID) {
        MatchFunction(ID);
        string newQuery = tokens.at(locationToken - 1) -> outputValue();
        Parameter* queryElement = new simpleParameter(newQuery);

        queryOrRuleList.push_back(queryElement);

        return queryElement;

    }
    else if (tokens.at(locationToken) -> type == LEFT_PAREN) {

        //expression(queryOrRuleList);
        return expression(queryOrRuleList);
    }
    else{
        throw tokens.at(locationToken);
    }



}

Parameter* Parser::expression(vector <Parameter*>& queryOrRuleList) {
    ///LEFT_PAREN parameter operator parameter RIGHT_PAREN
    //cout << "expression" << endl;

    Parameter* temp = new newExpression;


    if (tokens.at(locationToken) -> type == LEFT_PAREN) {
        MatchFunction(LEFT_PAREN);
        temp->setParam(parameter(queryOrRuleList));
        queryOrRuleList.pop_back();
        temp->setOpp(operator1(queryOrRuleList));
        temp->setParam(parameter(queryOrRuleList));
        queryOrRuleList.pop_back();
        MatchFunction(RIGHT_PAREN);


        queryOrRuleList.push_back(temp);

    }
    else {
        tokens.at(locationToken);
    }

    return temp;

}

string Parser::operator1(vector <Parameter*>& queryOrRuleList) {
    ///ADD | MULTIPLY
    //cout << "operator1" << endl;
    if (tokens.at(locationToken) -> type == ADD) {
        MatchFunction(ADD);

        return "+";

    }
    else if (tokens.at(locationToken) -> type == MULTIPLY) {
        MatchFunction(MULTIPLY);

        return "*";
    }
    else{
        throw tokens.at(locationToken);
    }


}


Parser::Parser(vector<Token *> tokens) {
    this->tokens = tokens;
}

DatalogProgram Parser::getFinalOutput() {
    return finalOutput;
}

