#include "City.hpp"
#include <iostream>
#include <string>

using namespace std;

City::City(const string& cityName, int numAccidents) : name(cityName), numAcc(numAccidents) {}

string City::GetName(){
    return name;
}
void City::SetName(string cityName){
    name = cityName;
}

int City::GetNumAccidents(){
    return numAcc;
}
void City::SetNumAccidents(int num){
    numAcc = num;
}

string City::getCountyByCity(string cityName, Database& db){
    const vector<vector<string>>& data = db.getData();
    const vector<string>& headers = db.getHeaders();

    int cityIndex = -1;
    int countyIndex = -1;

    // Buscar los índices de las columnas 'City' y 'State' en los encabezados
    for (int i = 0; i < headers.size(); ++i) {
        if (headers[i] == "City") {
            cityIndex = i;
        } else if (headers[i] == "County") {
            countyIndex = i;
        }
    }

    // Buscar la ciudad y devolver el estado correspondiente
    for (int i = 0; i < data.size(); i++) {
        const vector<string>& row = data[i];
        if (row[cityIndex] == cityName) {
            return row[countyIndex];
        }
    }

    return "Unknown County";
}
string City::getStateByCity(string cityName, Database& db){
    const vector<vector<string>>& data = db.getData();
    const vector<string>& headers = db.getHeaders();

    int cityIndex = -1;
    int stateIndex = -1;

    // Buscar los índices de las columnas 'City' y 'State' en los encabezados
    for (int i = 0; i < headers.size(); ++i) {
        if (headers[i] == "City") {
            cityIndex = i;
        } else if (headers[i] == "State") {
            stateIndex = i;
        }
    }

    // Buscar la ciudad y devolver el estado correspondiente
    for (int i = 0; i < data.size(); i++) {
        const vector<string>& row = data[i];
        if (row[cityIndex] == cityName) {
            return row[stateIndex];
        }
    }

    return "Unknown State";
}

int City::CountAccidentsInCity(string cityName, Database& db){
    int count = 0;
    const vector<vector<string>>& data = db.getData();
    const vector<string>& headers = db.getHeaders();

    int cityColumnIndex = -1;
    for(int i = 0; i < headers.size(); i++){
        if(headers[i] == "City"){
            cityColumnIndex = i;
            break;
        }
    }
    
    for (const vector<string>& row : data){
        if(cityColumnIndex < row.size() && row[cityColumnIndex] == cityName){
            count++;
        }
    }
    return count;
}
int City::CountAccidentsInState(string stateName, Database& db){
    int count = 0;
    const vector<vector<string>>& data = db.getData();
    const vector<string>& headers = db.getHeaders();

    int stateColumnIndex = -1;
    for(int i = 0; i < headers.size(); i++){
        if(headers[i] == "State"){
            stateColumnIndex = i;
            break;
        }
    }

    for (int i = 0; i < data.size(); i++) {
        const vector<string>& row = data[i];
        if (row[stateColumnIndex] == stateName) {
            count++;
        }
    }

    return count;
}
int City::CountAccidentsInCounty(string countyName, Database& db){
    int count = 0;
    const vector<vector<string>>& data = db.getData();
    const vector<string>& headers = db.getHeaders();

    int countyColumnIndex = -1;
    for(int i = 0; i < headers.size(); i++){
        if(headers[i] == "County"){
            countyColumnIndex = i;
            break;
        }
    }

    for (int i = 0; i < data.size(); i++) {
        const vector<string>& row = data[i];
        if (row[countyColumnIndex] == countyName) {
            count++;
        }
    }

    return count;
}


