#include "PriceCalculator.hpp"
using namespace std;

PriceCalculator::PriceCalculator(Database db, int driverAge, string carRangeLevel, int riskLevel, int accidentSeverity, int areaFrecuency, string weatherCondition) {
    this->db = db;
    this->driverAge= driverAge;
    this->carRangeLevel = carRangeLevel;
    this->riskLevel = riskLevel;
    this->accidentSeverity = accidentSeverity;
    this->areaFrecuency = areaFrecuency;
    this->weatherCondition = weatherCondition;
}

int PriceCalculator::calculatePolityPrice(Database db, string carRangeLevel, int riskLevel, int accidentSeverity, int areaFrecuency, string weatherCondition) {

    return 0;
}