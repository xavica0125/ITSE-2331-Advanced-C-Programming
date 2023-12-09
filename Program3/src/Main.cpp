#include "HelperFunctions.h"
#include "Customer.h"

int main()
{
	int userChoice;

	do
	{
		vector<Customer*> customers;

		cout << "Welcome to the Order Management System!\n\n"
			<< "Please select from the following options.\n"
			<< "1. Create a new customer\n"
			<< "2.Output report\n"
			<< "0. Exit\n";
		cin >> userChoice;

		switch (userChoice)
		{
		case 1:
		{
			customers = mainMenu();
			break;
		}
		case 2:
		{
			outputReport(customers);
			break;
		}
		}

	} while (userChoice != 0);
}