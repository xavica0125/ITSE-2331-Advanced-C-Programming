#include "mainMenu.h"

void orderMenu()
{
	string senderName, senderAddress, senderCity, senderState, senderZip;
	string receiverName, receiverAddress, receiverCity, receiverState, receiverZip;
	double weight, costPerOunce;
	int shippingChoice;
	char exitChoice;

	do
	{
		cout << "Welcome! Please enter information for sender and receiver for package: \n"
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
				double twoDayShipRate;
				TwoDayPackage package = TwoDayPackage(senderName, senderAddress, senderCity, senderState, senderZip, receiverName, receiverAddress, receiverCity, receiverState, receiverZip, weight, costPerOunce);
				cout << "What is the fixed two day shipping rate: ";
				cin >> twoDayShipRate;
				package.setTwoDayFee(twoDayShipRate);
				cout << package;
				break;
			}
			case 2:
			{
				double overnightShipRate;
				OvernightPackage package = OvernightPackage(senderName, senderAddress, senderCity, senderState, senderZip, receiverName, receiverAddress, receiverCity, receiverState, receiverZip, weight, costPerOunce);
				cout << "What is the additional cost per ounce overnight shipping rate: ";
				cin >> overnightShipRate;
				package.setOvernightRate(overnightShipRate);
				cout << package;
				break;
			}
			case 3:
				Package package = Package(senderName, senderAddress, senderCity, senderState, senderZip, receiverName, receiverAddress, receiverCity, receiverState, receiverZip, weight, costPerOunce);
				cout << package;
				break;
		}
		cout << "Would you like to continue? Y/N: ";
		cin >> exitChoice;
		cin.ignore();

	} while (exitChoice != 'N' && exitChoice != 'n');
		
}

ostream& operator<<(ostream& out, Package& package)
{
	
	out << "Total cost with regular package shipping: $"
		 << package.calculateCost() << "\n";
	return out;

}

ostream& operator<<(ostream& out, TwoDayPackage& package)
{
	
	out << "Total cost with two day package shipping flat rate: $"
		 << package.calculateCost() << "\n";
	return out;

}

ostream& operator<<(ostream& out, OvernightPackage& package)
{
	
	out << "Total cost with overnight package shipping rate: $"
		 << package.calculateCost() << "\n";
	return out;

}

