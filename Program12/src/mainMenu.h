#pragma once

#include "Stack.h"

#include <iostream>
#include <string>

using std::cout; using std::cin; using std::string;

void dataTypeSelection();

template<class T>
void stackOperations(Stack<T>& userStack);
