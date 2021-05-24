#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>

#include "voter.h"
#include "candidate.h"

using namespace std;

/*
 * Present menu to user
 * If selection P:
 *      print a formatted list of all candidates alongside their candidate id
 *      print prompt and ask for a candidate id
 *      find the candidate struct with the correct candidate id
 *      print the candidate.count struct field
 *
 * If selection A:
 *      Print and ask for a voter id
 *      once input
 *      print and ask for a candidate id
 *      assign the candidate_id choice to the voter.selection struct field
 *      increment the count of the candidate.count struct field
 *
 * If selection S:
 *      all i can think of is over-complicated inefficient solutions
 *
 * If selection L:
 *      all i can think of is over-complicated inefficient solutions
 */

/*
 * Voter/Candidate Input/Output
 * Simplest solution is to not do inplace edits, just overwrite the entire file each time a change is made,
 * slow yes, but effective for what this assignment requires.
 *
 * Create separate config files for Voter and Candidate to reduce requirements for polymorphic record format handling
 * - a read file function for voter
 * - a write file function for voter
 * - a read file function for candidate
 * - a write file function for candidate
 *
 * test the write file function for both using the pre existing voter/candidate arrays
 *
 * still use the voter/candidate arrays, but the read file will load the entities in, so we shouldnt have to change
 * the core of the application
 *
 * pretty much just generating the structs dynamically as opposed to statically in the code
 *
 */

// Function Prototypes
char menu();
void print_candidate_numbers();
void add_votes_to_candidate();
void display_lowest_voted_candidate();
void display_highest_voted_candidate();
void write_voters_to_file();
void write_candidates_to_file();
void read_voters_from_file();
void read_candidates_from_file();
void welcome_banner();
void print_help();

const string VOTER_FILE = "voter.txt";
const string CANDIDATE_FILE = "candidate.txt";

int main()
{
    welcome_banner();
    read_voters_from_file();
    read_candidates_from_file();
	while (true)
	{
		char choice;
		choice = menu();

		switch (choice)
		{
		    case 'P':
		        print_candidate_numbers();
                break;
            case 'A':
                add_votes_to_candidate();
                break;
            case 'S':
                display_lowest_voted_candidate();
                break;
            case 'L':
                display_highest_voted_candidate();
                break;
            case 'Q':
                write_voters_to_file();
                write_candidates_to_file();
                exit(0);
            default:
                menu();
		}
	}
}

void write_voters_to_file()
{
    ofstream file;
    // truncate to simplify the implementation
    file.open(VOTER_FILE, ios::trunc);
    for (int i = 0; i < 10; ++i) {
        voter_t v = voters[i];
        file << v.voter_id << " " << v.name << " " << v.age << " "
                << v.suburb << " " << v.date_of_birth << " " << v.candidate_selection << " "
                << v.electorate << " " << v.previously_voted << " " << v.salary << " " << v.retired << endl;
    }
}

void write_candidates_to_file()
{
    ofstream file;
    // truncate to simplify the implementation
    file.open(CANDIDATE_FILE, ios::trunc);
    for (int i = 0; i < 10; ++i) {
        candidate_t c = candidates[i];
        file << c.id << " " << c.name << " " << c.age << " "
             << c.gender << " " << c.electorate << " " << c.party << " "
             << c.abbreviation << " " << c.political_position << " " << c.officer << " " << c.count << endl;
    }
}

void read_voters_from_file() {
    string line;
    string element;

    ifstream file(VOTER_FILE);

    if (file.is_open()) {
        while (getline(file, line)) {
            vector<string> elements;
            istringstream iss(line);
            for (string line; iss >> line;) {
                elements.push_back(line);
            }

            voter_t v;
            v.voter_id = stoi(elements[0]);
            v.name = elements[1];
            v.age = stoi(elements[2]);
            v.suburb = elements[3];
            v.date_of_birth = elements[4];
            v.candidate_selection = stoi(elements[5]);
            v.electorate = elements[6];
            v.previously_voted = elements[7];
            v.salary = stoi(elements[8]);
            v.retired = elements[9];

            voters.push_back(v);
        }
    }
}

void read_candidates_from_file() {
    string line;
    string element;

    ifstream file(CANDIDATE_FILE);

    if (file.is_open()) {
        while (getline(file, line)) {
            vector<string> elements;
            istringstream iss(line);
            for (string line; iss >> line;) {
                elements.push_back(line);
            }

            candidate_t c;
            c.id = stoi(elements[0]);
            c.name = elements[1];
            c.age = stoi(elements[2]);
            c.gender = elements[3];
            c.electorate = elements[4];
            c.party = elements[5];
            c.abbreviation = elements[6];
            c.political_position = elements[7];
            c.officer = elements[8];
            c.count = stoi(elements[9]);

            candidates.push_back(c);
        }
    }
}
void print_candidate_numbers()
{
	int choice;

	cout << "Enter candidate ID: " << endl;
	cin >> choice;
	while (choice < 1 || choice > 10)
	{
	    cout << "Please enter a candidate ID between 1 and 10: " << endl;
	    cin >> choice;
	}
	cout << "Candidate " << candidates[choice - 1].id << " - " << candidates[choice - 1].name << " has " << candidates[choice - 1].count << " votes" << endl;
}

void add_votes_to_candidate()
{
	int votchoice, canchoice;

	cout << "Enter voter ID: " << endl;
	cin >> votchoice;

	while (votchoice > 10 || votchoice < 0)
	{
		cout << "Enter voter ID: " << endl;
		cin >> votchoice;
	}

	cout << "Enter candidate ID: " << endl;
	cin >> canchoice;

	while (canchoice > 10 || canchoice < 0)
	{
		cout << "Enter candidate ID: " << endl;
		cin >> canchoice;
	}

	voters[votchoice - 1].candidate_selection = canchoice;
	candidates[canchoice - 1].count += 1;
	cout << candidates[canchoice - 1].id << ". " << candidates[canchoice - 1].name << " now has " << candidates[canchoice - 1].count << " votes " << endl;
}


void display_lowest_voted_candidate()
{
	int index;
	int temp = candidates[0].count;
	for (int i = 0; i < 10; i++)
	{
		if (temp > candidates[i].count)
		{
			temp = candidates[i].count;
			index = i;
		}
	}

	// ugly hack solution for dealing with ties, could probably deal with this in
	// the loop one level higher but we're close to submission
	// FUTURE WORK: create more efficient logic
	for (int i = 0; i < 10; i++) {
	    if (temp == candidates[i].count) {
            cout << "The lowest amount of votes is Candidate " << candidates[i].id << ". " << candidates[i].name << " with " << candidates[i].count
                 << " votes" << endl << endl;
        }
	}
}


void display_highest_voted_candidate()
{
	int large, i, index;
	large = candidates[0].count;
	for (i = 1; i < 10; i++) {
		if (candidates[i].count > large) {
			large = candidates[i].count;
			index = i;
		}
	}

    // ugly hack solution for dealing with ties, could probably deal with this in
    // the loop one level higher but we're close to submission
    // FUTURE WORK: create more efficient logic
    for (int i = 0; i < 10; i++) {
        if (large == candidates[i].count) {
            cout << "The highest amount of votes is Candidate " << candidates[i].id << ". "<< candidates[i].name << " with " << candidates[i].count
                 << " votes" << endl;
        }
    }
}

void print_help() {
    cout << "Main menu:" << endl << "Please choose from the following" << endl;
    cout << "P - Display information on certain candidate" << endl;
    cout << "A - Add votes to candidate" << endl;
    cout << "S - Display candidate with smallest amount of votes" << endl;
    cout << "L - Display candidate with largest number of votes" << endl;
    cout << "Q - Quit" << endl << endl;
}

void welcome_banner() {
    cout << " ______ _______      _______ " << endl;
    cout << "|  ____/ ____\\ \\    / / ____|" << endl;
    cout << "| |__ | |     \\ \\  / / (___  " << endl;
    cout << "|  __|| |      \\ \\/ / \\___ \\ " << endl;
    cout << "| |___| |____   \\  /  ____) |" << endl;
    cout << "|______\\_____|   \\/  |_____/ " << endl;
}

char menu()
{
	char choice;
	print_help();
    cin >> choice;
    choice = toupper(choice);
    cout << endl;

    while (choice != 'P' && choice != 'A' && choice != 'S' && choice != 'L' && choice != 'Q')
    {
        cout << "Unknown Selection, Please Try Again" << endl;
        print_help();
        cin >> choice;
        cout << endl << endl;
     }

	return choice;
}