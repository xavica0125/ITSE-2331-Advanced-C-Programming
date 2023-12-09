#include "Customer.h"

int Customer::customerCount = 0;


const int Customer::getCustomerCount()
{
    return customerCount;
}

const int Customer::getCustID() const
{
    return custID;
}

const string Customer::getCustomerName() const
{
    return name;
}

void Customer::setCustomerName(const string& name)
{
    this->name = name;
}

const string Customer::getCustomerAddress() const
{
    return address;
}

void Customer::setCustomerAddress(const string& address)
{
    this->address = address;
}

const vector<Order*>& Customer::getOrderNums() const
{
    return orderNums;
}

void Customer::setOrderNums(Order* orderNum)
{
    orderNums.push_back(orderNum);
}

const time_t Customer::getCustomerCreationTime() const
{
	return customerCreationTime;
}

Customer::~Customer()
{
	delete this;
}