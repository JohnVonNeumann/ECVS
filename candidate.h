//
// Created by lw on 23/5/21.
//
#include <iostream>

using namespace std;

#ifndef ECVS_CANDIDATE_H
#define ECVS_CANDIDATE_H

// CANDIDATE DATA STRUCTURE:

struct CandidateInfo
{
    int id;            // Candidate Number
    string name;          // Name of candidate
    int age;                // Age of candidate
    string gender;         // Gender of candidate (male/female/other)
    string electorate;    // Electorate (district/region)
    string party;         // Name of the candidate's party
    string abbreviation;   // Abbreviated party name
    string logo;          // Description of party's symbol
    string officer;       // Registered officer of the party
    int count;              // Current number of votes for candidate
};

extern CandidateInfo candidate[10];

#endif //ECVS_CANDIDATE_H
