#include "CityComparator.hpp"
#include <iostream>

using namespace std;

CityComparator::CityComparator(const Database& database) : db(database) {}

CityComparator::~CityComparator() {}

void CityComparator::selectCities() {
    int numCities;
    do{
        cout << "Insert the number of cities you want to compare (between 2 and 4): ";
        cin >> numCities;
    }while(numCities < 2 || numCities > 4);

    cin.ignore();
    
    cities.clear();
    cout << "Select the cities you want to compare: "<< endl;
    for(int i = 0; i < numCities; i++){
        cout << "City " << i + 1 << " to compare: ";
        string city;
        getline(cin, city);//leer toda la linea de entrada, con espacios incluidos
        cities.push_back(city);
    }
}

// Function to calculate the average severity by city
map<string, double> CityComparator::CalculateSeverityMeanByCity(Database& db) {
    const vector<vector<string>>& data = db.getData();
    const vector<string>& headers = db.getHeaders();
    const vector<string>& selectCities = getCities();

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

    for (int i = 0; i < data.size(); i++){
        const vector<string>& row = data[i];
        if (cityColumnIndex < row.size() && severityColumnIndex < row.size()) {
            string city = row[cityColumnIndex];
            bool cityFound = false;
            for(int j = 0; j < selectCities.size(); j++){
                if(city == selectCities[j]){
                    cityFound = true;
                    break;
                }
            }
            if(cityFound){
                int severity = stoi(row[severityColumnIndex]);
                severityByCity[city].first += severity;
                severityByCity[city].second++;
            }
        }
    }

    //calculate the average severity by city
    map<string, double> severityMeanByCity;
    for(const pair<string, pair<int, int>>& entry : severityByCity) {
        if(entry.second.second > 0) {
            severityMeanByCity[entry.first] = (double)entry.second.first / entry.second.second;
        }
    }
    return severityMeanByCity;
 
}