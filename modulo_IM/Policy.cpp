/**
 * @author: Iñigo Martínez
 * 
 * Module: modulo_IM
 * 
 * @class Policy
 * 
 * This class contains detailed information about the policy, including the type of policy, the price, 
 * the car's range level, the location, the car details, and the driver's license age among other things. 
 * Additionally, it invokes methods from the PriceCalculator class to calculate the policy price.
 */
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
    //Instantiate an object of the Database and PriceCalculator classes
    Database db;
    PriceCalculator pc(db);

    //We calculate the price of the policy by using the methods of the PriceCalculator class
    price = pc.calculatePolicyBasePrice(carDetails, carRangeLevel, driverLicenceAge, policyType);
    pc.calculatePolicyPrice(price, location);

    return price;
}