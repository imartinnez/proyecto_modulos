#ifndef POLICY_HPP
#define POLICY_HPP

#include <iostream>
#include <string>
#include <vector>
#include "..//modulo_dev/Database.hpp"
#include "../modulo_IM/carModel.hpp"
#include "../modulo_IM/PriceCalculator.hpp"
using namespace std;

class Policy {
private:
    int policyType; //0-terceros    1-todo riesgo 
    double price;
    string carRangeLevel; // CLASE carModelList
    string location; //DRIVER
    carModel carDetails; //DRIVER
    int driverLicenceAge; //DRIVER
    

public:
    Policy(int policyType, double price, string carRangeLevel, string location, carModel cardetails, int driverLicenceAge);
    double calculatePolicyPrice();
    
    
};

#endif //POLICY_HPP