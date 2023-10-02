#include "OvernightPackage.h"

void OvernightPackage::setAdditionalShippingRate(const double overnightRate)
{

	this->overnightRate = overnightRate;

}

double OvernightPackage::getAdditionalShippingRate()
{
	return this->overnightRate;
}

double OvernightPackage::calculateCost()
{

	return (getAdditionalShippingRate() + Package::getCostPerOunce()) * Package::getWeight();
}

string OvernightPackage::displayInfo()
{
	ostringstream output;

	output << Package::displayInfo();
	
	return output.str();
}



