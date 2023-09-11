#pragma once
#include "Customer.h"
#include "Order.h"
#include "Product.h"

#include <vector>
#include <iostream>
#include <string>

using std::string; using std::cout; using std::cin; using std::vector;

void mainMenu();

Customer createNewCustomer();

Order createNewOrder();

Product createNewProduct();

