#include "Part2.h"

bool proceedToEnterKingdoms()
{
	char choice;
	cout << "Would you like to enter a kingdom (Y/N)? ";
	cin >> choice;
	if (choice == 'Y' || choice == 'y') {
		return true;
	}
}

void vectorLoop()
{
	if (proceedToEnterKingdoms() == true) {
		vector<string> kingdom;
		vector<int> size;
		int kingdomIndex = 0;
		char choice;
		string kingdomName;
		int kingdomSize;
		do {
			cout << "Enter the kingdom name: ";
			cin >> kingdomName;
			kingdom.push_back(kingdomName);
			for (int i = kingdomIndex; i < kingdom.size(); i++) {
				cout << "Enter " << kingdom[i] << " size: ";
				cin >> kingdomSize;
				size.push_back(kingdomSize);
			}
			kingdomIndex++;
			cout << "Would you like to enter another kingdom (Y/N) ? ";
			cin >> choice;
		} while ((choice != 'N') && (choice != 'n'));
		cout << "\n";
		vector <string> &kingdoms = kingdom;
		vector <int>& sizes = size;
		int& kingdomsIndex = kingdomIndex;
		outputKingdomsandSizes(kingdomsIndex, kingdoms, size);

	}
	else {
		cout << "\nExiting... \n\n";

	}
}

void outputKingdomsandSizes(int& kingdomIndex, vector<string> &kingdoms, vector<int> &size)
{
	for (int i = 0; i < kingdomIndex; i++) {
		cout << kingdoms[i] << " has an army size of "<< size[i]<< "\n";
		cout << "\n";
	}
}

