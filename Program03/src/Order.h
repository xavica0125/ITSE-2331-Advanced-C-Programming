#pragma once
#include "HelperFunctions.h"

#include <string>
#include <vector>

using std::string; using std::vector;


class Order {

	friend void getCurrentMonthAndYear(int& month, int& year);

private:
	
	static int orderCount;
	const int orderNum;
	const int custID;
	vector<int> productNums;
	time_t orderCreationTime;
	int month, year;

public:

	Order(int orderNum, int custID)
		: orderNum(orderNum),
		custID(custID) {
		getCurrentMonthAndYear(month, year);
		orderCount++;
	};

	static int getOrderCount();

	int getOrderNum() const;

	int getCustID() const;

	vector<int> getProductNums() const;
	void setProductNums(int productNumber);

	string getOrderCreationTime() const;

	~Order();
};