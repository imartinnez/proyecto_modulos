#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "../modulo_dev/Database.hpp"
#include "../modulo_IM/carModel.hpp"
#include "../modulo_IM/CarModelList.hpp"
using namespace std;

int main() {

    carModel a;
    CarModelList l1(a.brand, a.year);
    Database db;
    int tamaño;
    
    /*
    cout << "Bienvenido, escoja su marca de coche entre la siguiente lista:" << endl; //TIENE QUE SER EN INGLÉS
    l1.showBrands();
    cin >> a.brand;
    cout << "Ahora introduzca el año de fabricación de su coche:" << endl;
    cin >> a.year;
    l1.setCarDetails(a.brand, a.year);
    cout << l1.getCarBrand() << "    " << l1.getCarYear() << "    " << l1.getRangeLevel();
    */

    
    double accidentCounter;
    int severityCounter = 0;
    double severityAverage;
    double severityValue; 
    int stateIndex;
    int severityIndex;
    vector<string> row;

    int weatherIndex; //indice de la columna Weather_Condition
    double weatherCounter; //suma de los valores de las weatherConditions
    double weatherMultiplier; //multiplicador al que se le multiplica al precio base, el cual se saca de la formula

    db.loadCSV();
    vector<vector<string>> data = db.getData();
    vector<string> headers = db.getHeaders();
    tamaño = data.size();

    for(int h = 0; h < headers.size(); h++) {
        if(headers[h] == "State") {
            stateIndex = h;
            break;
        }
    }


    
    for(int i = 0; i < data.size(); i++) {
        row = data[i];
        if(row[stateIndex] == "NY") {
            accidentCounter++;
        }
    }

    //cout << endl << endl << accidentCounter;
    row.clear();

    /*
    for(int s = 0; s < headers.size(); s++) {
        if(headers[s] == "Severity") {
            severityIndex = s;
            break;
        }
    }
    for(int i = 0; i < data.size(); i++) {
        row = data[i];
        if(row[stateIndex] == "AZ") {
            severityCounter +=  stoi(row[severityIndex]);    //hacemos uso de stoi, para castear las celdas de tipo string en int
        }
    }
    //calculo de la media del valor de AS
    for(int i = 0; i < data.size(); i++) {
        row = data[i];
        severityAverage += stoi(row[severityIndex]);
    }
    */

   for(int w = 0; w < headers.size(); w++) {
        if(headers[w] == "Weather_Condition") {
            weatherIndex = w;
            break;
        }
    }


    for(int i = 0; i < data.size(); i++) {
        row = data[i];
        if(row[stateIndex] == "NY") {
            if(row[weatherIndex] == "Tornado") {weatherCounter += 6.0;}
            else if(row[weatherIndex] == "Heavy Snow") {weatherCounter += 5.0;}
            else if(row[weatherIndex] == "Heavy Rain" || row[weatherIndex] == "Hail") {weatherCounter += 4.0;}
            else if(row[weatherIndex] == "T-Storm" || row[weatherIndex] == "Snow") {weatherCounter += 3.0;}
            else if(row[weatherIndex] == "Rain" || row[weatherIndex] == "Fog") {weatherCounter += 2.0;}
            else {weatherCounter += 1.0;}
        }
    }

    weatherMultiplier = (weatherCounter/accidentCounter);
    //basePrice *= weatherMultiplier;





    cout << "HOLA" << endl << endl << weatherMultiplier << endl << 600.0*weatherMultiplier << endl << 1000.0*weatherMultiplier;



    


    return 0;
}