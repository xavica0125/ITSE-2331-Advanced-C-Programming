#pragma once


#include "Product.h"
#include <vector>

using std::vector;

class Order
{
	friend void getTime(time_t& creationTime);
private:
	const int orderNum;
	const int custID;
	vector<Product*> productNums;
	time_t orderCreationTime;
	static int orderCount;

public:
	Order(const int orderNum, const int custID) : orderNum(orderNum), custID(custID)
	{
		getTime(orderCreationTime);
		orderCount++;
	}

	const int getOrderNum() const;

	const int getCustID() const;

	const vector<Product*>& getProductNums() const;
	void setProductNums(Product* productNum);

	const time_t getOrderCreationTime() const;

	const int getOrderCount();

	~Order();
};

