#pragma once

#include "HelperFunctions.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

class Customer
{

	friend void getCurrentMonthAndYear(int &month, int &year);

private:
	static int customerCount;
	const int custID;
	const string name;
	string address;
	vector<int> orderNums;
	time_t customerCreationTime;
	int month, year;

public:
	Customer(const int custID, const string name, const string address)
		: custID(custID),
		  name(name),
		  address(address)
	{
		getCurrentMonthAndYear(month, year);
		customerCount++;
	};

	const static int getCustomerCount();

	const int getCustID() const;

	const string getCustomerName() const;
	void setCustomerName(const string& name);

	const string getCustomerAddress() const;
	void setCustomerAddress(const string& address);

	const vector<int> getOrderNums() const;
	void setOrderNums(const int orderNum);

	const string getCustomerCreationTime() const;

};