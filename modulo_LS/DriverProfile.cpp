/**
 * @author: Luis Sánchez
 * 
 * @module: modulo_LS
 * 
 * @class DriverProfile
 * 
 * The class DriverProfile is used to make a profile based on a
 * question form that saves the preferences of the drivers
 */
#include "DriverProfile.hpp"

using namespace std;

void DriverProfile::collectPreferences(){
    string response;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "                  QUESTION FORM: TRAFFIC PREFERENCES                 " << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "Do you consider the impact on traffic (severity) of accidents? (yes/no):";
    cin >> response;
    //change the bool variable to 'true' if the user writes 'yes'
    considerTrafficImpact = (response == "yes");

    cout << "Do you consider the number of accidents in the city? (yes/no):";
    cin >> response;
    considerCityAccidents = (response == "yes");

    cout << "Do you consider the number of accidents in the county? (yes/no):";
    cin >> response;
    considerCountyAccidents = (response == "yes");
    cout << "---------------------------------------------------------------------" << endl;
}

string DriverProfile::recommendCity(vector<string> cities, Database db, CityComparator cityComparator){
    //create a map to store the mean severity of each city
    map<string, double> citySeverities = cityComparator.CalculateSeverityMeanByCity(db);
    //this city is assumed to handle city methods related
    City cityE;
    string bestCity = "";
    double highestScore = -1;
    for( string city : cities){
        double score = 0;
        if(considerTrafficImpact){
            //check if the severity data of the cities is available
            if(citySeverities.find(city) != citySeverities.end()){
                //adds to the score based on the ccity's severity, if the severity is low, increases the score
                score += (4.0 - citySeverities[city]);
            }
        }
        if(considerCityAccidents){
            int cityAccidents = cityE.CountAccidentsInCity(city, db);
            //fewer accidents, increase the score
            score += 100.0 / (cityAccidents + 1);
        }
        if(considerCountyAccidents){
            string county = cityE.getCountyByCity(city, db);
            int countyAccidents = cityE.CountAccidentsInCounty(county, db);
            score += 100.0 / (countyAccidents + 1);
        }
        if(score > highestScore){
            //check if the current 'score' is higher than 'highest score'
            highestScore = score;
            bestCity = city;
        }

    }
    return bestCity;

}