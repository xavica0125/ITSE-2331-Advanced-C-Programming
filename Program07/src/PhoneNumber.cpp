#include "PhoneNumber.h"

ostream& operator<<(ostream& output, const PhoneNumber& number)
{
	
	output << "Area code: " << number.areaCode << "\nExchange: "
		<< number.exchange << "\nLine: " << number.line << "\n"
		<< "(" << number.areaCode << ") " << number.exchange << "-"
		<< number.line << "\n";

	return output;
}

istream& operator>>(istream& input, PhoneNumber& number)
{
	// Receive input for phone array
	input.get(number.phone, sizeof(number.phone)); 
	// Error handling for insufficient characters
	if (std::strlen(number.phone) != 14) 
	{
		input.setstate(ios::failbit);
		cout << "There is an insufficient number of characters.\n";
	}
	// Error handling for area code or exchange beginning with 0 or 1. 
	else if ((number.phone[1] == '0' || number.phone[1] == '1') || (number.phone[6] == '0' || number.phone[6] == '1'))
	{
		input.setstate(ios::failbit);
		cout << "Area code or exchange can't begin with 0 or 1.\n";
	}
	// Copying area code, exchange, and line to appropriate arrays. 
	else
	{
		
		int phoneIdx = 0; int areaCodeIdx = 0; int exchangeIdx = 0; int lineIdx = 0;
		while (phoneIdx != sizeof(number.phone))
		{
			if (isdigit(number.phone[phoneIdx]))
			{
				if (phoneIdx > 0 && phoneIdx < 4)
				{
					if (areaCodeIdx < sizeof(number.areaCode))
					{
						number.areaCode[areaCodeIdx] = number.phone[phoneIdx];
						areaCodeIdx++;
					}
				}
				else if (phoneIdx >= 6 && phoneIdx <= 8)
				{
					if (exchangeIdx < sizeof(number.exchange))
					{
						number.exchange[exchangeIdx] = number.phone[phoneIdx];
						exchangeIdx++;
					}
				}
				else if (phoneIdx >= 10 && phoneIdx <= 13)
				{
					if (lineIdx < sizeof(number.line))
					{
						number.line[lineIdx] = number.phone[phoneIdx];
						lineIdx++;
					}
				}
			}
			phoneIdx++;
		}
		number.areaCode[areaCodeIdx] = '\0';
		number.exchange[exchangeIdx] = '\0';
		number.line[lineIdx] = '\0';

	}
	return input;
}