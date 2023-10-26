#include "orderedAssociative.h"

void orderedAssociativeChoice(const int choice)
{
	switch (choice)
	{
	case 1:
		useSet();
		break;
	case 2:
		useMultiset();
		break;
	case 3:
		useMap();
		break;
	case 4:
		useMultimap();
		break;
	}
}

void useSet()
{
	set<double> mySet;
	int userInput;
	double itemToAdd;

	cout << "How many double do you want to add to the set? \n";
	cin >> userInput;

	for (int i = 0; i < userInput; i++)
	{
		cout << "Enter double to add: ";
		cin >> itemToAdd;
		mySet.insert(itemToAdd);
	}

	do
	{
		cout << "Would you like to... \n"
			<< "1. Display contents\n"
			<< "2. Find item in the set.\n"
			<< "3. Erase a range of values. \n"
			<< "0. Exit. \n"
			<< "Enter choice: ";
		cin >> userInput;

		switch (userInput)
		{
		case 1:
		{
			for (const double item : mySet)
			{
				cout << item << "\n";
			}
			break;
		}
		case 2:
		{
			double itemToFind;
			cout << "Which item to do you want to find? ";
			cin >> itemToFind;

			set<double>::iterator it;

			it = mySet.find(itemToFind);

			cout << *it << " found\n";

			break;
		}
		case 3:
		{
			double lowerBound;
			double upperBound;
			cout << "Enter lowerbound: ";
			cin >> lowerBound;
			cout << "Enter upperbound: ";
			cin >> upperBound;

			set<double>::iterator itlow, itup;

			itlow = mySet.lower_bound(lowerBound);
			itup = mySet.upper_bound(upperBound);

			mySet.erase(itlow, itup);

			break;
		}

		}
	} while (userInput != 0);
}

void useMultiset()
{
	multiset<double> myMultiSet;

	int userInput;
	double itemToAdd;

	cout << "How many double do you want to add to the set? \n";
	cin >> userInput;

	for (int i = 0; i < userInput; i++)
	{
		cout << "Enter double to add: ";
		cin >> itemToAdd;
		myMultiSet.insert(itemToAdd);
	}

	do
	{
		cout << "Would you like to... \n"
			<< "1. Display contents\n"
			<< "2. Find count of item.\n"
			<< "3. Construct and insert element. \n"
			<< "0. Exit. \n"
			<< "Enter choice: ";
		cin >> userInput;

		switch (userInput)
		{
		case 1:
		{
			for (const double item : myMultiSet)
			{
				cout << item << "\n";
			}
			break;
		}
		case 2:
		{
			double itemToFind;
			cout << "Which item to do you want to find the count of? ";
			cin >> itemToFind;

			cout << itemToFind << " appears " << myMultiSet.count(itemToFind) << " times.\n";

			break;
		}
		case 3:
		{
			double itemToEmplace;

			cout << "Enter double to emplace: ";
			cin >> itemToEmplace;

			myMultiSet.emplace(itemToEmplace);

			break;
		}

		}
	} while (userInput != 0);
}

void useMap()
{
	map<int, char> myMap;

	int userInput;
	
	int keyToAdd;
	char charToAdd;

	cout << "How many keys do you want to add to map? ";
	cin >> userInput;

	for (int i = 0; i < userInput; i++)
	{
		cout << "Enter key to add (int) : ";
		cin >> keyToAdd;
		cout << "Enter character to add: ";
		cin >> charToAdd;
		myMap[keyToAdd] = charToAdd;
	} 

	do
	{
		cout << "Would you like to... \n"
			<< "1. Display contents\n"
			<< "2. Find key and value.\n"
			<< "3. Erase element. \n"
			<< "0. Exit. \n"
			<< "Enter choice: ";
		cin >> userInput;

		switch (userInput)
		{
		case 1:
		{
			for (const auto pair : myMap)
			{
				cout << pair.first << " : " << pair.second << "\n";
			}
			break;
		}
		case 2:
		{
			int keyToFind;
			cout << "Which item to do you want to find? ";
			cin >> keyToFind;

			cout << keyToFind << " : " << myMap.find(keyToFind)->second << "\n";

			break;
		}
		case 3:
		{
			int keyToErase;

			cout << "Enter key to erase: ";
			cin >> keyToErase;

			myMap.erase(keyToErase);

			break;
		}

		}
	} while (userInput != 0);
}

void useMultimap()
{
	multimap<int, char> myMultiMap;

	int userInput;

	int keyToAdd;
	int numValues;
	char charToAdd;

	cout << "How many keys do you want to add to multimap? ";
	cin >> userInput;

	for (int i = 0; i < userInput; i++)
	{
		cout << "Enter key to add (int) : ";
		cin >> keyToAdd;
		cout << "How many characters do you want to add to this key? ";
		cin >> numValues;
		for (int j = 0; j < numValues; j++)
		{
			cout << "Enter character to add: ";
			cin >> charToAdd;
			myMultiMap.insert(std::make_pair(keyToAdd, charToAdd));
		}
	}

	do
	{
		cout << "Would you like to... \n"
			<< "1. Display contents\n"
			<< "2. Find key and values.\n"
			<< "3. Get count of elements with a specific key. \n"
			<< "0. Exit. \n"
			<< "Enter choice: ";
		cin >> userInput;

		switch (userInput)
		{
		case 1:
		{
			for (const auto pair : myMultiMap)
			{
				cout << pair.first << " : " << pair.second << "\n";
			}
			break;
		}
		case 2:
		{
			int keyToFind;
			cout << "Which item to do you want to find? ";
			cin >> keyToFind;

			auto range = myMultiMap.equal_range(keyToFind);
			for (auto it = range.first; it != range.second; it++) {
				cout << "Key: " << it->first << ", Value: " << it->second << "\n";
			}
		}
		case 3:
		{
			int keyToFind;

			cout << "Enter key to find count: ";
			cin >> keyToFind;

			cout << "There are " << myMultiMap.count(keyToFind) << " elements with key " << keyToFind << "\n";

			break;
		}

		}
	} while (userInput != 0);
}
