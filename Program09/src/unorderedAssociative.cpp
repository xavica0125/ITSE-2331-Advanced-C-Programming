#include "unorderedAssociative.h"

void unorderedAssociativeChoice(const int choice)
{
	switch (choice)
	{
	case 1:
		useUnorderedSet();
		break;
	case 2:
		useUnorderedMultiset();
		break;
	case 3:
		useUnorderedMap();
		break;
	case 4:
		useUnorderedMultimap();
		break;
	}
}

void useUnorderedSet()
{
	unordered_set<char> myUnorderedSet;

	int userInput;
	char itemToAdd;

	cout << "How many characters do you want to add to the unordered set? \n";
	cin >> userInput;

	for (int i = 0; i < userInput; i++)
	{
		cout << "Enter character to add: ";
		cin >> itemToAdd;
		myUnorderedSet.insert(itemToAdd);
	}

	do
	{
		cout << "Would you like to... \n"
			<< "1. Display contents\n"
			<< "2. Insert element.\n"
			<< "3. Swap values with another unordered set. \n"
			<< "0. Exit. \n"
			<< "Enter choice: ";
		cin >> userInput;

		switch (userInput)
		{
		case 1:
		{
			for (const char item : myUnorderedSet)
			{
				cout << item << "\n";
			}
			break;
		}
		case 2:
		{
			cout << "Enter character to add: ";
			cin >> itemToAdd;

			myUnorderedSet.insert(itemToAdd);
			break;
		}
		case 3:
		{
			unordered_set<char> myUnorderedSet2;

			cout << "How many characters do you want to add to the unordered set? \n";
			cin >> userInput;

			for (int i = 0; i < userInput; i++)
			{
				cout << "Enter character to add: ";
				cin >> itemToAdd;
				myUnorderedSet2.insert(itemToAdd);
			}

			cout << "Before swap... \n";
			for (const char item : myUnorderedSet2)
			{
				cout << item << "\n";
			}

			cout << "After swap... \n";
			myUnorderedSet2.swap(myUnorderedSet);

			for (const char item : myUnorderedSet2)
			{
				cout << item << "\n";
			}
			break;
		}

		}
	} while (userInput != 0);
}

void useUnorderedMultiset()
{
	unordered_multiset<char> myUnorderedMultiset;

	int userInput;
	char itemToAdd;

	cout << "How many characters do you want to add to the unordered set? \n";
	cin >> userInput;

	for (int i = 0; i < userInput; i++)
	{
		cout << "Enter character to add: ";
		cin >> itemToAdd;
		myUnorderedMultiset.insert(itemToAdd);
	}

	do
	{
		cout << "Would you like to... \n"
			<< "1. Display contents\n"
			<< "2. Erase elements.\n"
			<< "3. Clear multiset. \n" 
			<< "0. Exit. \n"
			<< "Enter choice: ";
		cin >> userInput;

		switch (userInput)
		{
		case 1:
		{
			for (const char item : myUnorderedMultiset)
			{
				cout << item << "\n";
			}
			break;
		}
		case 2:
		{
			char itemToErase;

			cout << "Enter character to erase: ";
			cin >> itemToErase;

			myUnorderedMultiset.erase(itemToErase);
			break;
		}
		case 3:
		{
			myUnorderedMultiset.clear();

			break;
		}

		}
	} while (userInput != 0);
}

void useUnorderedMap()
{
	unordered_map<int, string> myUnorderedMap;

	int userInput;
	int keyToAdd;
	string valueToAdd;


	cout<< "How many elements do you want to add to the unordered map? \n";
	cin >> userInput;

	for (int i = 0; i < userInput; i++)
	{
		cout << "Enter key to add (int) : ";
		cin >> keyToAdd;
		cout << "Enter string to add: ";
		cin >> valueToAdd;
		myUnorderedMap[keyToAdd] = valueToAdd;
	}

	do
	{
		cout << "Would you like to... \n"
			<< "1. Display contents\n"
			<< "2. Find key and value.\n"
			<< "3. Emplace element. \n"
			<< "0. Exit. \n"
			<< "Enter choice: ";
		cin >> userInput;

		switch (userInput)
		{
		case 1:
		{
			for (const auto pair : myUnorderedMap)
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

			cout << keyToFind << " : " << myUnorderedMap.find(keyToFind)->second << "\n";

			break;

		}
		case 3:
		{
			cout << "Enter key to add: ";
			cin >> userInput;
			cout << "Enter value to add: ";
			cin >> valueToAdd;

			myUnorderedMap.emplace(userInput, valueToAdd);

			break;
		}

		}
	} while (userInput != 0);
}

void useUnorderedMultimap()
{
	unordered_multimap<int, string> myUnorderedMultimap;

	int userInput;
	int stringsToAdd;
	int keyToAdd;
	string valueToAdd;

	cout << "How many elements do you want to add to the unordered multimap? \n";
	cin >> userInput;

	for (int i = 0; i < userInput; i++)
	{
		cout << "Enter key to add (int) : ";
		cin >> keyToAdd;
		cout << "How many strings do you want to add to this key? ";
		cin >> stringsToAdd;
		for (int j = 0; j < stringsToAdd; j++)
		{
			cout << "Enter value to add: ";
			cin >> valueToAdd;
			myUnorderedMultimap.emplace(keyToAdd, valueToAdd);
		}
	}

	do
	{
		cout << "Would you like to... \n"
			<< "1. Display contents\n"
			<< "2. Find range of key and value.\n"
			<< "3. Get count for an element. \n"
			<< "0. Exit. \n"
			<< "Enter choice: ";
		cin >> userInput;

		switch (userInput)
		{
		case 1:
		{
			for (const auto pair : myUnorderedMultimap)
			{
				cout << pair.first << " : " << pair.second << "\n";
			}
			break;
		}
		case 2:
		{
			cout << "Which key do you want to find the range of? ";
			cin >> userInput;

			auto range = myUnorderedMultimap.equal_range(userInput);

			for (auto it = range.first; it != range.second; it++)
			{
				cout << it->first << " : " << it->second << "\n";
			}

			break;

		}
		case 3:
		{
			cout << "Which key do you want to find the count of? ";
			cin >> userInput;

			cout << myUnorderedMultimap.count(userInput) << "\n";

			break;
		}

		}
	} while (userInput != 0);
}

