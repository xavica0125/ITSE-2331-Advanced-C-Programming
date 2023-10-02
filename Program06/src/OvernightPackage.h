#pragma once

#include "Package.h"

class OvernightPackage : public Package
{

	private:

		double overnightRate;

	public:

		using Package::Package;

		virtual void setAdditionalShippingRate(const double overnightRate) override;

		virtual double getAdditionalShippingRate() override;

		virtual double calculateCost() override;

		virtual string displayInfo() override;

		virtual ~OvernightPackage() = default;
};