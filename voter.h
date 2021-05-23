//
// Created by lw on 23/5/21.
//

#include <fstream>

using namespace std;

#ifndef ECVS_VOTER_H
#define ECVS_VOTER_H

struct voter_t {
    int voter_id;
    string name;
    int age;
    string suburb;
    string date_of_birth;
    int candidate_selection;
    string electorate;
    bool previously_voted;
    int salary;
    bool retired;
};

extern voter_t voter[10];

#endif //ECVS_VOTER_H
