#include "TwoDayPackage.h"


void TwoDayPackage::setAdditionalShippingRate(const double twoDayFee)
{

	this->twoDayFee = twoDayFee;

}

double TwoDayPackage::getAdditionalShippingRate()
{
	return this->twoDayFee;
}

double TwoDayPackage::calculateCost()
{

	return getAdditionalShippingRate() + (Package::getCostPerOunce() * Package::getWeight());

}

string TwoDayPackage::displayInfo()
{
	ostringstream output;

	output << Package::displayInfo();

	return output.str();
}





