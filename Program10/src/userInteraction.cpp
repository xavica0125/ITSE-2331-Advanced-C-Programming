#include "userInteraction.h"

void mainMenu()
{
	int topLevelChoice;
	do {
		cout << "Choose a container type: \n"
			<< "1. Modifying sequence algorithms\n"
			<< "2. Non modifying sequence algorithms\n"
			<< "3. Sorting and related algorithms\n"
			<< "4. Numerical algorithms\n"
			<< "0. Exit\n"
			<< "Enter choice: ";
		cin >> topLevelChoice;

		switch (topLevelChoice) {
		case 1:  // Sequence Containers
			int modSequenceChoice;
			do {
				cout << "Choose a modifiable sequence algorithm: \n"
					<< "1. generate\n"
					<< "2. fill_n\n"
					<< "3. replace_if\n"
					<< "4. swap_ranges\n"
					<< "0. Go back\n"
					<< "Enter choice: ";
				cin >> modSequenceChoice;

				modAlgoChoice(modSequenceChoice);

			} while (modSequenceChoice != 0);
			break;
		case 2:  // Ordered Associative Containers
			int nonModSequenceChoice;
			do {
				cout << "Choose an non modifiable sequence algorithm: \n"
					<< "1. find\n"
					<< "2. count\n"
					<< "3. equal\n"
					<< "4. for_each\n"
					<< "0. Go back\n"
					<< "Enter choice: ";
				cin >> nonModSequenceChoice;

				nonModAlgoChoice(nonModSequenceChoice);

			} while (nonModSequenceChoice != 0);
			break;
		case 3:  // Unordered Associative Containers
			int sortingAlgorithmsChoice;
			do {
				cout << "Choose a sorting or related algorithm: \n"
					<< "1. binary_search\n"
					<< "2. upper_bound\n"
					<< "3. set_difference\n"
					<< "4. sort\n"
					<< "5. set_union\n"
					<< "6. equal_range\n"
					<< "0. Go back\n"
					<< "Enter choice: ";
				cin >> sortingAlgorithmsChoice;

				sortingAlgoChoice(sortingAlgorithmsChoice);

			} while (sortingAlgorithmsChoice != 0);
			break;
		case 4: // Container Adapters
			int numericalAlgorithmsChoice;
			do {
				cout << "Choose a numerical algorithm: \n"
					<< "1. accumulate\n"
					<< "2. transform\n"
					<< "0. Go back\n"
					<< "Enter choice: ";
				cin >> numericalAlgorithmsChoice;

				numericalAlgoChoice(numericalAlgorithmsChoice);

			} while (numericalAlgorithmsChoice!= 0);
			break;
		}
	} while (topLevelChoice != 0);
}