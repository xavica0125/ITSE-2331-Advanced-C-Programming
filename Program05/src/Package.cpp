#include "Package.h"

Package::Package(string senderName, string senderAddress, string SenderCity, string senderState, string senderZip, string receiverName, string receiverAddress, string receiverCity, string receiverState, string receiverZip, double weight, double costPerOunce)
{

	this->senderName = senderName;
	this->senderAddress = senderAddress;
	this->senderCity = senderCity;
	this->senderState = senderState;
	this->senderZip = senderZip;
	this->receiverName = receiverName;
	this->receiverAddress = receiverAddress;
	this->receiverCity = receiverCity;
	this->receiverState = receiverState;
	this->receiverZip = receiverZip;
	this->weight = weight;
	this->costPerOunce = costPerOunce;

}

void Package::setSenderName(const string& senderName)
{

	this->senderName = senderName;

}

void Package::setSenderAddress(const string& senderAddress)
{

	this->senderAddress = senderAddress;

}

void Package::setSenderCity(const string& senderCity)
{

	this->senderCity = senderCity;

}

void Package::setSenderState(const string& senderState)
{

	this->senderState = senderState;

}

void Package::setSenderZip(const string& senderZip)
{

	this->senderZip = senderZip;

}

void Package::setWeight(const double weight)
{

		double ounces = weight * 16;
		this->weight = ounces;
	
}

void Package::setCostPerOunce(const double costPerOunce)
{

		this->costPerOunce = costPerOunce;

}

string Package::getSenderName() const
{

	return senderName;

}

string Package::getSenderAddress() const
{

	return senderAddress;

}

string Package::getSenderCity() const
{

	return senderCity;

}

string Package::getSenderState() const
{
	
	return senderState;

}

string Package::getSenderZip() const
{
	
	return senderZip;

}

double Package::getWeight() const
{
	
	return weight;

}

double Package::getCostPerOunce() const
{
	
	return costPerOunce;

}

double Package::calculateCost()
{
	
	return getWeight() * getCostPerOunce();

}











