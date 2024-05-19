#include "Policy.hpp"
using namespace std;

Policy::Policy(int policyType, double price, string carRangeLevel, string location, carModel cardetails, int driverLicenceAge) {
    this->policyType = policyType;
    this->price = price;
    this->carRangeLevel = carRangeLevel;
    this->location = location;
    this->carDetails.brand = carDetails.brand;
    this->carDetails.year = carDetails.year;
    this->driverLicenceAge = driverLicenceAge;
}

double Policy::calculatePolicyPrice() {
    Database db;
    PriceCalculator pc(db);

    price = pc.calculatePolicyBasePrice(carDetails, carRangeLevel, driverLicenceAge, policyType);
    pc.calculatePolicyPrice(location, price);

    return price;
}