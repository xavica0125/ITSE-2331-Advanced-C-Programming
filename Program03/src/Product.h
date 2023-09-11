#pragma once
#include "HelperFunctions.h"

#include <string>

using std::string;

class Product {

	friend void getCurrentMonthAndYear(int& month, int& year);

private:
	
	static int productCount;
	const int productNum;
	const string productName;
	string productDescription;
	time_t productCreationTime;
	int month, year;

public:
	
	Product(int productNum, string productName)
		: productNum(productNum),
		productName(productName) {
		getCurrentMonthAndYear(month, year);
		productCount++;
	};

	static int getProductCount();

	int getProductNum() const;

	string getProductName() const;

    string getProductDescription() const;
	void setProductDescription(string description);

	string getProductCreationTime() const;

	~Product();
};