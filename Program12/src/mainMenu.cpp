#include "mainMenu.h"

void dataTypeSelection()
{
	int userChoice;

	do
	{

		cout << "\nSelect one of the following to create a stack.\n"
			<< "1. Integer\n"
			<< "2. Double\n"
			<< "3. String\n"
			<< "0. Exit\n"
			<< "Enter choice: ";
		cin >> userChoice;
	
		switch (userChoice)
		{
		case 1:
		{
			Stack<int> intStack;
			stackOperations(intStack);
			break;
		}
		case 2:
		{
			Stack<double> doubleStack;
			stackOperations(doubleStack);
			break;
		}
		case 3:
		{
			Stack<string> stringStack;
			stackOperations(stringStack);
			break;
		}
		}


	} while (userChoice != 0);
}

template<class T>
void stackOperations(Stack<T>& userStack)
{
	int operationChoice;

	do
	{
		cout << "\nSelect one of the following operations to perform on your stack.\n"
			<< "1. Push\n"
			<< "2. Pop\n"
			<< "3. Top\n"
			<< "4. Clear\n"
			<< "5. Empty\n"
			<< "0. Exit\n"
			<< "Enter choice: ";
		cin >> operationChoice;

		switch (operationChoice)
		{
		case 1:
		{
			T itemToAdd;
			cout << "\nEnter item to push to top of stack: ";
			cin >> itemToAdd;

			userStack.push(itemToAdd);

			cout << "\nItem " << itemToAdd << " pushed to top of the stack.\n";
			break;
		}
		case 2:
		{
			try
			{
				cout << "\nItem " << userStack.pop() << " popped and removed from stack.\n";
			}
			catch (logic_error& error)
			{
				cout << "\n" << error.what() << "\n";
			}
			
			break;
		}
		case 3:
		{
			try
			{
				cout << "\nTop of stack item is " << userStack.top() << "\n";
			}
			catch (logic_error& error)
			{
				cout << "\n" << error.what() << "\n";
			}
			break;
		}
		case 4:
		{
			cout << "\nStack is cleared\n";
			userStack.clearStack();
			break;
		}
		case 5:
		{
			if (userStack.isEmpty())
			{
				cout << "\nStack is empty.\n";
			}
			else
			{
				cout << "\nStack is not empty.\n";
			}
			break;
		}
		}
	} while (operationChoice != 0);

}