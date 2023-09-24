#pragma once

#include "Package.h"

class TwoDayPackage : public Package
{
	friend ostream& operator<<(ostream& out, TwoDayPackage& package);

	private:
		
		double twoDayFee;

	public:
		
		using Package::Package;
		
		void setTwoDayFee(const double twoDayFee);

		double getTwoDayFee() const;

		double calculateCost();

};
