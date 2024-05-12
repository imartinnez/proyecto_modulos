#include "Policy.hpp"
using namespace std;

Policy::Policy(string name, string location, string carRangeLevel, int riskLevel, double price, vector<string> relevantDetails) {
    this->name = name;
    this->location = location;
    this->carRangeLevel = carRangeLevel;
    this->riskLevel = riskLevel;
    this->price = price;
    this->relevantDetails = relevantDetails;
}

string Policy::getName() {
    return name;
}

string Policy::getLocation() {
    return location;
}

string Policy::getcarRangeLevel() {
    return carRangeLevel;
}

int Policy::getRiskLevel() {
    return riskLevel;
}

double Policy::getPrice() {
    return price;
}

void updateDetails(vector<string> relevantDetails) {

    
}