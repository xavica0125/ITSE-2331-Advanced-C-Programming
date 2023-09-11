#include "Product.h"

int Product::productCount{ 0 };

int Product::getProductCount()
{

	return productCount;
}

int Product::getProductNum() const
{
	return productNum;
}

string Product::getProductName() const
{
	return productName;
}

string Product::getProductDescription() const
{
	return productDescription;
}

void Product::setProductDescription(string description)
{
	productDescription = description;
}

string Product::getProductCreationTime() const
{
	string creationTime = std::to_string(month) + "\n" + std::to_string(year);
	return creationTime;
}

Product::~Product()
{
}
