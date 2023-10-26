#include "userInteraction.h"


void mainMenu() 
{
    int topLevelChoice;
    do {
            cout << "Choose a container type: \n"
            << "1. Sequence Containers\n"
            << "2. Ordered Associative Containers\n"
            << "3. Unordered Associative Containers\n"
            << "4. Container Adapters\n"
            << "0. Exit\n"
            << "Enter choice: ";
            cin >> topLevelChoice;

			switch (topLevelChoice) {
			case 1:  // Sequence Containers
				int sequenceChoice;
				do {
					cout << "Choose a sequence container: \n"
						<< "1. array\n"
						<< "2. deque\n"
						<< "3. forward-list\n"
						<< "4. list\n"
						<< "5. vector\n"
						<< "0. Go back\n"
						<< "Enter choice: ";
					cin >> sequenceChoice;

					sequenceContainerChoice(sequenceChoice);

				} while (sequenceChoice != 0);
				break;
			case 2:  // Ordered Associative Containers
				int orderedChoice;
				do {
					cout << "Choose an ordered associative container: \n"
						<< "1. set\n"
						<< "2. multiset\n"
						<< "3. map\n"
						<< "4. multimap\n"
						<< "0. Go back\n"
						<< "Enter choice: ";
					cin >> orderedChoice;

					orderedAssociativeChoice(orderedChoice);

				} while (orderedChoice != 0);
				break;
			case 3:  // Unordered Associative Containers
				int unorderedChoice;
				do {
					cout << "Choose an unordered associative container: \n"
						<< "1. unordered_set\n"
						<< "2. unordered_multiset\n"
						<< "3. unordered_map\n"
						<< "4. unordered_multimap\n"
						<< "0. Go back\n"
						<< "Enter choice: ";
					cin >> unorderedChoice;

					unorderedAssociativeChoice(unorderedChoice);

				} while (unorderedChoice != 0);
				break;
			case 4: // Container Adapters
				int adapterChoice;
				do {
					cout << "Choose a container adaper: \n"
						<< "1. stack\n"
						<< "2. queue\n"
						<< "3. priority queue\n"
						<< "0. Go back\n"
						<< "Enter choice: ";
					cin >> adapterChoice;

					containerAdapterChoice(adapterChoice);

				} while (adapterChoice != 0);
				break;
			}
    }while (topLevelChoice != 0);
    
}
