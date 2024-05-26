/**
 * @author: Luis Sánchez
 * 
 * @module: modulo_LS
 * 
 * @class City
 * 
 * The class City is used for the examination and count of each selected city
 * where its study the state and county for a better information
 */
#include "City.hpp"

using namespace std;

City::City(){}

string City::GetName(){
    return name;
}
void City::SetName(string cityName){
    name = cityName;
}

//Get the county by the selected city
string City::getCountyByCity(string cityName, Database db){
    vector<vector<string>> data = db.getData();
    vector<string> headers = db.getHeaders();

    int cityIndex = -1;
    int countyIndex = -1;

    // Find the indices of the 'City' and 'County' columns in the headers
    for (int i = 0; i < headers.size(); ++i) {
        if (headers[i] == "City") {
            cityIndex = i;
        } else if (headers[i] == "County") {
            countyIndex = i;
        }
    }

    // Search for the city and return the corresponding county
    for (int i = 0; i < data.size(); i++) {
        vector<string> row = data[i];
        if (row[cityIndex] == cityName) {
            return row[countyIndex];
        }
    }

    return "Unknown County";
}
string City::getStateByCity(string cityName, Database db){
    vector<vector<string>> data = db.getData();
    vector<string> headers = db.getHeaders();

    int cityIndex = -1;
    int stateIndex = -1;

    for (int i = 0; i < headers.size(); ++i) {
        if (headers[i] == "City") {
            cityIndex = i;
        } else if (headers[i] == "State") {
            stateIndex = i;
        }
    }

    for (int i = 0; i < data.size(); i++) {
        vector<string> row = data[i];
        if (row[cityIndex] == cityName) {
            return row[stateIndex];
        }
    }

    return "Unknown State";
}

int City::CountAccidentsInCity(string cityName, Database db){
    int count = 0;
    vector<vector<string>> data = db.getData();
    vector<string> headers = db.getHeaders();

    int cityColumnIndex = -1;
    for(int i = 0; i < headers.size(); i++){
        if(headers[i] == "City"){
            cityColumnIndex = i;
            break;
        }
    }
    
    for (vector<string> row : data){
        if(cityColumnIndex < row.size() && row[cityColumnIndex] == cityName){
            count++;
        }
    }
    return count;
}
int City::CountAccidentsInState(string stateName, Database db){
    int count = 0;
    vector<vector<string>> data = db.getData();
    vector<string> headers = db.getHeaders();

    int stateColumnIndex = -1;
    for(int i = 0; i < headers.size(); i++){
        if(headers[i] == "State"){
            stateColumnIndex = i;
            break;
        }
    }

    for (int i = 0; i < data.size(); i++) {
        vector<string> row = data[i];
        if (row[stateColumnIndex] == stateName) {
            count++;
        }
    }

    return count;
}
int City::CountAccidentsInCounty(string countyName, Database db){
    int count = 0;
    vector<vector<string>> data = db.getData();
    vector<string> headers = db.getHeaders();

    int countyColumnIndex = -1;
    for(int i = 0; i < headers.size(); i++){
        if(headers[i] == "County"){
            countyColumnIndex = i;
            break;
        }
    }

    //Count the number of rows that match the county of the selected city
    for (int i = 0; i < data.size(); i++) {
        vector<string> row = data[i];
        if (row[countyColumnIndex] == countyName) {
            count++;
        }
    }

    return count;
}


