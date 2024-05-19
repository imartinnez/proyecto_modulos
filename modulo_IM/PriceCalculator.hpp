#ifndef PRICE_CALCULATOR_HPP
#define PRICE_CALCUCLATOR_HPP

#include <iostream>
#include <string>
#include "../modulo_dev/Database.hpp"
#include "../modulo_IM/carModel.hpp"
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
    string carRangeLevel; //CLASE carModelList
    */
    int accidentSeverity; //DB
    int accidentNumber; //DB
    int weatherMultiplier; //DB
    
public:    
    PriceCalculator(Database db); //, string carRangeLevel, int accidentSeverity, int accidentNumber);
    double calculatePolicyBasePrice(carModel carDetails, string carRangeLevel, int driverLicenceAge, int policyType);
    double calculatePolicyPrice(string location, double basePrice);
    void calculatePriceNumberAccidents(double accidentCounter, double &basePrice);
    void calculatePriceSeverityAccidents(vector<vector<string>> data, vector<string> headers, string location, double &basePrice, int stateIndex, double totalAccidents, double accidentCounter);
    void calculatePriceWeatherAccidents(vector<vector<string>> data, vector<string> headers, string location, double &basePrice, int stateIndex, double accidentCounter);

};

#endif //PRICE_CALCULATOR_HPP