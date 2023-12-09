#include "HelperFunctions.h"

/*void getTime(time_t& creationTime)
{
	time_t epochSeconds = std::time(nullptr);
	tm* tm_ptr = std::localtime(&epochSeconds);

	// Set day, hour, minute, and second to 0 to get the start of the month
	tm_ptr->tm_mday = 1;
	tm_ptr->tm_hour = 0;
	tm_ptr->tm_min = 0;
	tm_ptr->tm_sec = 0;

	creationTime = std::mktime(tm_ptr);

}*/

vector<Customer*> mainMenu()
{

	vector<Customer*> customerInstances;

	int custID;
	string name;
	string address;

	cout << "Enter customer ID: ";
	cin >> custID;
	cout << "Enter customer name: ";
	cin >> name;
	cin.ignore();
	cout << "Enter customer address: ";
	std::getline(cin, address);
	Customer* custInstance = new Customer(custID, name, address);
	
	customerInstances.push_back(custInstance);

	int orderNum;
	
	cin.ignore();
	cout << "Enter order number: ";
	cin >> orderNum;

	Order* orderInstance = new Order(orderNum, custID);

	custInstance->setOrderNums(orderInstance);

	int numofProducts;

	int productNum;
	string description;

	cout << "Enter number of products to place in order: ";
	cin >> numofProducts;

	for (int i = 0; i < numofProducts; i++)
	{
		cout << "Enter product number: ";
		cin >> productNum;
		cout << "Enter product name: ";
		cin >> name;
		cin.ignore();
		cout << "Enter product description: ";
		std::getline(cin, description);
		cin.ignore();
		Product* productInstance = new Product(productNum, name, description);
		orderInstance->setProductNums(productInstance);
	}

	return customerInstances;
}

void outputReport(vector<Customer*>& custInstances)
{
    cout << "Customers with all member data.\n";
    cout << "----------------------------------------\n";
    cout << "Customer ID\tOrder Number\tProduct Number\tProduct Name\tProduct Description\n";
    for (auto& custInstance : custInstances)
    {
        cout << custInstance->getCustID() << "\t\t";
        for (auto& orderInstance : custInstance->getOrderNums())
        {
            cout << orderInstance->getOrderNum() << "\t\t";
            for (auto& productInstance : orderInstance->getProductNums())
            {
                cout << productInstance->getProductNum() << "\t\t";
                cout << productInstance->getProductName() << "\t\t";
                cout << productInstance->getProductDescription() << "\n";
            }
        }
    }
}
