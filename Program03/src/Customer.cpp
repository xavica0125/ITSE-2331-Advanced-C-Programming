#include "Customer.h"

int Customer::customerCount{ 0 };

int Customer::getCustomerCount()
{
	return customerCount;
}

int Customer::getCustID() const 
{
	return custID;
}

string Customer::getCustomerName() const
{
	return name;
}

void Customer::setCustomerName(string name)
{
	this->name = name;
}

string Customer::getCustomerAddress() const
{
	return address;
}

void Customer::setCustomerAddress(string address)
{
	this->address = address;
}

vector<int> Customer::getOrderNums() const 
{
	return orderNums;
}

void Customer::setOrderNums(int orderNum)
{
	orderNums.push_back(orderNum);
}

Customer::~Customer()
{
}

string Customer::getCustomerCreationTime() const
{
	string creationTime = std::to_string(month) + "\n" + std::to_string(year);
	return creationTime;
}

