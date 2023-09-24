#include "TwoDayPackage.h"


void TwoDayPackage::setTwoDayFee(const double twoDayFee)
{

	this->twoDayFee = twoDayFee;

}

double TwoDayPackage::getTwoDayFee() const
{

	return twoDayFee;

}

double TwoDayPackage::calculateCost()
{

	return twoDayFee + (Package::getCostPerOunce() * Package::getWeight());

}



