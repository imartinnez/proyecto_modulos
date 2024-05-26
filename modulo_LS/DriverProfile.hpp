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
#ifndef DRIVERPROFILE_HPP
#define DRIVERPROFILE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "CityComparator.hpp"
#include "../modulo_Database/Database.hpp"
#include "City.hpp"

using namespace std;

class DriverProfile {
    private:
        bool considerTrafficImpact;
        bool considerCityAccidents;
        bool considerCountyAccidents;
    public:
        /**
         * prints the question form and collect preferences
         */
        void collectPreferences();
        /**
         * Collects the comparison of the selected cities and by puntuation, the method selects the best city based on the driver's preferences
         * @returns the best city of the selected ones
         */
        string recommendCity(vector<string> cities, Database db, CityComparator cityComparator);
};

#endif /*DRIVERPROFILE_HPP*/