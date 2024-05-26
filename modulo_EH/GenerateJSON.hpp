/**
 * @author: Eduardo Hortelano
 * 
 * Module: modulo_EH
 * 
 * @class GenerateJSON
 * 
 * The GenerateJSON class generates a "citiesWeather.json" file where you can see the cities,
 * the weather conditions in those cities when the accidents occurred, and how many accidents occurred under those weather conditions.
 * 
 */
#ifndef GENERATEJSON_HPP
#define GENERATEJSON_HPP

#include <vector>
#include <string>
#include <fstream>
#include "../modulo_Database/Database.hpp"
#include "../modulo_EH/json.hpp"

using namespace std;
class GenerateJSON {
private:
    Database db; // Reference to the Database instance

    

public:
    /**
     * GenerateJSON class constructor
     */
    GenerateJSON(Database db);
    /**
     * Generates .json file
     */
    void generateJSON();
    

};

#endif // GENERATEJSON_HPP
