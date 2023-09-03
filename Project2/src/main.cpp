#include <iostream>
#include <string>
#include <array>
#include "Pointer&Ref.h"

using std::cout; using std::cin; using std::string; using std::array;

int main()
{
	// Function 1

	// Declare variables
	float listPrice, discountPercentage, discountedPrice;

	// Enter input and display output
	cout << "Enter list price: ";
	cin >> listPrice;
	cout << "Enter discount percentage: ";
	cin >> discountPercentage;
	calculateDiscount(listPrice, discountPercentage, discountedPrice);
	cout << "Your discounted price: $" << discountedPrice << "\n";

	cout << "\n";

	// Function 2

	// Declare variables
	int one, two, largerNum;

	// Enter input and display output 
	cout << "Enter first number: ";
	cin >> one;
	cout << "Enter second number: ";
	cin >> two;
	determineLarger(one, two, &largerNum);
	cout << "The larger number is: " << largerNum << "\n";

	cout << "\n";

	// Function 3

	// Declare values and arrays
	const int arraySize1 = 4;
	string arrayOne[4], arrayTwo[4];
	string input;

	// Input strings into arrays
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

	// Determine whether arrays are identical
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
	
	//Function 4

	//Initializing values and arrays
	const int arraySize2 = 5;
	string builtInArray[arraySize2];
	array<string, arraySize2> classArray;

	// Input strings into array
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

	cout << "\n";

	sortArrays(builtInArray,  classArray, arraySize2);

	// Output arrays after sorting
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

	//Function 5

	// Initializing values
	int val1 = 1;
	int val2 = 2;
	int const val3 = 3;
	int const val4 = 4;
	int const val5 = 5000;

	// Nonconstant pointer to nonconstant data
	int* notConstPtr = &val1;

	// Constant pointer to nonconstant data
	int* const constPtrPtr = &val2;

	// Nonconstant pointer to constant data
	const int* constDataPtr = &val3;

	// Constant pointer to constant data
	const int* const dataAndPtrPtr = &val4;

	// Derenferenced pointer values before calling demoPtrTechniques function
	cout << "Before calling demoPtrTechniques function: \n";
	cout << *notConstPtr << "\n";
	cout << *constPtrPtr << "\n";
	cout << *constDataPtr << "\n";
	cout << *dataAndPtrPtr << "\n";
	
	cout << "\n";
	demoPtrTechniques(notConstPtr, constPtrPtr, constDataPtr, dataAndPtrPtr, val5);

	// Derenferenced pointer values after calling demoPtrTechniques function
	cout << "After calling demoPtrTechniques function: \n";
	cout << *notConstPtr << "\n";
	cout << *constPtrPtr << "\n";
	cout << *constDataPtr << "\n";
	cout << *dataAndPtrPtr<< "\n";
	
}