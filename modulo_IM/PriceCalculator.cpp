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
#include "PriceCalculator.hpp"
using namespace std;

PriceCalculator::PriceCalculator(Database db) {
    this->db = db;
}

double PriceCalculator::calculatePolicyBasePrice(carModel carDetails, string carRangeLevel, int driverLicenceAge, int policyType) {
    double basePrice;
    
    // Thanks to the ctime library, we get the current time and convert it into a tm structure
    time_t now = time(0);
    tm time = *localtime(&now);

    // We set the base price based on the status of the car
    if(carRangeLevel == "luxury") {basePrice = 2800.50;}
    else if(carRangeLevel == "high") {basePrice = 1470.00;}
    else if(carRangeLevel == "medium") {basePrice = 780.00;}
    else {basePrice = 390.50;}

    // If the driver’s license age is within a specific range, the base price will vary
    if(driverLicenceAge < 5) {basePrice += 415.20;}
    else if(driverLicenceAge >= 8) {basePrice -= 150.00;}

    // If the user decides to purchase a comprehensive insurance policy, the price will increase by 252%
    if(policyType == 1) {basePrice *= 2.52;} // since it is an int type, if it is 0 it will be third party, and if it is 1, it will be comprehensive

    // Depending on the car's year, the base price will vary
    if(((time.tm_year + 1900)-carDetails.year) >= 4 && ((time.tm_year + 1900)-carDetails.year) < 10) {basePrice += 100.00;}
    else if(carDetails.year >= 10) {basePrice += 300.00;}

    return basePrice;
}


double PriceCalculator::calculatePolicyPrice(double basePrice, string location) {
    int stateIndex;

    db.loadCSV();
    // Vector used to store accident rows
    vector<string> row;
    data = db.getData();
    headers = db.getHeaders();
    totalAccidents = data.size();

    // We go through the vector of headers to find the state index
    for(int h = 0; h < headers.size(); h++) {
        if(headers[h] == "State") {
            stateIndex = h;
            break;
        }
    }
    // We go through all the accident rows that match the location set by the user to count them
    for(int i = 0; i < data.size(); i++) {
        row = data[i];
        if(row[stateIndex] == location) {
            accidentCounter++;
        }
    }

    // We modify the final base price by calling the other functions with the established parameters
    calculatePriceNumberAccidents(basePrice);
    calculatePriceSeverityAccidents(basePrice, location, stateIndex);
    calculatePriceWeatherAccidents(basePrice, location, stateIndex);

    return basePrice;
}



void PriceCalculator::calculatePriceNumberAccidents(double &basePrice) {
    // Modifies the base price based on the number of accidents in a state
    if(accidentCounter < 1000) {basePrice -= 25.40;}
    else if(accidentCounter > 5000) {basePrice += 55.10;}
}



void PriceCalculator::calculatePriceSeverityAccidents(double &basePrice, string location,int stateIndex) {
    double severityAverage;        // average of the severity value of all accidents
    double severityValue;          // sum of the severity values of all accidents
    double severityCounter = 0.00; // sum of the severity values of a state
    int severityIndex;             // index of the Severity column
    vector<string> row;            // vector to store accident rows

    // We go through the vector of headers to find the severity index
    for(int s = 0; s < headers.size(); s++) {
        if(headers[s] == "Severity") {
            severityIndex = s;
            break;
        }
    }
    /**
     * In the rows corresponding to the state entered by the user, each value
     * in the severity column is added
     */
    for(int i = 0; i < data.size(); i++) {
        row = data[i];
        if(row[stateIndex] == location) {
            severityCounter +=  stoi(row[severityIndex]); // we use stoi() to convert the cells from string to int
        }
    }

    // We sum each value in the severity column of all accidents
    for(int i = 0; i < data.size(); i++) {
        row = data[i];
        severityValue += stoi(row[severityIndex]);
    }

    // We calculate the average severity of all accidents
    severityAverage = severityValue/totalAccidents; // calculation of the sum of Severity of all accidents divided by the number of accidents

    // If the average severity of the user's state is less than the global average severity, the base price is modified
    if(severityCounter/accidentCounter < severityAverage) {
        basePrice -= 50.00;
    }
}



void PriceCalculator::calculatePriceWeatherAccidents(double &basePrice, string location, int stateIndex) {
    int weatherIndex;         // index of the Weather_Condition column
    double weatherCounter;    // sum of the values of the weatherConditions
    double weatherMultiplier; // multiplier applied to the base price, obtained from the formula
    vector<string> row;       // vector to store accident rows

    // We go through the vector of headers to find the weather index
    for(int w = 0; w < headers.size(); w++) {
        if(headers[w] == "Weather_Condition") {
            weatherIndex = w;
            break;
        }
    }

    /**
     * We analyze cell by cell in the weather condition column of the user's state
     * and compare them with the various options in the column, if it matches any
     * the respective counter is added to the variable that accumulates them. Counter table:
     
     * Fair          -----------------> 1
     * Fog           -----------------> 2
     * Hail          -----------------> 4
     * Heavy Rain    -----------------> 4
     * Heavy Snow    -----------------> 5
     * Rain          -----------------> 2
     * Snow          -----------------> 3 
     * Tornado       -----------------> 6
     * T-Storm       -----------------> 3   
     */
    for(int i = 0; i < data.size(); i++) {
        row = data[i];
        if(row[stateIndex] == location) {
            if(row[weatherIndex] == "Tornado") {weatherCounter += 6.00;}
            else if(row[weatherIndex] == "Heavy Snow") {weatherCounter += 5.00;}
            else if(row[weatherIndex] == "Heavy Rain" || row[weatherIndex] == "Hail") {weatherCounter += 4.00;}
            else if(row[weatherIndex] == "T-Storm" || row[weatherIndex] == "Snow") {weatherCounter += 3.00;}
            else if(row[weatherIndex] == "Rain" || row[weatherIndex] == "Fog") {weatherCounter += 2.00;}
            else {weatherCounter += 1.00;}
        }
    }

    // We calculate the weather multiplier by dividing the sum of the counters by the total number of accidents in the state
    weatherMultiplier = (weatherCounter/accidentCounter);
    basePrice *= weatherMultiplier;
}