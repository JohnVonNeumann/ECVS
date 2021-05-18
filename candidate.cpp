//
//  main.cpp
//  SWE_Project
//
//  Created by Benedict Tivisini on 8/5/21.
//  Also edited by JVN

#include <iostream>
#include <cmath>

using namespace std;


// The candidate table needs to give a number for candidates
// My feeling is that ranking shouldn't be part of the struct as it
//      will increase the number of executions and be a PITA to deal with
struct candidate
{
    int id;                 // ID of candidate
    char name[30];          // Name of candidate
    int age;                // Age of candidate
    char gender[6];         // Gender of candidate (male/female/other)
    char electorate[20];    // Electorate (district/region)
    char party[30];         // Name of the candidate's party
    char logo[30];          // Description of party's symbol
    char officer[30];       // Registered officer of the party
    int count;              // Current number of votes for candidate
    int ranking;            // Ranking across candidates (1 being most votes)
};


// need more candidates and their details should be filled out
// regardless of how fucked the requirements are given the additional
// fields aren't even used
candidate Candidate_1 =
{
    "Candidate 1",              // name
    0,                          // age
    "",                         // gender
    "",                         // electorate
    "Australian Labor Party",   // party
    "ALP",                      // abbreviation
    "Text: 'Victorian Labour'", // logo
    "Mr Christopher Ford",      // officer
    0,                          // count
    0,                          // ranking
};

candidate Candidate_2 =
{
    
"Candidate 2",              // name
0,                          // age
"",                         // gender
"",                         // electorate
"Australian Labor Party",   // party
"ALP",                      // abbreviation
"Text: 'Victorian Labour'", // logo
"Mr Christopher Ford",      // officer
0,                          // count
0,                          // ranking
    
};



candidate  =
{
    
        // name
        // age
        // gender
        // electorate
        // party
        // abbreviation
        // logo
        // officer
        // count
        // ranking
    
};




int main()
{
    

    return 0;
}
