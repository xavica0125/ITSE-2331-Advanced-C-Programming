#include "userInteraction.h"

void addProducts()
{
	ofstream productsFile;
	productsFile.open("src/Products.txt", ios::app);

	int productID;
	string description;
	double price;

	cout << "Enter Product ID: ";
	cin >> productID;
	cin.ignore();
	cout << "Enter Product Description: ";
	getline(cin, description);
	cin.clear();
	cout << "Enter Product Price: ";
	cin >> price;

	if (!productsFile)
	{
		cerr << "File could not be opened\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		productsFile << productID << "%" << description << "%" << price << "\n";
	}
	productsFile.close();

}

void addOrders()
{
	ofstream ordersFile;
	ordersFile.open("src/Orders.txt", ios::app);

	int orderID;
	int customerID;
	string productID;
	int quantity;
	double orderTotal;

	cout << "Enter Order ID: ";
	cin >> orderID;
	cout << "Enter Customer ID: ";
	cin >> customerID;
	cout << "Enter Product ID: ";
	cin >> productID;
	cout << "Enter Quantity: ";
	cin >> quantity;

	ifstream productsFile("src/Products.txt");

	string line;
	string readProductID;
	string readPrice;

	if (!productsFile.is_open())
	{
		cout << "Error opening input file.\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		while (getline(productsFile, line))
		{
			size_t percentPos = line.find('%');
			readProductID = line.substr(0, percentPos);
			if (readProductID == productID)
			{
				size_t lastPercentPos = line.rfind('%');
				readPrice = line.substr(lastPercentPos + 1);

			}
		}

		productsFile.close();
	}

	orderTotal = quantity * std::stod(readPrice);

	if (!ordersFile.is_open())
	{
		cout << "Error opening input file.\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		ordersFile << orderID << "%" << customerID << "%" << productID << "%" << quantity << "%" << orderTotal << "\n";

		ordersFile.close();
	}

}


void userMainMenu()
{
	int menuChoice;

	do
	{
		cout << "Welcome! \n"
			<< "\nEnter 1 to enter product. \n"
			<< "Enter 2 to enter order. \n"
			<< "Enter 3 to display reports. \n"
			<< "Enter 4 to exit: ";
		cin >> menuChoice;
		cout << "\n";

		switch (menuChoice)
		{
		case 1:
			addProducts();
			break;

		case 2:
			addOrders();
			break;

		case 3:
			displayReports();
			break;

		}


	} while (menuChoice != 4);

}


void displayReports()
{
	int displayChoice;

	do
	{
		cout << "Pick a type of reporting: \n"
			<< "\n1. List of cities in CustomerMaster.txt \n"
			<< "2. List of states in CustomerMaster.txt \n"
			<< "3. All customer records in a city. \n"
			<< "4. All customer records in a state. \n"
			<< "5. All orders associated with a customer by CustomerID. \n"
			<< "6. All orders associated with a customer by ZipCode. \n"
			<< "7. Exit: ";
		cin >> displayChoice;
		cout << "\n";

		switch (displayChoice)
		{
		case 1:
		{
			displayCities();
			break;
		}
		case 2:
		{
			displayStates();
			break;
		}
		case 3:
		{
			displayAllCityRecords();
			break;
		}
		case 4:
		{
			displayAllStateRecords();
			break;
		}
		case 5:
		{
			ordersCustID();
			break;
		}
		case 6:
		{
			ordersZip();
			break;
		}
		}
	} while (displayChoice != 7);
}

void displayCities()
{
	vector<string> cities;
	string line;
	int percentCount;
	string customerCity;

	ifstream customerFile("src/CustomerMaster.txt");

	if (!customerFile.is_open())
	{
		cerr << "Error opening input file.\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		while (getline(customerFile, line))
		{
			percentCount = 0;
			customerCity.clear();
			for (int i = 0; i < line.size(); i++)
			{

				if (line[i] == '%')
				{
					percentCount++;
				}
				if (percentCount == 4)
				{
					if (line[i + 1] != '%')
					{
						customerCity += line[i + 1];

					}

				}

			}
			cities.push_back(customerCity);
		}
		customerFile.close();
	}

	for (string city : cities)
	{
		cout << city << "\n";
	}
}

void displayStates()
{
	vector<string> states;
	string line;
	int percentCount;
	string customerState;

	ifstream customerFile("src/CustomerMaster.txt");

	if (!customerFile.is_open())
	{
		cerr << "Error opening input file.\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		while (getline(customerFile, line))
		{
			percentCount = 0;
			customerState.clear();
			for (int i = 0; i < line.size(); i++)
			{

				if (line[i] == '%')
				{
					percentCount++;
				}
				if (percentCount == 5)
				{
					if (line[i + 1] != '%')
					{
						customerState += line[i + 1];

					}

				}

			}
			states.push_back(customerState);
		}
		customerFile.close();
	}

	for (string state : states)
	{
		cout << state << "\n";
	}
}

void displayAllCityRecords()
{
	string city;
	string line;
	int percentCount;
	string customerCity;
	vector <string> customerRecord;

	cout << "Enter city to retrieve customer records: ";
	cin >> city;

	ifstream customerFile("src/CustomerMaster.txt");

	if (!customerFile.is_open())
	{
		cerr << "Error opening input file.\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		while (getline(customerFile, line))
		{
			percentCount = 0;
			customerCity.clear();
			for (int i = 0; i < line.size(); i++)
			{

				if (line[i] == '%')
				{
					percentCount++;
				}
				if (percentCount == 4)
				{
					if (line[i + 1] != '%')
					{
						customerCity += line[i + 1];

					}

				}

			}
			if (customerCity == city)
			{

				customerRecord.push_back(line);


			}

		}
		customerFile.close();
	}


	for (const string& record : customerRecord)
	{
		istringstream stream(record);
		string field;
		while (getline(stream, field, '%'))
		{
			for (char character : field)
			{
				if (character != '%')
				{
					std::cout << character;
				}
			}
			cout << std::left << setw(5) << ' ';
		}
		cout << '\n';
	}
}

void displayAllStateRecords()
{
	string state;
	string line;
	int percentCount;
	string customerState;
	vector <string> customerRecord;

	cout << "Enter state to retrieve customer records: ";
	cin >> state;

	ifstream customerFile("src/CustomerMaster.txt");

	if (!customerFile.is_open())
	{
		cerr << "Error opening input file.\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		while (getline(customerFile, line))
		{
			percentCount = 0;
			customerState.clear();
			for (int i = 0; i < line.size(); i++)
			{

				if (line[i] == '%')
				{
					percentCount++;
				}
				if (percentCount == 5)
				{
					if (line[i + 1] != '%')
					{
						customerState += line[i + 1];

					}

				}

			}
			if (customerState == state)
			{

				customerRecord.push_back(line);


			}

		}
		customerFile.close();
	}


	for (const string& record : customerRecord)
	{
		istringstream stream(record);
		string field;
		while (getline(stream, field, '%'))
		{
			for (char character : field)
			{
				if (character != '%')
				{
					std::cout << character;
				}
			}
			cout << std::left << setw(5) << ' ';
		}
		cout << '\n';
	}
}

void ordersCustID()
{
	string searchID;
	string customerID;
	string line;
	vector<string> orders;
	int percentCount;

	cout << "Enter Customer ID to retrieve all orders: ";
	cin >> searchID;

	ifstream custOrders("src/Orders.txt");

	if (!custOrders.is_open())
	{
		cerr << "Error opening input file.\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		while (getline(custOrders, line))
		{
			percentCount = 0;
			customerID.clear();
			for (int i = 0; i < line.size(); i++)
			{

				if (line[i] == '%')
				{
					percentCount++;
				}
				if (percentCount == 1)
				{
					if (line[i + 1] != '%')
					{
						customerID += line[i + 1];

					}
				}
			}
			if (searchID == customerID)
			{

				orders.push_back(line);


			}
		}
		custOrders.close();
	}
	for (const string& order : orders)
	{
		istringstream stream(order);
		string field;
		while (getline(stream, field, '%'))
		{
			for (char character : field)
			{
				if (character != '%')
				{
					std::cout << character;
				}
			}
			cout << std::left << setw(5) << ' ';
		}
		cout << '\n';
	}
}

void ordersZip()
{
	string searchZip;
	string customerZip;
	string line;
	vector<string> orders;
	int percentCount;

	cout << "Enter Customer Zip to retrieve all orders: ";
	cin >> searchZip;

	ifstream custMaster("src/CustomerMaster.txt");


	if (!custMaster.is_open())
	{
		cerr << "Error opening input file.\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		while (getline(custMaster, line))
		{
			percentCount = 0;
			customerZip.clear();
			for (int i = 0; i < line.size(); i++)
			{

				if (line[i] == '%')
				{
					percentCount++;
				}
				if (percentCount == 6)
				{
					if (line[i + 1] != '\0')
					{
						customerZip += line[i + 1];

					}
				}
			}
			if (searchZip == customerZip)
			{
				string custID;
				string searchID;
				percentCount = 0;
				for (int i = 0; i < line.size(); i++)
				{

					if (line[i] == '%')
					{
						percentCount++;
					}
					if (percentCount < 1)
					{
						custID += line[i];
					}
				}
				ifstream custOrders("src/Orders.txt");

				if (!custOrders.is_open())
				{
					cerr << "Error opening input file.\n";
					exit(EXIT_FAILURE);
				}
				else
				{
					while (getline(custOrders, line))
					{
						percentCount = 0;
						searchID.clear();
						for (int i = 0; i < line.size(); i++)
						{

							if (line[i] == '%')
							{
								percentCount++;
							}
							if (percentCount == 1)
							{
								if (line[i + 1] != '%')
								{
									searchID += line[i + 1];

								}
							}
						}
						if (custID == searchID)
						{
							orders.push_back(line);
						}
					}

					custOrders.close();
				}
			}
		}

		custMaster.close();
	}
	for (const string& order : orders)
	{
		istringstream stream(order);
		string field;
		while (getline(stream, field, '%'))
		{
			for (char character : field)
			{
				if (character != '%')
				{
					std::cout << character;
				}
			}
			cout << std::left << setw(5) << ' ';
		}
		cout << '\n';
	}
}
