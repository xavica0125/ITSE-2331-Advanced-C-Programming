#pragma once
#include <iostream>
#include <string>
#include <array>
#include <algorithm>
using std::cout; using std::string; using std::array; using std::sort;
void calculateDiscount(float listPrice, float discountPercentage, float& discountedPrice);
void determineLarger(int one, int two, int* largerNum);
bool compareArrays(string one[], string two[], const int arraySize);
void sortArrays(string* builtInArray, array<string, 5>& classArray, const int arraySize2);