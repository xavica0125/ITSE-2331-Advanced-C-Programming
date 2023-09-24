#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

#include "TwoDayPackage.h"
#include "OvernightPackage.h"

using std::cout; using std::cin; using std::getline; using std::string; using std::ostream; using std::invalid_argument;


void orderMenu();

// Overloaded << operator functions for each type of function when calling calculateCost() method. 
ostream& operator<<(ostream& out, Package& package);
ostream& operator<<(ostream& out, TwoDayPackage& package);
ostream& operator<<(ostream& out, OvernightPackage& package);



