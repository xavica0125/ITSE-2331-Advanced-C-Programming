#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using std::string; using std::ostream; using std::ostringstream;

class Package
{

	private:
		string senderName;
		string senderAddress;
		string senderCity;
		string senderState;
		string senderZip;
		string receiverName;
		string receiverAddress;
		string receiverCity;
		string receiverState;
		string receiverZip;
		double weight{ 0 };
		double costPerOunce{ 0 };

	public:

		Package(string senderName, string senderAddress, string SenderCity, string senderState, string senderZip, string receiverName, string receiverAddress, string receiverCity, string receiverState, string receiverZip, double weight, double costPerOunce);

		void setSenderName(const string& senderName);
		void setSenderAddress(const string& senderAddress);
		void setSenderCity(const string& senderCity);
		void setSenderState(const string& senderState);
		void setSenderZip(const string& senderZip);
		void setWeight(const double weight);
		void setCostPerOunce(const double costPerOunce);

		string getSenderName() const;
		string getSenderAddress() const;
		string getSenderCity() const;
		string getSenderState() const;
		string getSenderZip() const;

		string getReceiverName() const;
		string getReceiverAddress() const;
		string getReceiverCity() const;
		string getReceiverState() const;
		string getReceiverZip() const;

		double getWeight() const;
		double getCostPerOunce() const;

		// Virtual function that calculates cost to ship specific package.
		virtual double calculateCost();	

		// Virtual function to set additional shipping rates for Two Day and Overnight shipping.
		virtual void setAdditionalShippingRate(const double rate); 
		
		// Virtual function returns additional shipping rate double class member
		virtual double getAdditionalShippingRate(); 

		// Virtual function returns all package information.
		virtual string displayInfo();  

		virtual ~Package() = default;
};