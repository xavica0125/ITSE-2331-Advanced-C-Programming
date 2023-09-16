#pragma once

#include <iostream>
#include <string>

using std::string; using std::ostream;

class OverloadDemo
{
	friend ostream& operator<<(ostream& out, const OverloadDemo& other);

private:
	
	int intOne;
	double doubleOne;
	string stringOne;
	void decrementString();

public:
	
	OverloadDemo() 
	{	
		intOne = 0;
		doubleOne = 0.0;
		stringOne = "";
	};


	OverloadDemo(int num, double d, string s)
	{
		intOne = num;
		doubleOne = d;
		stringOne = s;
	};


	void setIntOne(int);
	void setDoubleOne(double);
	void setStringOne(string);

	int getIntOne() const;
	double getDoubleOne() const;
	string getStringOne() const;

	OverloadDemo operator+(const OverloadDemo& other) const ;
	OverloadDemo operator-(const OverloadDemo& other) const;
	OverloadDemo operator*(const OverloadDemo& other) const;
	OverloadDemo operator/(const OverloadDemo& other)const;
	OverloadDemo& operator++();
	OverloadDemo operator++(int);
	OverloadDemo& operator--();
	OverloadDemo operator--(int);




};