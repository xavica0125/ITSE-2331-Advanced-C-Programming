#include "UserInteraction.h"

void mainMenu()
{
	int choice;
	vector<Customer> customerInstances;
	vector<Order> orderInstances;
	vector<Product> productInstances;
	do
	{
		cout << "\nWelcome!\n";
		cout << "Enter 1 to enter new customer \n";
		cout << "Enter 2 to add new order to existing customer \n";
		cout << "Enter 3 to add new product to existing order \n";
		cout << "Enter 4 to display report \n";
		cout << "Or Enter 5 to exit \n";
		cin >> choice;

		switch (choice) {
		case 1:
		{
			Customer customer = createNewCustomer();
			customerInstances.push_back(customer);
			break;
		}
		case 2:
		{
			Order order = createNewOrder();
			orderInstances.push_back(order);
			break;
		}
		case 3:
		{
			Product product = createNewProduct();
			productInstances.push_back(product);
			break;
		}
		case 4:
			outputReport(customerInstances, orderInstances, productInstances);
			break;
		case 5:
			cout << "Exiting...\n";
			break;
		default:
			cout << "Invalid choice, please try again.\n";
		}
		
	} while (choice != 5);
}

Customer createNewCustomer()
{
	int custID;
	string name, address;
	cout << "Enter Customer ID: ";
	cin >> custID;

	cout << "Enter Customer Name: ";
	cin >> name;

	cout << "Enter Customer Address: ";
	cin >> address;

	Customer object = Customer(custID, name, address);
	cout << "Success! \n";

	char choice;
	cout << "Would you like to enter an order? Y/N: ";
	cin >> choice;

	if (choice == 'Y' || choice == 'y')
	{
		Order order = createNewOrder();
		object.setOrderNums(order.getOrderNum());
		
		int numProducts;
		cout << "How many products would you like to enter? ";
		cin >> numProducts;
		for (int i = 0; i < numProducts; i++)
		{
			Product product = createNewProduct();
			order.setProductNums(product.getProductNum());
		}
		return object;
	}
	else
	{
		cout << "Returning to Main Menu\n";
	}
}

Order createNewOrder()
{
	int orderNum, custID;
	cout << "Enter Order Number: ";
	cin >> orderNum;

	cout << "Enter Customer ID: ";
	cin >> custID;
	cout << "Success!\n";
	return Order(orderNum, custID);
	
}

Product createNewProduct()
{
	int productNum;
	string productName;
	cout << "Enter Product Number: ";
	cin >> productNum;

	cout << "Enter Product Name: ";
	cin >> productName;

	cout << "Success!\n";
	return Product(productNum, productName);

}




