#include "Pointer&Ref.h"

// Function 1
void calculateDiscount(float listPrice, float discountPercentage, float& discountedPrice)
{
	discountedPrice = listPrice - (listPrice * (discountPercentage / 100));
}

// Function 2
void determineLarger(int one, int two, int* largerNum)
{
	if (one > two)
	{
		*largerNum = one;
	}
	else 
	{
		*largerNum = two;
	}
}

// Function 3
bool compareArrays(string one[], string two[],const int arraySize)
{
	bool match = true;
	for (int i = 0; i < arraySize; i++)
	{
		if (one[i] != two[i])
		{
			match = false;
		}
	}
	return match;
}

// Function 4
void sortArrays(string* builtInArray, array<string, 5>& classArray, const int arraySize2)
{
	sort(classArray.begin(), classArray.end());
	sort(builtInArray, builtInArray + arraySize2);
}

// Function 5
void demoPtrTechniques(int* notConst, int* const constPtr, const int*& constData, const int* const dataAndPtr,const int &val)
{
	*notConst = 2000;
	
	*constPtr = 3000;

	constData = &val;
}
