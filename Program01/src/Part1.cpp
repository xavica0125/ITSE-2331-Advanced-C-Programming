#include "Part1.h"


bool characterAndDragonEntry()
{
	char choice;
	cout << "Would you like to enter a character (Y/N)? ";
	cin >> choice;
	if (choice == 'Y' || choice == 'y') {
		return true;
	}
}


void arrayLoop() {

	if (characterAndDragonEntry() == true) {
		const int MAX_CHARACTERS = 50;
		const int MAX_DRAGONS = 50;
		string characters[MAX_CHARACTERS][MAX_DRAGONS];
		int numDragons[MAX_CHARACTERS] = { 0 };
		int characterIndex = 0;
		char choice;

		do
		{
			cout << "Enter the character name: ";
			cin>> characters[characterIndex][0];

			cout << "How many dragons would you like to enter for the character? ";
			cin >> numDragons[characterIndex];

			for (int i = 1; i <= numDragons[characterIndex]; i++) {
				cout << "Enter the name of dragon " << i << ": ";
				cin >> characters[characterIndex][i];
			}
			characterIndex++;
			cout << "Would you like to enter another character (Y/N) ? ";
			cin >> choice;
		} while ((choice != 'N') && (choice != 'n'));
		cout << "\n";
		string(&characterArray)[MAX_CHARACTERS][MAX_DRAGONS] = characters;
		int(&dragonCount)[MAX_CHARACTERS] = numDragons;

		arrayOutput(characterIndex, dragonCount,characterArray);
	}
	else {
		cout << "\nExiting...\n\n";
	}
}

void arrayOutput(int& characterIndex, int (&numDragons)[50], string (&characters)[50][50])
{
	for (int i = 0; i < characterIndex; i++) {
		cout << characters[i][0] << " owns ";
		for (int j = 1; j <= numDragons[i]; j++) {
			if (j == numDragons[i]) {
				cout << characters[i][j];
			}
			else {
				cout << characters[i][j] << ", ";
			}
		}
		cout << "\n";
	}
	cout << "\n";
}
