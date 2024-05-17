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
    

    cout << "Bienvenido, escoja su marca de coche entre la siguiente lista:" << endl; //TIENE QUE SER EN INGLÉS
    l1.showBrands();
    cin >> a.brand;
    cout << "Ahora introduzca el año de fabricación de su coche:" << endl;
    cin >> a.year;
    l1.setCarDetails(a.brand, a.year);
    cout << l1.getCarBrand() << "    " << l1.getCarYear() << "    " << l1.getRangeLevel();

    /*
    db.loadCSV();
    vector<vector<string>> datos = db.getData();
    vector<string> encabezados = db.getHeaders();

    cout << "Encabezados:" << endl;
    for (string header : encabezados) {
        cout << header << "\t";
    }
    cout << endl;


    cout << "Datos:" << endl;
    for (vector<string> fila : datos) {
        for (string celda : fila) {
            cout << celda << "\t";
        }
        cout << endl;
    }
    */


    


    return 0;
}