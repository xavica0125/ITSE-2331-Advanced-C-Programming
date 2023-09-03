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

bool compareArrays(string one[], string two[], int arraySize)
{
	bool match = false;
	for (int i = 0; i < arraySize; i++)
	{
		if (one[i] == two[i])
		{
			match = true;
		}
	}
	return match;
}
