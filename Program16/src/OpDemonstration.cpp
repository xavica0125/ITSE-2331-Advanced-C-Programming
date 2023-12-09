#include "OpDemonstration.h"

void demonstrateStructs()
{
	struct Person
	{
		string name;
		int age;
		float salary;
	};

	Person p1;
	cout << "\nEnter full name: ";
	cin >> p1.name;
	cout << "\nEnter age: ";
	cin >> p1.age;
	cout << "\nEnter salary: ";
	cin >> p1.salary;

	cout << "\n\nDisplaying information.\n";
	cout << "Name: " << p1.name << "\n";
	cout << "Age: " << p1.age << "\n";
	cout << "Salary: " << p1.salary << "\n\n";
}

void demonstrateBitwiseOperators()
{
    unsigned int a, b;
    
    cout << "\nEnter positive integer: ";
    cin >> a;
    cout << "\nEnter another positive integer: ";
    cin >> b;

 
    int result = a & b;
    cout << "\nBitwise AND: " << result << "\n";

 
    result = a | b;  
    cout << "\nBitwise OR: " << result << "\n";

 
    result = a ^ b;
    cout << "\nBitwise XOR: " << result << "\n";

  
    result = ~a;  
    cout << "\nBitwise NOT: " << result << "\n";

    
    result = a << 1;  
    cout << "\nBitwise left shift: " << result << "\n";

   
    result = a >> 1;  
    cout << "\nBitwise right shift: " << result << "\n\n";
        
}

void demonstrateCharHandling()
{
    char c;
	cout << "\nEnter a character: ";
	cin >> c;
	cout << "\n\nThe character you entered is: " << c << "\n";
	cout << "\nThe ASCII value of the character is: " << (int)c << "\n";
	cout << "\nThe character in uppercase is: " << (char)toupper(c) << "\n";
	cout << "\nThe character in lowercase is: " << (char)tolower(c) << "\n\n";
}

void demonstrateCstringHandling()
{
    char str[100];
	cout << "Enter a string: ";
	cin >> str;
	cout << "\n\nThe string you entered is: " << str << "\n";
	cout << "\nThe length of the string is: " << strlen(str) << "\n";
	cout << "\nThe string in reverse is: " << _strrev(str) << "\n";
}

void demonstrateCstringSearch()
{
    char str[100];
	cout << "Enter a string: ";
	cin >> str;
	cout << "\nThe string you entered is: " << str << "\n";
	
    char substr[100];
	cout << "\nEnter a substring to search for: ";
	cin >> substr;
	cout << "\nThe substring you entered is: " << substr << "\n"; 

    char* result = strstr(str, substr);
	if (result != nullptr)
	{
		cout << "\nThe substring was found at position: " << result - str << "\n";
	}
	else
	{
		cout << "\nThe substring was not found.\n";
	}

}

void demonstrateCstringMemory()
{
	char str[100];
	cout << "\nEnter a string: ";
	cin >> str;
	
	char charToFind;
	cout << "\nEnter a character to search for: ";
	cin >> charToFind;

	cout << "\n\nThe string you entered is: " << str << "\n";
	cout << "\nFirst occurrence of  " << charToFind << " found at: " << static_cast<char*>(memchr(str, charToFind, strlen(str))) << "\n";
}


