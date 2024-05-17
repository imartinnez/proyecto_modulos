#include <iostream>
#include <vector>
#include <limits>
#include "../modulo_dev/Database.hpp"
#include "../modulo_LS/City.hpp"
#include "../modulo_LS/CityComparator.hpp"


using namespace std;


int main(){
    Database database;
    database.loadCSV();

    CityComparator cityComparator(database);

    cout << "---------------------------------------------------------------------" << endl;
    cout << "                ROAD SAFETY CITIES COMPARISON :                    " << endl;
    cout << "---------------------------------------------------------------------" << endl;

    cityComparator.selectCities();

        cout << "---------------------------------------------------------------------" << endl;
    const vector<string>& ciudades = cityComparator.getCities();

    for(int i = 0; i < ciudades.size(); i++) {
        const string& ciudad = ciudades[i];
        City ciudad_obj(ciudad);
        string estado = ciudad_obj.getStateByCity(ciudad, database);
        string condado = ciudad_obj.getCountyByCity(ciudad, database);
        int numStateAcc = ciudad_obj.CountAccidentsInState(estado, database);
        cout << "Accidents in " << ciudad << " STATE " << "<<" << estado << ">> is: " << numStateAcc << endl;

        int numCountyAcc = ciudad_obj.CountAccidentsInCounty(condado, database);
        cout << "Accidents in " << ciudad << " COUNTY " << "<<" << condado << ">> is: " << numCountyAcc << endl;

        int numCityAcc = ciudad_obj.CountAccidentsInCity(ciudad, database);
        cout << "Accidents in " << ciudad << " is: " << numCityAcc << endl;
        cout << "---------------------------------------------------------------------" << endl;
    }

        
    map<string, double> severidadMediaPorCiudad = cityComparator.CalculateSeverityMeanByCity(database);
     cout << "Average SEVERITY by city: " << endl;
     cout << "(between 1 and 4, where 1 indicates the least impact on traffic):" << endl;
    for (const auto& entry : severidadMediaPorCiudad) {
        cout << "City: " << entry.first << ", Average Severity: " << entry.second << endl;
    }
    cout << "---------------------------------------------------------------------" << endl;
    int opcion;
    cout << "Would you like to customize the city comparison by making a question" << endl;
    cout <<  "form about road safety?(YES: 1, NO: 0): ";
    cin >> opcion;
    if(opcion == 1){
        cout << " " << endl;
    } else if (opcion == 0){
        cout << "The program is finished. THANKS!" << endl;
        return 0;
    } else{
        cout << "invalid option" << endl;
    }


    return 0;
}

