#include "OvernightPackage.h"

void OvernightPackage::setOvernightRate(const double overnightRate)
{

	this->overnightRate = overnightRate;

}

double OvernightPackage::getOvernightRate()
{
	
	return overnightRate;

}

double OvernightPackage::calculateCost()
{

	return (overnightRate + Package::getCostPerOunce()) * Package::getWeight();
}

