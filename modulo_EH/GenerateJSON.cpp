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
#include "GenerateJSON.hpp"

using json = nlohmann::json;
using namespace std;

/**
 * Constructor of the GenerateJSON class.
 */
GenerateJSON::GenerateJSON(Database db) {
    this->db = db;
}

/**
 * Function to create JSON.
 */
void GenerateJSON::generateJSON() {
    db.loadCSV(); // Load the data
    int cityIndex; // Variables to store the indices of the city and weather_condition columns
    int weatherIndex;
    json cities; // Create JSON object

    vector<vector<string>> data = db.getData();
    vector<string> headers = db.getHeaders();

    for (int i = 0; i < headers.size(); i++) { // Obtain the values of cityIndex and weatherIndex
        if (headers[i] == "City") {
            cityIndex = i;
        } else if (headers[i] == "Weather_Condition") {
            weatherIndex = i;
        }
    }

    for (auto row : data) { // Store the values in the JSON
        string city = row[cityIndex];
        string weather = row[weatherIndex];
        if (!cities.contains(city)) { // If the city does not exist in the JSON, add it and add the weather with the counter set to 1
            cities[city] = json::object();
            cities[city][weather] = {{"counter", 1}};
        } else {
            if (!cities[city].contains(weather)) { // If the city exists but the weather does not, add the weather to the city with the counter set to 1
                cities[city][weather] = {{"counter", 1}};
            } else { // If the weather already exists in the city, increment the counter by 1
                cities[city][weather]["counter"] = cities[city][weather]["counter"].get<int>() + 1;
            }            
        }       
    }

    // Generate the file here
    ofstream outputfile("citiesWeather.json");
    if (outputfile.is_open()) {
        outputfile << cities.dump(4);
        outputfile.close();
    } else {
        cout << "Error trying to generate .json file" << endl;
    }
}



