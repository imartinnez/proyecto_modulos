#include "PriceCalculator.hpp"
using namespace std;

PriceCalculator::PriceCalculator(Database db, carModel carDetails, string location, int driverLicenceAge, int policyType, string carRangeLevel, int accidentSeverity, int accidentNumber, int weatherMultiplier) {
    this->db = db;
    /*
    this->carDetails = carDetails;
    this->location = location;
    this->driverLicenceAge = driverLicenceAge;
    this->policyType = policyType;
    */
    this->carRangeLevel = carRangeLevel;
    this->accidentSeverity = accidentSeverity;
    this->accidentNumber = accidentNumber;
    this->weatherMultiplier = weatherMultiplier;
}

double PriceCalculator::calculatePolicyBasePrice(carModel carDetails, string carRangeLevel, int driverLicenceAge, int policyType) {
    double basePrice;

    //calculo del precio base
    if(carRangeLevel == "luxury") {basePrice = 3000.0;}
    else if(carRangeLevel == "high") {basePrice = 1500.0;}
    else if(carRangeLevel == "medium") {basePrice = 800.0;}
    else {basePrice = 400.0;}

    //edad del conductor  (el caso medio no se pone, ya que mantiene el precio base)
    if(driverLicenceAge < 5) {basePrice += 400.0;}
    else if(driverLicenceAge >= 20) {basePrice -= 100.0;}

    //tipo de seguro
    if(policyType == 1) {basePrice *= 2.5;} //si es igual a 1, es decir, una poliza a todo riesgo, se aumenta un 150%

    //año del coche
    if(carDetails.year >= 4 && carDetails.year < 10) {basePrice += 100.0;}
    else if(carDetails.year >= 10) {basePrice += 300.0;}

    return basePrice;
}

double PriceCalculator::calculateLocationPolicyPrice(string location, double basePrice) {

    db.loadCSV();
    vector<vector<string>> data = db.getData();
    vector<string> headers = db.getHeaders();

    return 0;
}

