#include <iostream>
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

// Function Prototypes
char menu();
void print_candidate_numbers();
void add_votes_to_candidate();
void display_lowest_voted_candidate();
void display_highest_voted_candidate();
void welcome_banner();
void print_help();

int main()
{
    welcome_banner();
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
                exit(0);
            default:
                menu();
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
	cout << "Candidate " << candidate[choice - 1].id << " - " << candidate[choice - 1].name << " has " << candidate[choice - 1].count << " votes" << endl;
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

	voter[votchoice - 1].candidate_selection = canchoice;
	candidate[canchoice - 1].count += 1;
	cout << candidate[canchoice - 1].name << " now has " << candidate[canchoice - 1].count << " votes " << endl;
}


void display_lowest_voted_candidate()
{
	int index;
	int temp = candidate[0].count;
	for (int i = 0; i < 10; i++)
	{
		if (temp > candidate[i].count)
		{
			temp = candidate[i].count;
			index = i;
		}
	}

	// ugly hack solution for dealing with ties, could probably deal with this in
	// the loop one level higher but we're close to submission
	// FUTURE WORK: create more efficient logic
	for (int i = 0; i < 10; i++) {
	    if (temp == candidate[i].count) {
            cout << "The lowest amount of votes is " << candidate[i].name << " with " << candidate[i].count
                 << " votes" << endl << endl;
        }
	}
}


void display_highest_voted_candidate()
{
	int large, i, index;
	large = candidate[0].count;
	for (i = 1; i < 10; i++) {
		if (candidate[i].count > large) {
			large = candidate[i].count;
			index = i;
		}
	}

    // ugly hack solution for dealing with ties, could probably deal with this in
    // the loop one level higher but we're close to submission
    // FUTURE WORK: create more efficient logic
    for (int i = 0; i < 10; i++) {
        if (large == candidate[i].count) {
            cout << "The highest amount of votes is " << candidate[i].name << " with " << candidate[i].count
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