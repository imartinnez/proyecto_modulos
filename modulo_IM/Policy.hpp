#ifndef POLICY_HPP
#define POLICY_HPP

#include <iostream>
#include <string>
#include <vector>
#include "modulo_dev/Database.hpp"
#include "carModel.hpp"
#include "PriceCalculator.hpp"
using namespace std;

class Policy {
private:
    string name;
    string location;
    carModel carDetails;
    string carRangeLevel; //un rango de low, medium, high, xhigh del coche
    int riskLevel;
    double price;
    vector<string> relevantDetails;

public:
    Policy(string name, string location, string carRangeLevel, int riskLevel, double price, vector<string> relevantDetails);
    string getName();
    string getLocation();
    string getcarRangeLevel();
    int getRiskLevel();
    double getPrice();
    void updateDetails(vector<string> relevantDetails);

};

#endif //POLICY_HPP