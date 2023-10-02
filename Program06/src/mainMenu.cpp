#include "mainMenu.h"

void orderMenu()
{
	cout << std::fixed << std::setprecision(2);

	int menuChoice;
	double totalShippingCost = 0;
	vector <Package*> packages;
	do
	{
		cout << "Welcome! Would you like to add packages (1) or display vector of packages (2) or Exit (3): ";
		cin >> menuChoice;
		cin.ignore();

		switch (menuChoice)
		{
		case 1:
		{	
			enterPackage(totalShippingCost, packages);
			break;
		}
		case 2:
		{
			packageDisplay(totalShippingCost, packages);
			break;
		}
		}

	} while (menuChoice != 3);

	memoryDeallocation(packages);

}

// Function deletes dynamically allocated Package objects and clears vector Packages.
void memoryDeallocation(vector<Package*>& packages)
{
	for (Package* package : packages)
	{
		delete package;
		package = nullptr;
	}
	packages.clear();
}

// Function allows user to enter package information. 
void enterPackage(double &totalShippingCost, vector<Package*>& packages)
{
	string senderName, senderAddress, senderCity, senderState, senderZip;
	string receiverName, receiverAddress, receiverCity, receiverState, receiverZip;
	double weight, costPerOunce, additionalShippingRate;

	char exitChoice;
	int shippingChoice;
	
	do
	{
		cout << "Please enter information for sender and receiver for package: \n"
			<< "Enter sender name: ";
		getline(cin, senderName);
		cout << "Enter sender address: ";
		getline(cin, senderAddress);
		cout << "Enter sender city: ";
		cin >> senderCity;
		cout << "Enter sender state: ";
		cin >> senderState;
		cout << "Enter sender zip code: ";
		cin >> senderZip;

		// Error handling to ensure weight and costPerOunce are greater than 0.
		do
		{
			try
			{
				cout << "Enter package weight in pounds: ";
				cin >> weight;
				cout << "Enter cost per ounce to ship: ";
				cin >> costPerOunce;

				if (weight <= 0 || costPerOunce <= 0)
				{
					throw invalid_argument("Both values must be greater than 0");
				}
			}
			catch (const invalid_argument& e)
			{
				cout << "Invalid input: " << e.what() << "\n";
			}

		} while (weight <= 0 || costPerOunce <= 0);

		cin.ignore();

		cout << "Enter receiver name: ";
		getline(cin, receiverName);
		cout << "Enter receiver address: ";
		getline(cin, receiverAddress);
		cout << "Enter receiver city: ";
		cin >> receiverCity;
		cout << "Enter receiver state: ";
		cin >> receiverState;
		cout << "Enter receiver zip code: ";
		cin >> receiverZip;

		cout << "You may opt to ship with Two Day Shipping or Overnight Shipping \n"
			<< "Enter 1 for Two Day Shipping or 2 for Overnight Shipping or 3 for Standard Shipping: ";
		cin >> shippingChoice;

		switch (shippingChoice)
		{
		case 1:
		{
			Package* twoDayPackage = new TwoDayPackage(senderName, senderAddress, senderCity, senderState, senderZip, receiverName, receiverAddress, receiverCity, receiverState, receiverZip, weight, costPerOunce);

			packages.push_back(twoDayPackage);

			cout << "What is the fixed two day shipping rate: ";
			cin >> additionalShippingRate;
			twoDayPackage->setAdditionalShippingRate(additionalShippingRate);
			
			totalShippingCost += twoDayPackage->calculateCost();

			break;
		}
		case 2:
		{
			Package* overnightPackage = new OvernightPackage(senderName, senderAddress, senderCity, senderState, senderZip, receiverName, receiverAddress, receiverCity, receiverState, receiverZip, weight, costPerOunce);

			packages.push_back(overnightPackage);

			cout << "What is the additional cost per ounce overnight shipping rate: ";
			cin >> additionalShippingRate;
			overnightPackage->setAdditionalShippingRate(additionalShippingRate);

			totalShippingCost += overnightPackage->calculateCost();
			break;
		}
		case 3:
			Package * package = new Package(senderName, senderAddress, senderCity, senderState, senderZip, receiverName, receiverAddress, receiverCity, receiverState, receiverZip, weight, costPerOunce);

			packages.push_back(package);

			totalShippingCost += package->calculateCost();
			break;
		}
		cout << "Would you like to continue? Y/N: ";
		cin >> exitChoice;
		cin.ignore();
	} while (exitChoice != 'n' && exitChoice != 'N');
}

/* Function loops over vector Packages and displays each package information and total shipping costs of all packages inside the vector. */
void packageDisplay(double &totalShippingCost, vector<Package*>& packages)
{

	for (Package* packagePtr : packages)
	{
		cout << packagePtr->displayInfo() << "\n";
		
	}

	cout << "Total shipping costs: $" << totalShippingCost << "\n";
}