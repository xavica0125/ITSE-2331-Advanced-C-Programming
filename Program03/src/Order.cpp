#include "Order.h"

int Order::orderCount{ 0 };

int Order::getOrderCount()
{
	return orderCount;
}

int Order::getOrderNum() const
{
	return orderNum;
}

int Order::getCustID() const
{
	return custID;
}

vector<int> Order::getProductNums() const
{
	return productNums;
}

void Order::setProductNums(int productNumber)
{
	productNums.push_back(productNumber);

}

string Order::getOrderCreationTime() const
{
	string creationTime = std::to_string(month) + "\n" + std::to_string(year);
	return creationTime;
}

Order::~Order()
{
}

