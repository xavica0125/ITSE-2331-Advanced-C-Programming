#include "List.h"

#include <iostream>
#include <string>

using std::cout; using std::cin; using std::string;

template<class T>
void listOperations(List<T>& list);

int main()
{
	int userChoice;
	do
	{
		cout << "Welcome! Select a data type to create a List.\n"
			<< "1. String\n"
			<< "2. Integer\n"
			<< "3. Double\n"
			<< "4. Character\n"
			<< "0. Exit\n"
			<< "Enter choice: ";
		cin >> userChoice;

		switch (userChoice)
		{
		case 1:
		{
			List<string> newList;
			listOperations(newList);
			break;
		}
		case 2:
		{
			List<int> newList;
			listOperations(newList);
			break;
		}
		case 3:
		{
			List<double> newList;
			listOperations(newList);
			break;
		}
		case 4:
		{
			List<char> newList;
			listOperations(newList);
			break;
		}
		}

	} while (userChoice != 0);
}

template<class T>
void listOperations(List<T>& list)
{
	int userChoice;
	T entry;
	do
	{
		cout << "\n";

		if (!list.isEmpty())
		{
			displayList(list);
		}

		cout << "\n";

		cout << "\nSelect one of the list operations.\n"
			<< "1. Insert at the beginning of the list.\n"
			<< "2. Insert at the end of the list.\n"
			<< "3. Delete from the beginning of the list.\n"
			<< "4. Delete from the end of the list.\n"
			<< "5. Insert at an index of the list.\n"
			<< "6. Delete a node from the list by value.\n"
			<< "7. End list processing.\n"
			<< "Enter choice: ";

		cin >> userChoice;

		switch (userChoice)
		{
		case 1:
		{
			cout << "\nEnter entry: ";
			cin >> entry;
			list.insertFront(entry);
			cout << "\n" << entry << " inserted at beginning of list\n";
			break;
		}
		case 2:
		{
			cout << "\nEnter entry: ";
			cin >> entry;
			list.insertEnd(entry);
			cout << "\n" << entry << " inserted at end of list\n";
			break;
		}
		case 3:
		{
			try
			{
				list.deleteFront();
				cout << "\nNode at beginning of list deleted.\n";
			}
			catch (logic_error& e)
			{
				cout << e.what();
			}
			break;
		}
		case 4:
		{
			try
			{
				list.deleteEnd();
				cout << "\nNode at end of list deleted.\n";
			}
			catch (logic_error& e)
			{
				cout << e.what();
			}
			break;
		}
		case 5:
		{
			int idx;
			cout << "\nEnter index at which to insert value: ";
			cin >> idx;
			cout << "\nEnter value to add to list at index " << idx << ": ";
			cin >> entry;
			try
			{
				list.insertIndexValue(idx, entry);
				cout << "\n" << entry << " added at index " << idx << "\n";
			}
			catch (logic_error& e)
			{
				cout << e.what();
			}
			break;
		}
		case 6:
		{
			cout << "\nEnter value of node you wish to delete: ";
			cin >> entry;
			try
			{
				list.deleteNodeByVal(entry);
				cout << "\nNode of value " << entry << " was deleted.\n";
			}
			catch (logic_error& e)
			{
				cout << e.what();
			}
			break;
		}
		}
	} while (userChoice != 7);

	cout << "\n";
}

