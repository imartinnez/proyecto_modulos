/**
 * @author: Iñigo Martínez
 * 
 * Module: modulo_IM
 * 
 * @class Driver
 * 
 * This class contains detailed information about a driver, including their name,
 * ID, vehicle license plate, location, driver license age, car details, and policy price.
 * It also provides methods to manage and display the driver's information and their policy.
 */
#ifndef DRIVER_HPP
#define DRIVER_HPP

#include <iostream>   // To use cout, cin...
#include <string>     // To handle strings
#include <unistd.h>  // To use the sleep() function
#include "../modulo_IM/carModel.hpp"
#include "../modulo_IM/CarModelList.hpp"
#include "../modulo_IM/FileGenerator.hpp"
using namespace std;

class Driver {
private:
    string name;          // Driver's name.
    string id;            // Driver's ID.
    string licencePlate;  // Driver's vehicle license plate.
    string location;      // Driver's location.
    int driverLicenceAge; // Driver's license age.
    carModel carDetails;  // Driver's car details.
    double policyPrice;   // Insurance policy price.
    int policyType;       // Policy type: 0 for third party, 1 for comprehensive.

public:
    /**
     * Constructor for the Driver class.
     */
    Driver(string name, string id, string licencePlate, string location, int driverLicenceAge, carModel carDetails, int policyType);

    /**
     * This method calculates and assigns the insurance policy price based on the driver's
     * information and the policy type by invoking methods from the Policy and CarModelList classes.
     */
    void setPolicyPrice();

    /**
     * Gets the policy price.
     * 
     * @return The insurance policy price.
     */
    double getPolicyPrice();

    /**
     * Displays the driver's details.
     * 
     * @param policyCalculated Indicates if the policy price has been calculated.
     */
    void showDriverDetails(bool policyCalculated);

    /**
     * This method allows updating the driver's information.
     */
    void updateDriverDetails();

    /**
     * This method creates a .txt file that will store the driver's insurance policy information.
     */
    void generatePolicyFile();

    /**
     * This method displays the contents of the insurance policy .txt file.
     */
    void showPolicyFile();
};

#endif // DRIVER_PROFILE_HPP

