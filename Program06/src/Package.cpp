#include "Package.h"

Package::Package(string senderName, string senderAddress, string senderCity, string senderState, string senderZip, string receiverName, string receiverAddress, string receiverCity, string receiverState, string receiverZip, double weight, double costPerOunce)
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

string Package::getReceiverName() const
{
	return receiverName;
}

string Package::getReceiverAddress() const
{
	return receiverAddress;
}

string Package::getReceiverCity() const
{
	return receiverCity;
}

string Package::getReceiverState() const
{
	return receiverState;
}

string Package::getReceiverZip() const
{
	return receiverZip;
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


void Package::setAdditionalShippingRate(const double rate)
{
}

double Package::getAdditionalShippingRate() 
{
	return 0.0;
}

string Package::displayInfo()
{
	ostringstream output;
	output << std::fixed << std::setprecision(2);

	output << "Displaying sender information: \n"
		<< "Sender Name: " << this->getSenderName() << "\n"
		<< "Sender Address: " << this->getSenderAddress() << "\n"
		<< "Sender City: " << this->getSenderCity() << "\n"
		<< "Sender State: " << this->getSenderState() << "\n"
		<< "Sender Zip: " << this->getSenderZip() << "\n"
		<< "\n"
		<< "Now displaying receiver information \n"
		<< "Receiver Name: " << this->getReceiverName() << "\n"
		<< "Receiver Address: " << this->getReceiverAddress() << "\n"
		<< "Receiver City: " << this->getReceiverCity() << "\n"
		<< "Receiver State: " << this->getReceiverState() << "\n"
		<< "Receiver Zip: " << this->getReceiverZip() << "\n"
		<< "\nPackage weight: " << this->getWeight() << "\n"
		<< "Package cost per ounce: " << this->getCostPerOunce() << "\n";
	if (this->getAdditionalShippingRate() != 0)
	{
		output << "Additional fee: " << this->getAdditionalShippingRate() << "\n";
	}
	output << "\nTotal cost to ship package: $" << this->calculateCost() << "\n";
	return output.str();
}












