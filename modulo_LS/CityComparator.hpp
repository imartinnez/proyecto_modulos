#ifndef CITYCOMPARATOR_HPP
#define CITYCOMPARATOR_HPP

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include "../modulo_dev/Database.hpp"

using namespace std;

class CityComparator{
    private:
        vector<string> cities;
        string recommendation;
        Database db;
    public:
        CityComparator(const Database& database);
        ~CityComparator();

        const vector<string>& getCities() {
            return cities;
        };
        //void setCities(const vector<string>& newCities);

        //const string& getRecommendation() const;
        //void setRecommendation() const;

        void selectCities();

        map<string, double> CalculateSeverityMeanByCity(Database& db);
        

        void generateReport();

        void recommendCity();
};

#endif /*CITYCOMPARATOR*/