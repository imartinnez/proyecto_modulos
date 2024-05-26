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
#ifndef POLICY_HPP
#define POLICY_HPP

#include <iostream>  // To use cout, cin...
#include <vector>    // To use vector<>
#include <string>    // To handle strings
#include "../modulo_IM/carModel.hpp"
#include "../modulo_IM/PriceCalculator.hpp"
using namespace std;

class Policy {
private:
    int policyType;       // Type of policy: 0 for third-party, 1 for comprehensive.
    double price;         // Policy price.
    string carRangeLevel; // Car status level.
    string location;      // Insured's location.
    carModel carDetails;  // Insured car details.
    int driverLicenceAge; // Driver's license age.

public:
    /**
     * Policy class constructor.
     */
    Policy(int policyType, double price, string carRangeLevel, string location, carModel carDetails, int driverLicenceAge);

    /**
     * Calculates the policy price by invoking methods from the PriceCalculator class.
     * 
     * @return The calculated policy price.
     */
    double calculatePolicyPrice();
};

#endif // POLICY_HPP
