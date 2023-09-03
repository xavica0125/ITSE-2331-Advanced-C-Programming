#include "UserMenu.h"

void userMenu()
{
	int choice;
	do {
		cout << "Welcome! \n";
		cout << "Enter 1 to input Game of Thrones characters and their dragons \n"
			"Enter 2 to input Game of Thrones kingdoms and the size of their armies \n"
			"Enter 3 to exit program: ";
		cin >> choice;
		if (!cin) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "\nIncorrect input. Please try again.\n\n";

		}
		else {
			switch (choice) {
			case 1:
				arrayLoop();
				break;
			case 2:
				vectorLoop();
				break;
			case 3:
				break;
			default:
				cout << "Incorrect input. Please try again.\n";
			}
		}
	} while (choice != 3);
	cout << "Exiting...\n";
}
	