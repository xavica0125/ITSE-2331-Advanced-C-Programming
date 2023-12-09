#include "Product.h"

int Product::productCount = 0;

int Product::getProductCount()
{
	return productCount;
}

const int Product::getProductNum() const
{
	return productNum;
}

const string Product::getProductName() const
{
	return name;
}

const string Product::getProductDescription() const
{
	return description;
}

void Product::setProductDescription(const string& description)
{
	this->description = description;
}

const time_t Product::getProductCreationTime() const
{
	return productCreationTime;
}

Product::~Product()
{
	delete this;
}