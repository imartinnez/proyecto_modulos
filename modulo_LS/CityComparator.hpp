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
#ifndef CITYCOMPARATOR_HPP
#define CITYCOMPARATOR_HPP

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include "../modulo_Database/Database.hpp"

using namespace std;

class CityComparator{
    private:
        vector<string> cities;
        string recommendation;
        Database db;
    public:
        /**
         * Constructor of the class CityComparator
         */
        CityComparator(Database database);
        /**
         * get the list of the selected cities
         * @returns vector of the city list
         */
        vector<string> getCities();

        /**
         * ask the user to select the cities for the comparison
         */
        void selectCities();
        /**
         * this method calculates the average severity of each city
         * @returns a map of the average severity and the count number of accidents
         */
        map<string, double> CalculateSeverityMeanByCity(Database db);

};

#endif /*CITYCOMPARATOR*/