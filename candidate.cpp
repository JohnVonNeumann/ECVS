//
//  main.cpp
//  SWE_Project
//
//  Created by Benedict Tivisini on 8/5/21.
//  Also edited by JVN
//  Updated by Benedict Tivisini on 19/5/21. 

#include <iostream>
#include <cmath>

using namespace std;


// The candidate table needs to give a number for candidates
// My feeling is that ranking shouldn't be part of the struct as it
//      will increase the number of executions and be a PITA to deal with


// CANDIDATE DATA STRUCTURE:
struct CandidateInfo
{
    string name;          // Name of candidate
    int age;                // Age of candidate
    string gender;         // Gender of candidate (male/female/other)
    string electorate;    // Electorate (district/region)
    string party;         // Name of the candidate's party
    string abbreviation;   // Abbreviated party name
    string logo;          // Description of party's symbol
    string officer;       // Registered officer of the party
    int count;              // Current number of votes for candidate
    int ranking;            // Ranking across candidates (1 being most votes)
};


// SAMPLE CANDIDATE DATA:
CandidateInfo candidate[10] = {
    
    {"Candidate 1",48,"Male","Mulgrave","Australian Labor Party","ALP","Text: 'Victorian Labour'.","Mr Christopher Ford",0,0},
    
    {"Candidate 2",41,"Female","Kew","Democratic Labour Party (DLP)","Labour DLP","Text 'LABOUR DLP' surrounded by wheat.","Mr Joel Van Der Horst",0,0},
    
    {"Candidate 3",59,"Male","Altona","National Party of Australia – Victoria","The Nationals","Bold text 'THE NATIONALS' followed by softer text 'for Regional Victoria'.","Mr Matthew Harris",0,0},
    
    {"Candidate 4",55,"Female","Albert Park","Liberal Party of Australia – Victorian Division","Liberal","Australian flag above text 'LIBERAL'.","Mr Sam McQuestin",0,0},
    
    {"Candidate 5",33,"Male","Box Hill","Australian Labor Party","ALP","Text: 'Victorian Labour'.","Mr Christopher Ford",0,0},
    
    {"Candidate 6",37,"Female","Prahran","Liberal Party of Australia – Victorian Division","Liberal","Australian flag above text 'LIBERAL'.","Mr Sam McQuestin",0,0},
    
    {"Candidate 7",40,"Male","Burwood","Liberal Democratic Party","Liberal Democrats","Bold text 'LIBERAL DEMOCRATS'.","Mr Tim Quilty",0,0},
    
    {"Candidate 8",31,"Female","Hawthorn","The Australian Greens – Victoria","Australian Greens","Bold text 'THE GREENS' within a triangle.","Mr Martin Shield",0,0},
    
    {"Candidate 9",51,"Male","Ivanhoe","The Australian Greens – Victoria","Australian Greens","Bold text 'THE GREENS' within a triangle.","Mr Martin Shield",0,0},
    
    {"Candidate 10",46,"Female","Bundoora","Pauline Hanson’s One Nation","PHON","Text 'PAULINE HANSON'S one NATION' with emphasis on 'one'.","officer",0,0}
    
};



int main()
{
    

    return 0;
}
