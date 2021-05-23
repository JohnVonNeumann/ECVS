//
// Created by jvn on 18/5/21.
//
#include <fstream>
#include "voter.h"

using namespace std;

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

voter_t voter_1 {
        1,
        "Frank Litz",
        21,
        "Frankston",
        "23/12/56",
        0,
        "Nowhereville",
        false,
        100000,
        false
};

voter_t voter_2 {
        2,
        "Sally Jones",
        56,
        "Dromana",
        "03/11/94",
        0,
        "Somewhereville",
        true,
        31337,
        true
};

voter_t voter_3 {
        3,
        "John Limpton",
        34,
        "Richmond",
        "11/04/29",
        0,
        "Whoknowsville",
        true,
        100000000,
        true
};

voter_t voter_4 {
        4,
        "Candy Lothestosock",
        42,
        "Glenelg",
        "18/07/98",
        0,
        "Notsureville",
        true,
        46578,
        false
};

voter_t voter_5 {
        5,
        "Bill Bobs",
        99,
        "Kew",
        "01/01/11",
        0,
        "Whocaresville",
        true,
        3,
        true
};

voter_t voter_6 {
        6,
        "Chloe Kloggs",
        32,
        "Burnley",
        "18/09/12",
        0,
        "Runningoutoffunnyplacesville",
        false,
        467689,
        false
};

voter_t voter_7 {
        7,
        "Jarrad Plops",
        56,
        "Surrey Hills",
        "15/06/15",
        0,
        "Honestlydonewiththisville",
        true,
        21378,
        false
};

voter_t voter_8 {
        8,
        "Jake Paul",
        12,
        "Carrum Downs",
        "17/11/24",
        0,
        "Whatville",
        false,
        0,
        false
};

voter_t voter_9 {
        9,
        "Sally Browsn",
        71,
        "Seaford",
        "12/10/13",
        0,
        "Wotville",
        true,
        100,
        true
};

voter_t voter_10 {
        10,
        "Lorne Malvo",
        100,
        "Kensington",
        "04/03/02",
        0,
        "Lastoneville",
        false,
        90000,
        true
};

voter_t voter[10] = {
        voter_1,
        voter_2,
        voter_3,
        voter_4,
        voter_5,
        voter_6,
        voter_7,
        voter_8,
        voter_9,
        voter_10
};