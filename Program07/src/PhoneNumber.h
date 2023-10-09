#pragma once

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>

using std::cout; using std::cin; using std::string; using std::ostream; using std::istream; using std::ios; 

class PhoneNumber 
{
	friend ostream& operator<< (ostream&, const PhoneNumber&);
	friend istream& operator>> (istream&, PhoneNumber&);
	
	private: 
		char phone[15];
		char areaCode[4];
		char exchange[4];
		char line[5]; 
};
