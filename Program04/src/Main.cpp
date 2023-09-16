#include "OverloadDemo.h"

#include <iostream>
#include <string>

using std::cout; using std::cin; using std::ostream; using std::string;

ostream& operator<<(ostream& out, const OverloadDemo& other);
void mainMenu();

int main()
{

	mainMenu();

}

ostream& operator<<(ostream& out, const OverloadDemo& other)
{
	out << other.getIntOne() << "\n" << other.getDoubleOne() << "\n" <<
		other.getStringOne() << "\n";
	return out;

}

void mainMenu()
{
	
	char choice;
	int num;
	double d;
	string s;
	string operatorArray[] = {"+" , "-", "*", "/", "++ Prefix", "Postfix ++", "-- Prefix", "Postfix--"};
	do
	{
		cout << "Welcome!\n";
		cout << "Enter integer OverloadDemo object 1: ";
		cin >> num;
		cout << "\nEnter double OverloadDemo object 1: ";
		cin >> d;
		cout << "\nEnter string OverloadDemo object 1: ";
		cin >> s;
		OverloadDemo demo1(num, d, s);
		cout << "\nEnter integer OverloadDemo object 2: ";
		cin >> num;
		cout << "\nEnter double OverloadDemo object 2: ";
		cin >> d;
		cout << "\nEnter string OverloadDemo object 2: ";
		cin >> s;
		OverloadDemo demo2(num, d, s);
		do
		{

			for (int i = 0; i < 8; i++)
			{
				cout << i + 1 << ". " << operatorArray[i] << "\n";
			}
			cout << "Choose an operation: ";
			cin >> choice;
			switch (choice)
			{
			case '1':
			{
				OverloadDemo result = demo1 + demo2;
				cout << result << "\n";
				break;
			}
			case '2':
			{
				OverloadDemo result = demo1 - demo2;
				cout << result << "\n";
				break;
			}
			case '3':
			{
				OverloadDemo result = demo1 * demo2;
				cout << result << "\n";
				break;
			}
			case '4':
			{
				OverloadDemo result = demo1 / demo2;
				cout << result << "\n";
				break;
			}
			case '5':
			{
				cout << "Which object would you like to increment? 1 or 2: ";
				cin >> choice;
				if (choice == '1')
				{
					cout << ++demo1 << "\n";

				}
				else if (choice == '2')
				{
					cout << ++demo2 << "\n";
				}
				break;
			}
			case '6':
			{
				cout << "Which object would you like to increment? 1 or 2: ";
				cin >> choice;
				if (choice == '1')
				{
					OverloadDemo result = demo1++;
					cout << result << "\n";
					cout << "Object 1 after Postfix ++ " << "\n";
					cout << demo1 << "\n";
				}
				else if (choice == '2')
				{
					OverloadDemo result = demo2++;
					cout << result << "\n";
					cout << "Object 2 after Postfix ++ " << "\n";
					cout << demo2 << "\n";
				}
				break;
			}
			case '7':
			{
				cout << "Which object would you like to decrement? 1 or 2: ";
				cin >> choice;
				if (choice == '1')
				{
					cout << --demo1 << "\n";
				}
				else if (choice == '2')
				{
					cout << --demo2 << "\n";
				}
				break;
			}
			case '8':
			{
				cout << "Which object would you like to decrement? 1 or 2: ";
				cin >> choice;
				if (choice == '1')
				{
					OverloadDemo result = demo1--;
					cout << result << "\n";
					cout << "Object 1 after Postfix -- " << "\n";
					cout << demo1 << "\n";
				}
				else if (choice == '2')
				{
					OverloadDemo result = demo2--;
					cout << result << "\n";
					cout << "Object 2 after Postfix -- " << "\n";
					cout << demo2 << "\n";
				}
				break;
			}
			}
			cout << "Would you like to continue? Y/N: ";
			cin >> choice;
		} while (choice != 'N' && choice != 'n');
		cout << "Would you like to enter new OverloadDemo objects? Y/N: ";
		cin >> choice;
	} while (choice != 'N' && choice != 'n');
	

}


