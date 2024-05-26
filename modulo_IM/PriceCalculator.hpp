/**
 * @author: Iñigo Martínez
 * 
 * Module: modulo_IM
 * 
 * @class PriceCalculator
 * 
 * This class is responsible for calculating the base price and the final price of an insurance policy
 * for a car, taking into account various factors such as accident history,
 * location, driver's license age, and type of policy.
 */
#ifndef PRICE_CALCULATOR_HPP
#define PRICE_CALCULATOR_HPP

#include <iostream>  // To use cout, cin...
#include <string>    // To handle strings
#include <ctime>     // To use time()
#include "../modulo_Database/Database.hpp"
#include "../modulo_IM/carModel.hpp"
using namespace std;

class PriceCalculator {
private:
    Database db;                  // Object of the Database class
    vector<vector<string>> data;  // Vector of vectors of strings to store database data
    vector<string> headers;       // Vector of type string that stores the data headers
    double totalAccidents;        // Total accidents recorded from all data
    double accidentCounter;       // Accident counter in a specific state

public:    
    /**
     * Constructor of the PriceCalculator class.
     */
    PriceCalculator(Database db);

    /**
     * Calculates the base price of a policy.
     * 
     * 
     * @param carDetails Structured data type carModel with car details.
     * @param carRangeLevel Car status.
     * @param driverLicenceAge Driver's license age.
     * @param policyType Type of policy.
     * 
     * @return The base price of the policy.
     */
    double calculatePolicyBasePrice(carModel carDetails, string carRangeLevel, int driverLicenceAge, int policyType);

    /**
     * Calculates the final price of a policy based on the base price and location.
     * 
     * @param basePrice Base price of the policy.
     * @param location Insured's location.
     * 
     * @return The final price of the policy.
     */
    double calculatePolicyPrice(double basePrice, string location);

    /**
     * Calculates the adjustment of the base price based on the number of accidents.
     * 
     * @param basePrice Base price of the policy.
     */
    void calculatePriceNumberAccidents(double &basePrice);

    /**
     * Calculates the adjustment of the base price based on the severity of accidents in a State.
     * 
     * @param basePrice Base price of the policy.
     * @param location Insured's location.
     * @param stateIndex Index of the State column in the database
     */
    void calculatePriceSeverityAccidents(double &basePrice, string location, int stateIndex);

    /**
     * Calculates the adjustment of the base price based on weather conditions in a State.
     * 
     * @param basePrice Base price of the policy.
     * @param location Insured's location.
     * @param stateIndex Index of the State column in the database
     */
    void calculatePriceWeatherAccidents(double &basePrice, string location, int stateIndex);
};

#endif // PRICE_CALCULATOR_HPP

