#include "StringOperations.h"

int main()
{
	int userChoice;
	
	do
	{
		cout << "Please select from the following string operations.\n"
			<< "1. Assign values to string variables\n"
			<< "2. Concatenate strings\n"
			<< "3. Compare strings\n"
			<< "4. Display string using forward iterator\n"
			<< "5. Display string using reverse iterator\n"
			<< "6. Demonstrate common I/O operations\n"
			<< "0. Exit\n";
		cin >> userChoice;

		switch (userChoice)
		{
		case 1:
		{
			assignValues();
			break;
		}
		case 2:
		{
			concatenateStrings();
			break;
		}
		case 3:
		{
			compareStrings();
			break;
		}
		case 4:
		{
			displayStringForward();
			break;
		}
		case 5:
		{
			displayStringReverse();
			break;
		}
		case 6:
		{
			demonstrateIO();
			break;
		}
		}

	} while (userChoice != 0);
}