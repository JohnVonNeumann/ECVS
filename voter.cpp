//
// Created by jvn on 18/5/21.
//
#include <fstream>

using namespace std;

struct voter_t {
    int voter_id;
    string name;
    int age;
    string suburb;
    char electorate[20];
    int candidate_selection;
};