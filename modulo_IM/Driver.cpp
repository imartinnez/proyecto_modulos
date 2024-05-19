#include "Driver.hpp"
using namespace std;

Driver::Driver(string name, string id, string licencePlate, string location, carModel carDetails, int policyType) {
    this->name = name;
    this->id = id;
    this->licencePlate = licencePlate;
    this->location = location;
    this->carDetails.brand = carDetails.brand;
    this->carDetails.year = carDetails.year;
    this->policyType = policyType;
}

void Driver::setPolicyPrice() {
    CarModelList cm(carDetails.brand, carDetails.year);
    string carRangeLevel = cm.getRangeLevel();

    Policy p(policyType, policyPrice, carRangeLevel, location, carDetails, driverLicenceAge);
    policyPrice = p.calculatePolicyPrice();
}

double Driver::getPolicyPrice() {
    return policyPrice;
}

void Driver::generatePolicyFile() {
    FileGenerator f(licencePlate, carDetails, name, id, policyPrice);
    f.generatePolicy();
}

void Driver::showPolicyFile() {
    FileGenerator f(licencePlate, carDetails, name, id, policyPrice);
    f.showPolicy();
} 


/*
string Driver::getName();
string Driver::getLocation();
int Driver::getDriverLicenceAge();
int Driver::getPolicyType();
double Driver::getPolicyPrice();
string Driver::getCarBrand();
int Driver::getCarYear();
void Driver::setName(string name);
void Driver::setLocation(string location);
void Driver::setDriverLicenceAge(int driverLicenceAge);
void Driver::setPolicyPrice(int policyType);
void Driver::setPolicyPrice(double policyPrice);
void Driver::setCarDetails(string brand, int year);

    

void Driver::setDetails();
void Driver::setPolicyInfo();
void Driver::getPolicyInfo();    
*/