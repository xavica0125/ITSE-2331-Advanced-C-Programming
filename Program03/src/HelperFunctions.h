#pragma once
#include "Customer.h"
#include "Order.h"
#include "Product.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>

using std::time_t; using std::vector; using std::cout; using std::setw;

void getCurrentMonthAndYear(int& month, int& year);

void outputReport(vector<Customer> customerInstances,vector<Order>& orderInstances, vector<Product>& productInstances);

void outputCustomerInfo(vector<Customer>& customerInstances);

void outputOrderInfo(vector<Order>& orderInstances);

void outputProductInfo(vector<Product>& productInstances);