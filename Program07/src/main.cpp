#include "PhoneNumber.h"

#include <limits>

using std::endl;
using std::numeric_limits;	using std::streamsize;


int main()
{
	char retry;
	do
	{
		PhoneNumber phone;

		cout << "Enter phone number in the form (555) 555-5555: " << endl;
		cin >> phone;
	
		if (cin) // If input.setstate(ios::failbit) is set to false
		{
			cout << "\nThe phone number entered was:\n";

			cout << phone;
			retry = 'N';
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.clear();
			cout << "\n\n<ENTER> to exit: ";
			cin.get();
		}
		else
		{
			cin.clear();
			cout << "Would you like to try again? Y/N: ";
			cin >> retry;
		}
		cin.ignore();
	} while (retry == 'Y' || retry == 'y');
		
	
}

