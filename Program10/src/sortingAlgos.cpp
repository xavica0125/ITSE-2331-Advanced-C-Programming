#include "sortingAlgos.h"

void sortingAlgoChoice(const int choice)
{
	switch (choice)
	{
	case 1:
		binarySearchAlgo();
		break;
	case 2:
		upperBoundAlgo();
		break;
	case 3:
		setDifferenceAlgo();
		break;
	case 4:
		sortAlgo();
		break;
	case 5:
		setUnionAlgo();
		break;
	case 6:
		equalRangeAlgo();
		break;
	}
}

void binarySearchAlgo()
{
	vector<int> myVector;

	int userInput;
	int numValue;

	cout << "How many integer entries do you want to make for vector? ";
	cin >> userInput;

	for (int i = 0; i < userInput; i++)
	{
		cout << "Enter value: ";
		cin >> numValue;
		myVector.push_back(numValue);
	}

	cout << "Sorting...\n";
	sort(myVector.begin(), myVector.end());

	cout << "Enter value to search for using binary search: ";
	cin >> numValue;

	auto found = binary_search(myVector.cbegin(), myVector.cend(), numValue);

	if (found)
	{
		cout << numValue << " found in Vector.\n";
	}
	else
	{
		cout << numValue << " not found in Vector.\n";
	}
}

void upperBoundAlgo()
{
	vector<double> myVector;

	int valEntries;
	double userInput;

	cout << "How many double entries would you like to make for multiset? ";
	cin >> valEntries;

	for (int i = 0; i < valEntries; i++)
	{
		cout << "Enter double: ";
		cin >> userInput;
		myVector.push_back(userInput);
	}

	sort(myVector.begin(), myVector.end());

	cout << "\nEnter double to enter and call upper_bound algorithm: ";
	cin >> userInput;

	auto it = upper_bound(myVector.cbegin(), myVector.cend(), userInput);
	
	for (double num : myVector)
	{
		cout << num << " ";
	}
	cout << "\nUpper bound " << userInput << " can be inserted at is " << (it - myVector.cbegin()) << "\n";
}

void setDifferenceAlgo()
{
	set<int> mySet1;
	set<int> mySet2;
	set<int> difference;
	int valEntries;
	int userInput;

	cout << "How many integer entries would you like to make for set1? ";
	cin >> valEntries;

	for (int i = 0; i < valEntries; i++)
	{
		cout << "Enter integer: ";
		cin >> userInput;
		mySet1.insert(userInput);
	}

	cout << "How many integer entries would you like to make for set2? ";
	cin >> valEntries;

	for (int i = 0; i < valEntries; i++)
	{
		cout << "Enter integer: ";
		cin >> userInput;
		mySet2.insert(userInput);
	}

	set_difference(mySet1.cbegin(), mySet1.cend(), mySet2.cbegin(), mySet2.cend(), std::inserter(difference, difference.begin()));

	cout << "\nSet difference between mySet1 and mySet 2 is: ";
	for (int num : difference)
	{
		cout << num << " ";
	}

	cout << "\n";
}

void sortAlgo()
{
	vector<double> myVector;
	int valEntries;
	double userInput;

	cout << "How many double entries would you like to make for vector ? ";
	cin >> valEntries;

	for (int i = 0; i < valEntries; i++)
	{
		cout << "Enter double: ";
		cin >> userInput;
		myVector.push_back(userInput);
	}

	cout << "Before sorting...\n";
	for (double num : myVector)
	{
		cout << num << " ";
	}

	cout << "\nSorting...\n";

	sort(myVector.begin(), myVector.end());

	cout << "After sorting...\n";
	for (double num : myVector)
	{
		cout << num << " ";
	}

	cout << "\n";
}

void setUnionAlgo()
{
	set<int> mySet1;
	set<int> mySet2;
	set<int> unionSet;
	int userInput;

	cout << "Enter 5 integer entries for set1: \n";
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter integer: ";
		cin >> userInput;
		mySet1.insert(userInput);
	}

	cout << "Enter 5 integer entries for set2: \n";
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter integer: ";
		cin >> userInput;
		mySet2.insert(userInput);
	}

	set_union(mySet1.cbegin(), mySet1.cend(), mySet2.cbegin(), mySet2.cend(), std::inserter(unionSet,unionSet.begin()));

	cout << "Set union of set1 and set2...\n";
	for (int num : unionSet)
	{
		cout << num << " ";
	}

	cout << "\n";
}

void equalRangeAlgo()
{
	set<double> mySet;
	int valEntries;
	double userInput;

	cout << "How many double entries would you like to make for set? ";
	cin >> valEntries;

	for (int i = 0; i < valEntries; i++)
	{
		cout << "Enter double: ";
		cin >> userInput;
		mySet.insert(userInput);
	}

	cout << "Enter double to find equal range for: ";
	cin >> userInput;

	auto range = equal_range(mySet.cbegin(), mySet.cend(), userInput);

	for (double num : mySet)
	{
		cout << num << " ";
	}

	cout << "\nLower bound: " << *range.first << "\n";
	cout << "Upper bound: " << *range.second << "\n";
	
}
