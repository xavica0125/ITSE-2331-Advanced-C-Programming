#include "OpDemonstration.h"

#include <iostream>

using std::cout; using std::cin; 

int main()
{
	int menuChoice;

	do
	{
		cout << "Welcome!\n"
			<< "1. Demonstrate structs\n"
			<< "2. Demonstrate bitwise operators\n"
			<< "3. Demonstrate character handling\n"
			<< "4. Demonstrate c-string handling\n"
			<< "5. Demonstrate c-string search\n"
			<< "6. Demonstrate c-string memory\n"
			<< "7. Exit\n"
			<< "Enter your choice: ";
		cin >> menuChoice;

		switch (menuChoice)
		{
		case 1:
			demonstrateStructs();
			break;

		case 2:
			demonstrateBitwiseOperators();
			break;

		case 3:
			demonstrateCharHandling();
			break;

		case 4:
			demonstrateCstringHandling();
			break;

		case 5:
			demonstrateCstringSearch();
			break;

		case 6:
			demonstrateCstringMemory();
			break;
		}
	} while (menuChoice != 7);	
}