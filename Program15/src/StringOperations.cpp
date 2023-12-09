#include "StringOperations.h"

void assignValues()
{
	string input;
	int choice;
	cout << "\nSelect an assignment operation\n"
		<< "1. Initialize string with constructor argument\n"
		<< "2. Initialize string with assignment operator\n"
		<< "3. Initialize string with assign function\n";
	cin >> choice;

	cout << "\nEnter a string: ";
	cin >> input;

	switch (choice)
	{
	case 1:
	{
		string str1{input};
		cout << "\nstr1: " << str1 << "\n";
		break;
	}
	case 2:
	{
		string str2 = input;
		cout << "\nstr2: " << str2 << "\n";
		break;
	}
	case 3:
	{
		string str3;
		str3.assign(input);
		cout << "\nstr3: " << str3 << "\n";
		break;
	}
	}
}

void concatenateStrings()
{
	int choice;
	cout << "\nSelect a concatenation operation\n"
		<< "1. Concatenate with += operator\n"
		<< "2. Concatenate with append function\n";
	cin >> choice;

	string input1, input2;
	cout << "\nEnter a string: ";
	cin >> input1;
	cout << "\nEnter another string: ";
	cin >> input2;

	cout << "\nstr1: " << input1 << "\n";
	cout << "\nstr2: " << input2 << "\n";
	
	switch (choice)
	{
	case 1:
	{
		input1 += input2;
		cout << "\nstr1: " << input1 << "\n";
		break;
	}
	case 2:
	{
		input1.append(input2);
		cout << "\nstr1: " << input1 << "\n";
		break;
	}
	}

	cout << "\n";
}

void compareStrings()
{
	int choice;
	string input1, input2;

	cout << "Enter a string: ";
	cin >> input1;
	cout << "\nEnter another string: ";
	cin >> input2;

	cout << "\nString1: " << input1 << "\n";
	cout << "\nString2: " << input2 << "\n";

	cout << "\nSelect portions of strings to compare\n"
		<< "1. Compare entire strings\n"
		<< "2. Compare substrings\n";
	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		if (input1 == input2)
		{
			cout << "\nStrings are equal\n";
		}
		else if (input1 < input2)
		{
			cout << "\nString1 is less than String2\n";
		}
		else
		{
			cout << "\nString1 is greater than String2\n";
		}
		break;
	}
	case 2: 
	{
		int start1, length;
		cout << "\nEnter starting index for " << input1 << ": ";
		cin >> start1;
		cout << "\nEnter length: ";
		cin >> length;

		int start2;
		cout << "\nEnter starting index for " << input2 << ": ";
		cin >> start2;
		

		int result = input1.compare(start1, length, input2, start2, length);
		
		if ( result == 0)
		{
			cout << "\nStrings are equal\n";
		}
		else if (result < 0)
		{
			cout << "\nString1 is less than String2\n";
		}
		else
		{
			cout << "\nString1 is greater than String2\n";
		}
		break;
	}
	}
	cout << "\n";
}

void displayStringForward()
{
	string input;
	cout << "\nEnter a string: ";
	cin >> input;

	cout << "\nString: " << input << "\n";

	cout << "\nDisplaying string using forward iterator\n";
	for (string::iterator it = input.begin(); it != input.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << "\n\n";
}

void displayStringReverse()
{
	string input;
	cout << "\nEnter a string: ";
	cin >> input;

	cout << "\nString: " << input << "\n";

	cout << "\nDisplaying string using reverse iterator\n";
	for (string::reverse_iterator it = input.rbegin(); it != input.rend(); ++it)
	{
		cout << *it << " ";
	}
	cout << "\n\n";
}

void demonstrateIO()
{
	int choice;

	cout << "\nSelect one of I/O streams\n"
		<< "1. Standard cin/cout streams\n"
		<< "2. File I/O\n"
		<< "3. String streams\n";
	cin >> choice;

	switch (choice)
	{
	case 1: 
	{
		string input;
		cout << "\nEnter a string: ";
		cin >> input;
		cout << "\nString: " << input << "\n\n";
		break;
	}
	case 2:
	{
		string input;
		string fileLine;
		cout << "\nEnter a string: ";
		cin >> input;

		ofstream outFile("src/output.txt");
		if (outFile.is_open())
		{
			cout << "Writing " << input << " to file...\n";
			outFile << input << "\n";
			outFile.close();
		}
		else
		{
			cout << "\nError opening file...\n";
		}

		ifstream inFile("src/output.txt");
		if (inFile.is_open())
		{
			cout << "\nReading from file...\n";
			inFile >> fileLine;
			cout << "\nString: " << fileLine << "\n";
			inFile.close();
		}
		else
		{
			cout << "\nError opening file...\n";
		}

		cout << "\n";

		break;
	}
	case 3:
	{
		cout << "\nDemonstrating istringstreams...\n";

		istringstream ss{ "105 Grassy Lane" };

		string streetNum, streetNameFirst, streetNameSecond;

		ss >> streetNum >> streetNameFirst >> streetNameSecond;
		
		cout << "\nStreet Number: " << streetNum << "\nStreet Name: " << streetNameFirst << " " << streetNameSecond << "\n";

		cout << "\nDemonstrating ostringstreams...\n";
		ostringstream oss;
		
		oss << "105 Grassy Lane" << " Austin, TX";
		
		cout << "\nString: " << oss.str() << "\n";
	}
	}

	cout << "\n";
}

