#include <iostream>
#include <string>
#include <array>
#include "Pointer&Ref.h"

using std::cout; using std::cin; using std::string; using std::array;

int main()
{
	float listPrice, discountPercentage, discountedPrice;

	cout << "Enter list price: ";
	cin >> listPrice;
	cout << "Enter discount percentage: ";
	cin >> discountPercentage;
	calculateDiscount(listPrice, discountPercentage, discountedPrice);
	cout << "Your discounted price: $" << discountedPrice << "\n";

	cout << "\n";

	int one, two, largerNum;

	cout << "Enter first number: ";
	cin >> one;
	cout << "Enter second number: ";
	cin >> two;
	determineLarger(one, two, &largerNum);
	cout << "The larger number is: " << largerNum << "\n";

	cout << "\n";

	const int arraySize1 = 4;
	string arrayOne[4], arrayTwo[4];
	string input;

	for (int i = 0; i < arraySize1; i++)
	{
		cout << "Enter string for array 1 index " << i + 1 << ": ";
		cin >> arrayOne[i];
	}
	for (int i = 0; i < arraySize1; i++)
	{
		cout << "Enter string for array 2 index " << i + 1 << ": ";
		cin >> arrayTwo[i];
	}
	switch (compareArrays(arrayOne, arrayTwo, arraySize1))
	{
		case 0:
			cout << "False\n";
			break;
		case 1:
			cout << "True\n";
			break;
	}

	cout << "\n";

	const int arraySize2 = 5;
	string builtInArray[arraySize2];
	array<string, arraySize2> classArray;
	for (int i = 0; i < arraySize2; i++)
	{
		cout << "Enter string for array 1 index " << i + 1 << ": ";
		cin >> builtInArray[i];
	}
	for (int i = 0; i < arraySize2; i++)
	{
		cout << "Enter string for array 2 index " << i + 1 << ": ";
		cin >> classArray[i];
	}
	sortArrays(builtInArray,  classArray, arraySize2);
	for (string items : builtInArray)
	{
		cout << items << "\n";
	}

	cout << "\n";
	
	for (string items : classArray)
	{
		cout << items << "\n";
	}

	cout << "\n";
}