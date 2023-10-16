#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>


using std::cout; using std::cin; using std::getline; using std::cerr; using std::ofstream; using std::ifstream; using std::ios; using std::string; using std::vector; using std::istringstream; using std::setw;

void addProducts();

void addOrders(); 

void userMainMenu();

void displayReports();

void displayCities();

void displayStates();

void displayAllCityRecords();

void displayAllStateRecords();

void ordersCustID();

void ordersZip();