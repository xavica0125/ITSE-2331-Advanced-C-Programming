#pragma once

#include "test.h"

#include <string>
#include <vector>


using std::string; using std::vector;

class Product
{
	friend void getTime(time_t& creationTime);
private:
	const int productNum;
	const string name;
	string description;
	time_t productCreationTime;
	static int productCount;

public:
	Product(const int productNum, const string name, const string description)
		: productNum(productNum),
		name(name),
		description(description)
	{
		getTime(productCreationTime);
		productCount++;
	};

	static int getProductCount();

	const int getProductNum() const;

	const string getProductName() const;

	const string getProductDescription() const;
	void setProductDescription(const string& description);

	const time_t getProductCreationTime() const;

	~Product();
};

