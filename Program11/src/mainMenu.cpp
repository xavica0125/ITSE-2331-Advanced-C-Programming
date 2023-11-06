#include "mainMenu.h"

void userMenu()
{
	int userInput;

	do
	{
		cout << "Select from exception-based operations below.\n"
			<< "1. Division by zero\n"
			<< "2. Rethrowing exceptions\n"
			<< "3. Stack unwinding\n"
			<< "4. Using the 'new' operator to throw a bad_alloc exception type\n"
			<< "5. Using the 'new' operator to demonstrate set_new_handler function\n"
			<< "0. Exit\n"
			<< "Enter choice: ";
		cin >> userInput;

		switch (userInput)
		{
		case 1:
		{
			int x;
			int y;

			cout << "\nEnter operand 1: ";
			cin >> x;
			cout << "\nEnter operand 2: ";
			cin >> y;

			divByZero(x, y);
			break;
		}
		case 2:
		{
			try
			{
				rethrowException();
			}
			catch (invalid_argument& e)
			{
				cout << e.what() << "\n";
			}
			break;
		}
		case 3:
		{
			int x;
			cout << "\nEnter integer (enter 0 to cause exception): ";
			cin >> x;

			stackUnwind(x);
			break;
		}
		case 4:
		{
			badAllocException();
			break;
		}
		case 5:
		{
			setNewHandler();
			break;
		}
		}
	} while (userInput != 0);
}