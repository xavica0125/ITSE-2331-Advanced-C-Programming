#include "Pointer&Ref.h"

void calculateDiscount(float listPrice, float discountPercentage, float& discountedPrice)
{
	discountedPrice = listPrice - (listPrice * (discountPercentage / 100));
}

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

void sortArrays(string* builtInArray, array<string, 5>& classArray, const int arraySize2)
{
	sort(classArray.begin(), classArray.end());
	sort(builtInArray, builtInArray + arraySize2);
}
