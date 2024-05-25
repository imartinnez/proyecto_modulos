
#ifndef REFRESCARTXT_HPP
#define REFRESCARTXT_HPP

#include <vector>
#include <string>
#include <fstream>
#include "../modulo_dev/Database.hpp"
#include "../modulo_EH/json.hpp"

using namespace std;
class RefrescarTXT {
private:
    Database db; // Referencia a la instancia de Database
    vector<pair<string,string>> data;// Variable miembro para almacenar los datos
    

public:
    RefrescarTXT(Database db);
    void filterCityWeather();
    void generateWeatherJSON(); 

};

#endif // REFRESCARTXT_HPP
