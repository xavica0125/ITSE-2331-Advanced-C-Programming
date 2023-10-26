#include "containerAdapters.h"

void containerAdapterChoice(const int choice)
{
	switch (choice)
	{
	case 1:
		useStack();
		break;
	case 2:
		useQueue();
		break;
	case 3:
		usePriorityQueue();
		break;
	}
}

void useStack()
{
	stack<int> myStack;

	int userInput;
	int itemToAdd;

	cout << "How many integers do you want to add to the stack? \n";
	cin >> userInput;

	for (int i = 0; i < userInput; i++)
	{
		cout << "Enter integer to add: ";
		cin >> itemToAdd;
		myStack.push(itemToAdd);
	}

	do
	{
		cout << "Would you like to... \n"
			<< "1. Display contents\n"
			<< "2. Push element.\n"
			<< "3. Remove top element from stack. \n"
			<< "0. Exit. \n"
			<< "Enter choice: ";
		cin >> userInput;

		switch (userInput)
		{
		case 1:
		{
			stack<int> myStackCopy = myStack;
			while (!myStack.empty())
			{
				cout << myStack.top() << "\n";
				myStack.pop();
			}
			myStack = myStackCopy;
			break;
		}
		case 2:
		{
			cout << "Enter integer to add: ";
			cin >> itemToAdd;

			myStack.push(itemToAdd);

			break;
		}
		case 3:
		{
			cout << "Removing top element from stack.\n";
			myStack.pop();

			break;
		}

		}
	} while (userInput != 0);
}

void useQueue()
{
	queue<string> myQueue;

	int userInput;
	string itemToAdd;

	cout << "How many integers do you want to add to the queue? \n";
	cin >> userInput;

	for (int i = 0; i < userInput; i++)
	{
		cout << "Enter integer to add: ";
		cin >> itemToAdd;
		myQueue.push(itemToAdd);
	}

	do
	{
		cout << "Would you like to... \n"
			<< "1. Display contents\n"
			<< "2. Push element.\n"
			<< "3. Remove top element from queue. \n"
			<< "0. Exit. \n"
			<< "Enter choice: ";
		cin >> userInput;

		switch (userInput)
		{
		case 1:
		{
			queue<string> myQueueCopy = myQueue;
			while (!myQueue.empty())
			{
				cout << myQueue.front() << "\n";
				myQueue.pop();
			}
			myQueue = myQueueCopy;
			break;
		}
		case 2:
		{
			cout << "Enter integer to add: ";
			cin >> itemToAdd;

			myQueue.push(itemToAdd);

			break;
		}
		case 3:
		{
			cout << "Removing top element from queue.\n";
			myQueue.pop();

			break;
		}

		}
	} while (userInput != 0);
}

void usePriorityQueue()
{
	priority_queue<double> myPriorityQueue;

	int userInput;
	double itemToAdd;

	cout << "How many doubles do you want to add to the priority queue? \n";
	cin >> userInput;

	for (int i = 0; i < userInput; i++)
	{
		cout << "Enter double to add: ";
		cin >> itemToAdd;
		myPriorityQueue.push(itemToAdd);
	}

	do
	{
		cout << "Would you like to... \n"
			<< "1. Display contents\n"
			<< "2. Push element.\n"
			<< "3. Remove top element from priority queue. \n"
			<< "0. Exit. \n"
			<< "Enter choice: ";
		cin >> userInput;

		switch (userInput)
		{
		case 1:
		{
			priority_queue<double> myPriorityQueueCopy = myPriorityQueue;
			while (!myPriorityQueue.empty())
			{
				cout << myPriorityQueue.top() << "\n";
				myPriorityQueue.pop();
			}
			myPriorityQueue = myPriorityQueueCopy;
			break;
		}
		case 2:
		{
			cout << "Enter double to add: ";
			cin >> itemToAdd;

			myPriorityQueue.push(itemToAdd);

			break;
		}
		case 3:
		{
			cout << "Removing top element from priority queue.\n";
			myPriorityQueue.pop();

			break;
		}

		}
	} while (userInput != 0);
}

