#include "modifyingSequence.h"

void modAlgoChoice(const int choice)
{
	switch (choice)
	{
	case 1:
		generateAlgo();
		break;
	case 2:
		fill_nAlgo();
		break;
	case 3:
		replace_ifAlgo();
		break;
	case 4:
		swap_rangesAlgo();
		break;
	}
}

int nextNum()
{
	static int num{ 1 };
	return num++;
}

void generateAlgo()
{
	array<int, 10> myArray{ 0 };

	cout << "Before calling generate function...\n";
	for (int num : myArray)
	{
		cout << num << " ";
	}

	generate(myArray.begin(), myArray.end(), []() {return nextNum(); });

	cout << "\nAfter calling generate function...\n";
	for (int num : myArray)
	{
		cout << num << " ";
	}

	cout << "\n";
}

void fill_nAlgo()
{
	array<int, 10> myArray{ 0 };

	int userInput;
	cout << "Enter value to fill the last five values of array: ";
	cin >> userInput;

	cout << "Before calling fill_n function...\n";
	for (int num : myArray)
	{
		cout << num << " ";
	}

	fill_n(myArray.begin() + 5, 5 , userInput);

	cout << "\nAfter calling fill_n function...\n";

	for (int num : myArray)
	{
		cout << num << " ";
	}

	cout << "\n";
}

void replace_ifAlgo()
{
	array<int, 10> myArray{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int userInput;
	cout << "Enter value to replace if x * 2 > 4: ";
	cin >> userInput;

	cout << "Before calling replace_if function...\n";
	for (int num : myArray)
	{
		cout << num << " ";
	}

	replace_if(myArray.begin(), myArray.end(), [](auto x) {return x * 2 > 4; }, userInput);

	cout << "\nAfter calling replace_if function...\n";

	for (int num : myArray)
	{
		cout << num << " ";
	}

	cout << "\n";
}

void swap_rangesAlgo()
{
	array<int, 10> myArray{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	cout << "Before calling swap_ranges function...\n";
	for (int num : myArray)
	{
		cout << num << " ";
	}

	swap_ranges(myArray.begin(), myArray.begin() + 5, myArray.begin() + 5);

	cout << "\nAfter calling swap_ranges function...\n";

	for (int num : myArray)
	{
		cout << num << " ";
	}

	cout << "\n";
}





