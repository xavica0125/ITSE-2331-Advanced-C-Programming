#pragma once

#include "Customer.h"
#include "Order.h"
#include "Product.h"

#include <ctime>
#include <iostream>
#include <iomanip>
#include <vector>

using std::cout; using std::cin; using std::vector; using std::setw; using std::left;
using std::right; 

using std::time_t;

//void getTime(time_t& creationTime);

vector<Customer*> mainMenu();

void outputReport(vector<Customer*>& custInstances);