#pragma once
#include <iostream>
#include <string>
#include <array>
#include <algorithm>

using std::cout; using std::string; using std::array; using std::sort;

// Function 1
void calculateDiscount(float listPrice, float discountPercentage, float& discountedPrice);

// Function 2
void determineLarger(int one, int two, int* largerNum);

// Function 3
bool compareArrays(string one[], string two[], const int arraySize);

// Function 4
void sortArrays(string* builtInArray, array<string, 5>& classArray, const int arraySize2);

//Function 5
void demoPtrTechniques(int* notConst, int* const constPtr, const int*& constData, const int* const dataAndPtr,const int& val);