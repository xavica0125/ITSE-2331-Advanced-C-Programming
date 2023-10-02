#pragma once

#include "Package.h"

class TwoDayPackage : public Package
{

	private:
		
		double twoDayFee;

	public:
		
		using Package::Package;
		
		virtual void setAdditionalShippingRate(const double twoDayFee) override;

		virtual double getAdditionalShippingRate() override;

		virtual double calculateCost() override;

		virtual string displayInfo() override;

		virtual ~TwoDayPackage() = default;
};
