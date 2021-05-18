#include <fstream>
#include <iostream>

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

int main()
{
	char choice;
	choice = menu();

	switch (choice)
	{
        case 'P':
            break;
        case 'A':
            break;
        case 'S':
            break;
        case 'L':
            break;
        case 'Q':
            break;
	    default:
	        menu();
	}
}


char menu()
{
	char choice;
	do
	{
        // create a print_menu
        cout << "Main menu:" << endl << "Please choose from the following" << endl;
		cout << "P - Display information on certain candidate" << endl;
		cout << "A - Add votes to candidate" << endl;
		cout << "S - Display candidate with smallest amount of votes" << endl;
		cout << "L - Display candidate with largest number of votes" << endl;
		cout << "Q - Quit" << endl;
		cin >> choice;
	} while (choice != 'P' || choice != 'A' || choice != 'S' || choice != 'L' || choice != 'Q'); {
	    return choice;
	}
}