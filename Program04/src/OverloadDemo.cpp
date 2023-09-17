#include "OverloadDemo.h"


void OverloadDemo::decrementString()
{
	stringOne = stringOne.substr(0, stringOne.length() - 1);
}

void OverloadDemo::setIntOne(int)
{

	this->intOne = intOne;

}

void OverloadDemo::setDoubleOne(double)
{

	this->doubleOne = doubleOne;

}

void OverloadDemo::setStringOne(string)
{

	this->stringOne = stringOne;

}

int OverloadDemo::getIntOne() const
{

	return intOne;

}

double OverloadDemo::getDoubleOne() const
{

	return doubleOne;

}

string OverloadDemo::getStringOne() const
{

	return stringOne;

}

OverloadDemo OverloadDemo::operator+(const OverloadDemo& other) const
{

	OverloadDemo result(intOne + other.intOne, doubleOne + other.doubleOne, stringOne + other.stringOne);
	return result;

}

OverloadDemo OverloadDemo::operator-(const OverloadDemo& other) const
{
	string str = other.stringOne + stringOne;
	OverloadDemo result(intOne - other.intOne, doubleOne - other.doubleOne, str);
	return result;

}

OverloadDemo OverloadDemo::operator*(const OverloadDemo& other) const
{
	string str;
	int maxLength = (stringOne.length() > other.stringOne.length()) ? stringOne.length() : other.stringOne.length();
	for (int i = 0; i < maxLength; i++)
	{
		if (i < stringOne.length())
		{
			str += stringOne[i];
		}
		if (i < other.stringOne.length())
		{
			str += other.stringOne[i];
		}
		
	}
	OverloadDemo result(intOne * other.intOne, doubleOne * other.doubleOne, str);
	return result;

}

OverloadDemo OverloadDemo::operator/(const OverloadDemo& other) const
{
	int res;
	if (stringOne.length() > other.stringOne.length())
	{
		res = stringOne.length() / other.stringOne.length();
	}
	else
	{
		res = other.stringOne.length() / stringOne.length();
	}
	string str = std::to_string(res);
	OverloadDemo result(intOne / other.intOne, doubleOne / other.doubleOne, str);
	return result;

}


OverloadDemo& OverloadDemo::operator++()
{
	this->intOne++;
	this->doubleOne++;
	this->stringOne += "++";

	return *this;
}


OverloadDemo OverloadDemo::operator++(int)
{
	OverloadDemo temp = *this;
	this->intOne++;	
	this->doubleOne++;
	this->stringOne += "++";
	
	return temp;
}


OverloadDemo& OverloadDemo::operator--()
{
	this->intOne--;
	this->doubleOne--;
	decrementString();
	
	return *this;
}


OverloadDemo OverloadDemo::operator--(int)
{
	OverloadDemo temp = *this;
	this->intOne--;
	this->doubleOne--;
	decrementString();

	return temp;
	
}

