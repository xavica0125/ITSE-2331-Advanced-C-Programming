#pragma once

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <vector>

#include "TwoDayPackage.h"
#include "OvernightPackage.h"

using std::cout; using std::cin; using std::getline; using std::string; using std::ostream; using std::invalid_argument; using std::vector;


void orderMenu();

void memoryDeallocation(vector<Package*>& packages);

void enterPackage(double &totalShippingCost, vector<Package*>& packages);

void packageDisplay(double& totalShippingCost, vector<Package*>& packages);


