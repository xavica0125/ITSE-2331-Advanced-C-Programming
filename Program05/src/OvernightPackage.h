#pragma once

#include "Package.h"

class OvernightPackage : public Package
{

	friend ostream& operator<<(ostream& out, OvernightPackage& package);

	private:

		double overnightRate;

	public:

		using Package::Package;

		void setOvernightRate(const double overnightRate);

		double getOvernightRate();

		double calculateCost();

};