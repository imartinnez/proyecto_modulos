#ifndef CITY_HPP
#define CITY_HPP

#include<string>
#include"../modulo_dev/Database.hpp"

using namespace std;

class City {
    private:
        string name;
        int numAcc;
    public:
        City(const string& cityName = "", int numAccidents = 0);

        string GetName();
        void SetName(string cityName);

        int GetNumAccidents();
        void SetNumAccidents(int num);

        string getStateByCity(string cityName, Database& db);
        string getCountyByCity(string cityName, Database& db);

        int CountAccidentsInCity(string cityName, Database& db);
        int CountAccidentsInCounty(string countyName, Database& db);
        int CountAccidentsInState(string stateName, Database& db);

};

#endif /*CITY_HPP*/