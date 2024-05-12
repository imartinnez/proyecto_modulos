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
    int driverAge;
    string carRangeLevel;
    int riskLevel;
    int accidentSeverity;
    int areaFrecuency;
    string weatherCondition;
    
public:    
    PriceCalculator(Database db, int driverAge, string carRangeLevel, int riskLevel, int accidentSeverity, int areaFrecuency, string weatherCondition);
    int calculatePolityPrice(Database db, string carRangeLevel, int riskLevel, int accidentSeverity, int areaFrecuency, string weatherCondition);
};

#endif //PRICE_CALCULATOR_HPP