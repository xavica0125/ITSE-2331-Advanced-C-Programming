#include "HelperFunctions.h"

void getCurrentMonthAndYear(int& month, int& year)
{
	time_t epochSeconds = time(NULL);

	tm* tm_ptr = localtime(&epochSeconds);

	month = tm_ptr->tm_mon;
	year = tm_ptr->tm_year + 1900;
	
}


void outputReport(vector<Customer> customerInstances,vector<Order>& orderInstances,vector<Product>& productInstances)
{
	outputCustomerInfo(customerInstances);
	outputOrderInfo(orderInstances);
	outputProductInfo(productInstances);
	
}

void outputCustomerInfo(vector<Customer>& customerInstances)
{
	for (int i = 0; i < customerInstances.size(); i++)
	{
		cout << customerInstances[i].getCustID() << setw(3) << customerInstances[i].getCustomerName() << setw(3) << customerInstances[i].getCustomerAddress() << setw(3);
		for (int j = 0; j < customerInstances[i].getOrderNums().size(); j++)
		{
			cout << customerInstances[i].getOrderNums()[j] << ", " << setw(3);
		}
		cout << customerInstances[i].getCustomerCreationTime() << setw(3) << Customer::getCustomerCount() << "\n";
	}
}

void outputOrderInfo(vector<Order>& orderInstances)
{
	for (int i = 0; i < orderInstances.size(); i++)
	{
		cout << orderInstances[i].getOrderNum() << setw(3) << orderInstances[i].getCustID() << setw(3);
		for (int j = 0; j < orderInstances[i].getProductNums().size(); j++)
		{
			cout << orderInstances[i].getProductNums()[j] << ", " << setw(3);
		}
		cout << orderInstances[i].getOrderCreationTime() << setw(3) << Order::getOrderCount() << "\n";
	}
}

void outputProductInfo(vector<Product>& productInstances)
{
	for (int i = 0; i < productInstances.size(); i++)
	{
		cout << productInstances[i].getProductNum() << setw(3) << productInstances[i].getProductName() << setw(3) << productInstances[i].getProductDescription() << setw(3) << productInstances[i].getProductCreationTime() << setw(3) << Product::getProductCount() << "\n";
	}
}


	