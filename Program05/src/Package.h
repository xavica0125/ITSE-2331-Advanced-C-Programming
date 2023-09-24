#pragma once

#include <string>

using std::string; using std::ostream;

class Package
{
	friend ostream& operator<<(ostream& out, Package& package);

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
		double getWeight() const;
		double getCostPerOunce() const;

		double calculateCost();	

};