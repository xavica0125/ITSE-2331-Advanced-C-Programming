#pragma once

#include "Order.h"

#include <string>
#include <vector>

using std::string; using std::vector;

class Customer
{
	friend void getTime(time_t& creationTime);
private:
	static int customerCount;
	const int custID;
	string name;
	string address;
	vector<Order*> orderNums;
	time_t customerCreationTime;
	int month, year;

public:
	Customer(const int custID, const string name, const string address)
		: custID(custID),
		name(name),
		address(address)
	{
		getTime(customerCreationTime);
		customerCount++;
	};

	const static int getCustomerCount();

	const int getCustID() const;

	const string getCustomerName() const;
	void setCustomerName(const string& name);

	const string getCustomerAddress() const;
	void setCustomerAddress(const string& address);

	const time_t getCustomerCreationTime() const;

	const vector<Order*>& getOrderNums() const;
	void setOrderNums(Order* orderNum);

	~Customer();
};

