#include "sequenceContainers.h"

void sequenceContainerChoice(const int choice)
{
	switch (choice)
	{
		case 1:
			useArray();
			break;
		case 2:
			useDeque();
			break;
		case 3:
			useForwardList();
			break;
		case 4:
			useList();
			break;
		case 5:
			useVector();
			break;
	}
}

void useArray()
{
	array<int, 5> myArray;
	int userInput;

	for (int& index : myArray)
	{
		cout << "Enter sample data (int): ";
		cin >> userInput;
		index = userInput;
	}

	int userChoice;
	do
	{
		cout << "Would you like to... \n"
			<< "1. Display contents\n"
			<< "2. Search for a specific item.\n"
			<< "3. Sort the array. \n"
			<< "0. Exit. \n"
			<< "Enter choice: ";
		cin >> userChoice;

		switch (userChoice)
		{
		case 1:
		{
			for (const int& index : myArray)
			{
				cout << index << "\n";
			}
			break;
		}
		case 2:
		{
			int itemToSearch;
			cout << "Enter item to search: ";
			cin >> itemToSearch;

			for (int i = 0; i < myArray.size(); i++)
			{
				if (myArray[i] == itemToSearch)
				{
					cout << "Found item: " << myArray[i] << " at index " << i << "\n";
				}
			}
			break;
		}
		case 3:
		{
			cout << "Before sorting... \n";

			for (const int& index : myArray)
			{
				cout << index << "\n";
			}

			sort(myArray.begin(), myArray.end());
			cout << "After sorting... \n";

			for (const int& index : myArray)
			{
				cout << index << "\n";
			}
			break;
		}

		}
	} while (userChoice != 0);
	

}

void useDeque()
{
	deque<int> myDeque;
	int userInput;
	int itemToAdd;

	cout << "How many int do you want to add to the deque? \n";
	cin >> userInput;

	for (int i = 0; i < userInput; i++)
	{
		cout << "Enter item to add: ";
		cin >> itemToAdd;
		myDeque.push_back(itemToAdd);
	}

	do
	{
		cout << "Would you like to... \n"
			<< "1. Display contents\n"
			<< "2. Push item to the front of the deque.\n"
			<< "3. Pop item from the front of the deque. \n"
			<< "0. Exit. \n"
			<< "Enter choice: ";
		cin >> userInput;

		switch (userInput)
		{
		case 1:
		{
			for (const int item : myDeque)
			{
				cout << item << "\n";
			}
			break;
		}
		case 2:
		{
			int itemToAdd;
			cout << "Enter item to add: ";
			cin >> itemToAdd;

			myDeque.push_front(itemToAdd);

			break;
		}
		case 3:
		{
			int poppedItem;
			myDeque.pop_front();
			cout << "Enter 1 to display contents of deque after front item popped. \n";
			break;
		}

		}
	} while (userInput != 0);

}

void useForwardList()
{
	forward_list<string> myForwardList;

	int userInput;
	string itemToAdd;

	cout << "How many string items do you want to add to the forward list? ";
	cin >> userInput;

	for (int i = 0; i < userInput; i++)
	{
		cout << "Enter string item: ";
		cin >> itemToAdd;
		myForwardList.push_front(itemToAdd);
	}

	do
	{
		cout << "Would you like to... \n"
			<< "1. Display contents\n"
			<< "2. Remove duplicate values.\n"
			<< "3. Reverse order of elements. \n"
			<< "0. Exit. \n"
			<< "Enter choice: ";
		cin >> userInput;

		switch (userInput)
		{
		case 1:
		{
			for (const string& item : myForwardList)
			{
				cout << item << "\n";
			}
			break;
		}
		case 2:
		{
			myForwardList.unique();
			break;
		}
		case 3:
		{
			myForwardList.reverse();
			break;
		}

		}
	} while (userInput != 0);
}

void useList()
{
	list<string> myList1;
	list<string> myList2;

	int userInput;
	string itemToAdd;

	for (int i = 1; i < 3; i++)
	{
		cout << "How many string items do you want to add to list " << i << "?\n";
		cin >> userInput;
		if (i == 1)
		{
			for (int j = 0; j < userInput; j++)
			{

				cout << "Enter string item: ";
				cin >> itemToAdd;
				myList1.push_back(itemToAdd);
			}
		}
		else
		{
			for (int k = 0; k < userInput; k++)
			{

				cout << "Enter string item: ";
				cin >> itemToAdd;
				myList2.push_front(itemToAdd);
			}
		}
	}

	do
	{
		cout << "Would you like to... \n"
			<< "1. Display contents\n"
			<< "2. Merge lists.\n"
			<< "3. Swap list contents. \n"
			<< "0. Exit. \n"
			<< "Enter choice: ";
		cin >> userInput;

		switch (userInput)
		{
		case 1:
		{	
			cout << "Displaying contents for list 1...\n";
			for (const string& item : myList1)
			{
				cout << item << "\n";
			}
			cout << "\nDisplaying contents for list 2...\n";
			for (const string& item : myList2)
			{
				cout << item << "\n";
			}
			break;
		}
		case 2:
		{
			myList1.sort();
			myList2.sort();
			myList1.merge(myList2);
			break;
		}
		case 3:
		{
			myList1.swap(myList2);
			break;
		}

		}
	} while (userInput != 0);
}

void useVector()
{
	vector<int> myVector;
	int userInput;
	int itemToAdd;
	
	cout << "How many int do you want to add to the vector? \n";
	cin >> userInput;
	for (int i = 0; i < userInput; i++)
	{
		cout << "Enter sample data: ";
		cin >> itemToAdd;
		myVector.push_back(itemToAdd);
	}

	int userChoice;
	do
	{
		cout << "Would you like to... \n"
			<< "1. Display contents\n"
			<< "2. Reserve extra capacity.\n"
			<< "3. Shrink to fit. \n"
			<< "0. Exit. \n"
			<< "Enter choice: ";
		cin >> userChoice;

		switch (userChoice)
		{
		case 1:
		{
			for (const int& index : myVector)
			{
				cout << index << "\n";
			}
			break;
		}
		case 2:
		{
			int extraCapacity;
			cout << "Current capacity: " << myVector.capacity() << "\n";
			cout << "How much extra capacity do you want to reserve? ";
			cin >> extraCapacity;
			myVector.reserve(extraCapacity);
			cout << "Capacity after: " << myVector.capacity() << "\n";
			break;
		}
		case 3:
		{
			cout << "Current capacity: " << myVector.capacity() << "\n";
			myVector.shrink_to_fit();
			cout << "Capacity after shrink to fit: " << myVector.capacity() << "\n";
			break;
		}

		}
	} while (userChoice != 0);
}
