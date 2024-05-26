/**
 * @author: Luis Sánchez
 * 
 * Module: modulo_LS
 * 
 * @class main_LS
 * 
 * This class is responsible for gathering all the functionalities of the other
 * classes in the modulo_LS module.
 */
#include "../modulo_Database/Database.hpp"
#include "../modulo_LS/City.hpp"
#include "../modulo_LS/CityComparator.hpp"
#include "../modulo_LS/DriverProfile.hpp"


using namespace std;


int main(){
    Database database;
    database.loadCSV();

    //initialize the comparator and driver profile
    CityComparator comparator(database);
    DriverProfile profile;

    cout << "---------------------------------------------------------------------" << endl;
    cout << "                ROAD SAFETY: CITIES COMPARISON:                      " << endl;
    cout << "---------------------------------------------------------------------" << endl;

    comparator.selectCities();

        cout << "---------------------------------------------------------------------" << endl;
    vector<string> cities = comparator.getCities();

    //Create a City object. 
    //Retrieve state, county, and accident statistics.
    //Print the accident statistics for the state, county, and city
    for(int i = 0; i < cities.size(); i++) {
        //gets the list of selected cities
        string city = cities[i];
        City city_obj;
        city_obj.SetName(city);
        string state = city_obj.getStateByCity(city, database);
        string county = city_obj.getCountyByCity(city, database);
        int numStateAcc = city_obj.CountAccidentsInState(state, database);
        cout << "Accidents in " << city << " STATE " << "<<" << state << ">> is: " << numStateAcc << endl;

        int numCountyAcc = city_obj.CountAccidentsInCounty(county, database);
        cout << "Accidents in " << city << " COUNTY " << "<<" << county << ">> is: " << numCountyAcc << endl;

        int numCityAcc = city_obj.CountAccidentsInCity(city, database);
        cout << "Accidents in " << city << " is: " << numCityAcc << endl;
        cout << "---------------------------------------------------------------------" << endl;
    }

    //calculates the average severity
    map<string, double> severityByCity = comparator.CalculateSeverityMeanByCity(database);

    cout << "Average SEVERITY by city: " << endl;
    cout << "(between 1 and 4, where 1 indicates the least impact on traffic):" << endl;
    for (int i = 0; i < cities.size(); i++) {
        string city = cities[i];
        //Checks if the city is present in the severityByCity map.
        //Compares the iterator returned by find with the iterator returned by end(). If they are not equal, it means the city key was found in the map
        if (severityByCity.find(city) != severityByCity.end()) {
            cout << "City: " << city << ", Average Severity: " << severityByCity[city] << endl;
        } else {
            cout << "City: " << city << ", Average Severity: Data not available" << endl;
        }
    }

    cout << "---------------------------------------------------------------------" << endl;
    int opcion;
    cout << "Would you like to customize the city comparison by making a question" << endl;
    cout <<  "form about road safety?(YES: 1, NO: 0): ";
    cin >> opcion;
    if(opcion == 1){
        profile.collectPreferences();
        string bestCity = profile.recommendCity(cities, database, comparator);
        cout << "The best city for you based on your preferences is: " << bestCity << endl;
    } else if (opcion == 0){
        cout << "The program is finished. THANKS!" << endl;
        return 0;
    } else{
        cout << "invalid option" << endl;
    }


    return 0;
}

