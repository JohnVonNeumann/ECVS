//
//  main.cpp
//  SWE_Project
//
//  Created by Benedict Tivisini on 8/5/21.
//  Also edited by JVN
//  Updated by Benedict Tivisini on 19/5/21. 
//  Updated by Benedict Tivisini on 22/5/21. 

#include <iostream>

using namespace std;


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



// SAMPLE CANDIDATE DATA:

CandidateInfo candidate[10] = {
    
    {1,"Candidate 1",48,"Male","Mulgrave","Australian Labor Party","ALP","Text: 'Victorian Labour'.","Mr Christopher Ford",2},
    
    {2,"Candidate 2",41,"Female","Kew","Democratic Labour Party (DLP)","Labour DLP","Text 'LABOUR DLP' surrounded by wheat.","Mr Joel Van Der Horst",4},
    
    {3,"Candidate 3",59,"Male","Altona","National Party of Australia – Victoria","The Nationals","Bold text 'THE NATIONALS' followed by softer text 'for Regional Victoria'.","Mr Matthew Harris",3},
    
    {4,"Candidate 4",55,"Female","Albert Park","Liberal Party of Australia – Victorian Division","Liberal","Australian flag above text 'LIBERAL'.","Mr Sam McQuestin",5},
    
    {5,"Candidate 5",33,"Male","Box Hill","Australian Labor Party","ALP","Text: 'Victorian Labour'.","Mr Christopher Ford",4},
    
    {6,"Candidate 6",37,"Female","Prahran","Liberal Party of Australia – Victorian Division","Liberal","Australian flag above text 'LIBERAL'.","Mr Sam McQuestin",8},
    
    {7,"Candidate 7",40,"Male","Burwood","Liberal Democratic Party","Liberal Democrats","Bold text 'LIBERAL DEMOCRATS'.","Mr Tim Quilty",1},
    
    {8,"Candidate 8",31,"Female","Hawthorn","The Australian Greens – Victoria","Australian Greens","Bold text 'THE GREENS' within a triangle.","Mr Martin Shield",7},
    
    {9,"Candidate 9",51,"Male","Ivanhoe","The Australian Greens – Victoria","Australian Greens","Bold text 'THE GREENS' within a triangle.","Mr Martin Shield",10},
    
    {10,"Candidate 10",46,"Female","Bundoora","Pauline Hanson’s One Nation","PHON","Text 'PAULINE HANSON'S one NATION' with emphasis on 'one'.","officer",50}
    
};

