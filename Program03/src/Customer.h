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
	string name;
	string address;
	vector<int> orderNums;
	time_t customerCreationTime;
	int month, year;

public:
	Customer(int custID, string name, string address)
		: custID(custID),
		  name(name),
		  address(address)
	{
		getCurrentMonthAndYear(month, year);
		customerCount++;
	};

	static int getCustomerCount();

	int getCustID() const;

	string getCustomerName() const;
	void setCustomerName(string name);

	string getCustomerAddress() const;
	void setCustomerAddress(string address);

	vector<int> getOrderNums() const;
	void setOrderNums(int orderNum);

	string getCustomerCreationTime() const;

	~Customer();
};