#ifndef DRIVER_HPP
#define DRIVERP_HPP

#include <iostream>
#include <string>
#include "modulo_dev/Database.hpp"
#include "carModel.hpp"
using namespace std;

class Driver {
private:
    string name;
    string location;
    carModel carDetails;

public:
    Driver(string name, string location, carModel carDetails);
    string getName();
    string getLocation();
    carModel getCarDetails();
    void setName(string name);
    void setLocation(string location);
    void setCarDetails(carModel carDetails);
    
    void calculatePrice();
    void generateFile();
    void setDetails();
    void setPolicyInfo();
    void getPolicyInfo();
};

#endif //DRIVER_PROFILE_HPP