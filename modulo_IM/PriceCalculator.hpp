#ifndef PRICE_CALCULATOR_HPP
#define PRICE_CALCUCLATOR_HPP

#include <iostream>
#include <string>
#include "modulo_dev/Database.hpp"
#include "carModel.hpp"
using namespace std;

class PriceCalculator {
private:
    Database db;
    double basePrice;
    /*
    carModel carDetails; //DRIVER
    string location; //DRIVER
    int driverLicenceAge; //DRIVER
    int policyType; // DRIVER    0-terceros    1-todo riesgo 
    */
    string carRangeLevel; //CLASE carModelList
    int accidentSeverity; //DB
    int accidentNumber; //DB
    int weatherMultiplier; //DB
    
public:    
    PriceCalculator(Database db, carModel carDetails, string location, int driverLicenceAge, int policyType, string carRangeLevel, int accidentSeverity, int accidentNumber, int weatherMultiplier);
    double calculatePolicyBasePrice(carModel carDetails, string carRangeLevel, int driverLicenceAge, int policyType);
    double calculateLocationPolicyPrice(string location, double basePrice);
};

#endif //PRICE_CALCULATOR_HPP