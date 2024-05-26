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
#ifndef CITY_HPP
#define CITY_HPP

#include <iostream>
#include <string>
#include"../modulo_Database/Database.hpp"

using namespace std;

class City {
    private:
        string name;
        int numAcc;
    public:
        /**
         * Constructor of the class City
         */
        City();
        /**
         * Obtains the name of the City
         */
        string GetName();
        /**
         * Change the name of the City
         * @returns the new City name
         */
        void SetName(string cityName);

        /**
         * Obtains the state of the selected city
         * @returns the state of the city
         */
        string getStateByCity(string cityName, Database db);
        /**
         * Obtains the county of the selected city
         * @returns the county of the city
         */
        string getCountyByCity(string cityName, Database db);

        /**
         * Count the accidents by the selected city
         * @returns the number of incidents of each city
         */
        int CountAccidentsInCity(string cityName, Database db);
        /**
         * Count the accidents by the selected city of its county
         * @returns the number of incidents of each county
         */
        int CountAccidentsInCounty(string countyName, Database db);
        /**
         * Count the accidents by the selected city of its state
         * @returns the number of incidents of each state
         */
        int CountAccidentsInState(string stateName, Database db);

};

#endif /*CITY_HPP*/