#include "nonModSequence.h"

void nonModAlgoChoice(const int choice)
{
	switch (choice)
	{
	case 1:
		findAlgo();
		break;
	case 2:
		countAlgo();
		break;
	case 3:
		equalAlgo();
		break;
	case 4:
		forEachAlgo();
		break;
	}
}

void findAlgo()
{
	vector<string> myVector;
	string userInput;
	int numEntries;

	cout << "How many string entries do you want to enter into vector: ";
	cin >> numEntries;

	for (int i = 0; i < numEntries; i++)
	{
		cout << "Enter string entry: ";
		cin >> userInput;
		myVector.push_back(userInput);
	}

	cout << "Enter string entry to find in vector: ";
	cin >> userInput;

	auto found = find(myVector.begin(), myVector.end(), userInput);

	if (found != myVector.cend())
	{
		cout << userInput << " found at " << (found - myVector.cbegin()) << "\n";
	}
	else
	{
		cout << userInput << " not found...\n";
	}
}

void countAlgo()
{
	vector<char> myVector;
	char userInput;
	int numEntries;

	cout << "How many character entries do you want to enter into vector: ";
	cin >> numEntries;

	for (int i = 0; i < numEntries; i++)
	{
		cout << "Enter character entry: ";
		cin >> userInput;
		myVector.push_back(userInput);
	}

	cout << "Enter character entry to find in count of vector: ";
	cin >> userInput;

	auto totalCount = count(myVector.begin(), myVector.end(), userInput);

	cout << "The total count for " << userInput << " is " << totalCount << "\n";
}

void equalAlgo()
{
	vector<char> myVector1;
	vector<char> myVector2;

	char userInput;
	int numEntries;

	cout << "How many character entries do you want to enter into vector1: ";
	cin >> numEntries;

	for (int i = 0; i < numEntries; i++)
	{
		cout << "Enter character entry: ";
		cin >> userInput;
		myVector1.push_back(userInput);
	}

	cout << "How many character entries do you want to enter into vector2: ";
	cin >> numEntries;
	for (int i = 0; i < numEntries; i++)
	{
		cout << "Enter character entry: ";
		cin >> userInput;
		myVector2.push_back(userInput);
	}

	auto equalVector = equal(myVector1.cbegin(), myVector1.cend(), myVector2.cbegin(), myVector2.cend());

	if (equalVector)
	{
		cout << "Vector 1 and Vector 2 are equal.\n";
	}
	else
	{
		cout << "Vector 1 and Vector 2 are not equal.\n";
	}
}

void forEachAlgo()
{
	vector<int> myVector{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	cout << "Before applying for_each algorithm...\n";
	for (int num : myVector)
	{
		cout << num << " ";
	}

	cout << "\n";

	cout << "After applying for_each algorithm...\n";
	for_each(myVector.begin(), myVector.end(), [](auto x) {cout <<  x * x * x << " "; });

	cout << "\n";

	
}
