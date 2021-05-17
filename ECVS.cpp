#include<iostream>
#include<fstream>
using namespace std;

char menu();



int main()
{

	


	char choice;

	choice = menu();

	switch (choice)
	{
	case "P":

		break;
	case "A":
		break;
	
	case "S":
		break;

	case "L":
		break;

	case "Q":
		break;

	}

}


char menu()
{

	char choice;

	do
	{
		cout << "Main menu:" << endl << "Please choose from the following" << endl;

		cout << "P - Display information on certain candidate" << endl;
		cout << "A - Add votes to candidate" << endl;
		cout << "S - Display candidate with smallest amount of votes" << endl;
		cout << "L - Display candidate with largest number of votes" << endl;
		cout << "Q - Quit" << endl;
		cin >> choice;
	} while (choice != "P" || choice != "A" || choice != "S" || choice != "L" || choice != "Q")

		return choice;
}
