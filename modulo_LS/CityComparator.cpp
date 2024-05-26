/**
 * @author: Luis Sánchez
 * 
 * @module: modulo_LS
 * 
 * @class CityComparator
 * 
 * the class CityComparator is used to study the relation of the selected cities and to calculate the average severity
 * severity: impact on traffic (1 is the lowest level, 4 is the highest)
 */
#include "CityComparator.hpp"

using namespace std;

CityComparator::CityComparator(Database database) {
    this->db = database;
}

vector<string> CityComparator::getCities() {
    return cities;
}

void CityComparator::selectCities() {
    int numCities;
    do{
        cout << "Insert the number of cities you want to compare (between 2 and 4): ";
        cin >> numCities;
    }while(numCities < 2 || numCities > 4);

    cin.ignore();
    //empties the container, removing all its elements.
    cities.clear();

    cout << "Select the cities you want to compare: "<< endl;
    for(int i = 0; i < numCities; i++){
        cout << "City " << i + 1 << " to compare: ";
        string city;
        //read the entire input line, including spaces
        getline(cin, city);
        cities.push_back(city);
    }
}

// Function to calculate the average severity by city
// the map structure associates unique keys with values.
// stores elements in pairs(first and second)
map<string, double> CityComparator::CalculateSeverityMeanByCity(Database db) {
    vector<vector<string>> data = db.getData();
    vector<string> headers = db.getHeaders();
    vector<string> selectCities = getCities();

    // a map to store the total severity and count of accidents for each city
    // in this map, the key is the name of the city and the value is the pair of severity and accidents
    map<string, pair<int, int>> severityByCity;

    int cityColumnIndex = -1;
    for(int i = 0; i < headers.size(); i++){
        if (headers[i] == "City") {
            cityColumnIndex = i;
            break;
        }
    }
    
    int severityColumnIndex = -1;
    for(int i = 0; i < headers.size(); i++){
        if(headers[i] == "Severity") {
            severityColumnIndex = i;
            break;
        }
    }

    //iterate through each row of data to calculate total severity and count of accidents for each selected city
    for (int i = 0; i < data.size(); i++){
        vector<string> row = data[i];
        //Checks if both indices are valid for the current row.
        if (cityColumnIndex < row.size() && severityColumnIndex < row.size()) {
            string city = row[cityColumnIndex];
            //initialize a flag to track if the city is found in the selected cities
            bool cityFound = false;
            for(int j = 0; j < selectCities.size(); j++){
                if(city == selectCities[j]){
                    cityFound = true;
                    break;
                }
            }
            if(cityFound){
                //convert the severity value from string to integer
                int severity = stoi(row[severityColumnIndex]);
                //add the severity to the total severity of the city
                //The severityByCity map is updated by incrementing the total severity (first) and the accident count (second) for that city.
                severityByCity[city].first += severity;
                severityByCity[city].second++;
            }
        }
    }

    //calculate the average severity by city
    map<string, double> severityMeanByCity;
    for(const pair<string, pair<int, int>>& entry : severityByCity) {
        //If the accident count (second) is greater than 0, the average severity is calculated (first divided by second).
        if(entry.second.second > 0) {
            severityMeanByCity[entry.first] = (double)entry.second.first / entry.second.second;
        }
    }
    return severityMeanByCity;
 
}
