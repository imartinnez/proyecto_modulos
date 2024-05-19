#ifndef DRIVER_HPP
#define DRIVER_HPP

#include <iostream>
#include <string>
#include "../modulo_IM/carModel.hpp"
#include "../modulo_IM/CarModelList.hpp"
#include "../modulo_IM/FileGenerator.hpp"
using namespace std;

class Driver {
private:
    string name;
    string id;
    string licencePlate;
    string location;
    int driverLicenceAge;
    carModel carDetails;
    double policyPrice;
    int policyType;

public:
    Driver(string name, string id, string licencePlate, string location, carModel carDetails, int policyType);
    
    void setPolicyPrice();
    double getPolicyPrice();
    void generatePolicyFile();
    void showPolicyFile();
    /*
    string getName();
    string getLocation();
    int getDriverLicenceAge();
    int getPolicyType();
    double getPolicyPrice();
    string getCarBrand();
    int getCarYear();
    void setName(string name);
    void setLocation(string location);
    void setDriverLicenceAge(int driverLicenceAge);
    void setPolicyPrice(int policyType);
    void setPolicyPrice(double policyPrice);
    void setCarDetails(string brand, int year);
    

    
    void setPolicyInfo();
    void getPolicyInfo();
    void modifyPolicyInfo();
    
    */
};

#endif //DRIVER_PROFILE_HPP