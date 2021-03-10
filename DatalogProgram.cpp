//
// Created by Kyle Gwilliam on 2/19/21.
//

#include "DatalogProgram.h"
using namespace std;

DatalogProgram::DatalogProgram() {

}



void DatalogProgram::toString() {

    //cout << "Success!" << endl;
    cout << "Schemes(" << scheme.size() << "):" << endl;

    for (unsigned int i = 0; i < scheme.size(); i++) {
        cout << "  " << scheme.at(i)->toString() << endl;
    }

    cout << "Facts(" << facts.size() << "):" << endl;

    for (unsigned int i = 0; i < facts.size(); i++) {
        cout << "  " << facts.at(i)->toStringFacts() << endl;
        for (unsigned int j = 0; j < facts.at(i)->getPredicateListOfParameters().size(); j++) {
            domainSet.insert(facts.at(i)->getPredicateListOfParameters().at(j)->toString());
        }
    }

    cout << "Rules(" << rule.size() << "):" << endl;

    for (unsigned int i = 0; i < rule.size(); i++) {
        cout << "  " << rule.at(i)->toString() << endl;
    }

    cout << "Queries(" << query.size() << "):" << endl;

    for (unsigned int i = 0; i < query.size(); i++) {
        cout << "  " << query.at(i)->toStringQuery() << endl;
    }

    cout << "Domain(" << domainSet.size() << "):"<< endl;
    for (auto itr = domainSet.begin(); itr != domainSet.end(); itr++) {
        cout << "  " <<*itr<<endl;
    }

}
