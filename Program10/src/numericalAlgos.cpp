#include "numericalAlgos.h"

void numericalAlgoChoice(const int choice)
{
	switch (choice)
	{
	case 1:
		accumulateAlgo();
		break;
	case 2:
		transformAlgo();
		break;
	}
}

void accumulateAlgo()
{
	vector<string> myVector;
	int userInput;
	string stringValue;

	cout << "How many string entries do you want to make for vector? ";
	cin >> userInput;

	for (int i = 0; i < userInput; i++)
	{
		cout << "Enter value: ";
		cin >> stringValue;
		myVector.push_back(stringValue);
	}

	cout << "\nAccumulating...\n";

	string result = accumulate(myVector.begin(), myVector.end(), string(""));
	cout << "Result: " << result << "\n";

}

void transformAlgo()
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

	cout << "Vector before transformation: ";
	for (int i : myVector)
	{
		cout << i << " ";
	}

	cout << "\nTransforming...\n";

	transform(myVector.begin(), myVector.end(), myVector.begin(), [](int x) {return x * 2; });

	cout << "Vector after transformation: ";

	for (int i : myVector)
	{
		cout << i << " ";
	}

	cout << "\n";
}
