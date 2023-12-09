#include "Order.h"

int Order::orderCount = 0;

const int Order::getOrderNum() const
{
	return orderNum;
}

const int Order::getCustID() const
{
	return custID;
}

const vector<Product*>& Order::getProductNums() const
{
	return productNums;
}
	
void Order::setProductNums(Product* productNum)
{
	productNums.push_back(productNum);
}

const time_t Order::getOrderCreationTime() const
{
	return orderCreationTime;
}

const int Order::getOrderCount()
{
	return orderCount;
}

Order::~Order()
{
	delete this;
}