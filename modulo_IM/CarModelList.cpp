#include "CarModelList.hpp"
using namespace std;

CarModelList::CarModelList(string brand, int year) {
    this->carDetails.brand = brand;
    this->carDetails.year = year;
}

carModel CarModelList::getCarDetails(){
    return carDetails;
}

void CarModelList::setCarDetails(string brand, int year) {
    carDetails.brand = brand;
    carDetails.year = year;
}

void CarModelList::showBrands() {
    vector<string> brands;
    string line;

    ifstream filename("modulo_IM/carModels.txt");
    if (!filename.is_open()) {
        cout << "Erroooor con el archivo" << endl;
        exit (0);
    }

    
    while (getline(filename, line)) {
        // Separar la línea en marca y tipo
        size_t pos = line.find("-");
        
        if (pos != string::npos) {
            // Si se encuentra el guion, agregar solo la marca
            string brand = line.substr(0, pos);
            brands.push_back(brand);
        } else {
            // Si no se encuentra el guion, agregar toda la línea como marca
            brands.push_back(line);
        }
    }

    cout << "Marcas de coches:" << endl;
    for (const string& marca : brands) {
        cout << marca << endl;
    }

}

string CarModelList::getRangeLevel(carModel carDetails) {
    
    string line;
    string tipe;
    bool brand_found = false;

    ifstream filename("modulo_IM/carTipes.txt");
    if (!filename.is_open()) {
        return "Error con el archivo";
    }

    while (getline(filename, line)) {
        // Si la línea coincide con la marca buscada
        if (line == carDetails.brand) {
            // Leer la siguiente línea que contiene el tipo
            if (getline(filename, tipe)) {
                brand_found = true;
                break;
            }
        }
    }

    filename.close();

    // Si se encontró la marca, devolver el tipo
    if (brand_found) {
        return tipe;
    } else {
        // Si no se encontró la marca, devolver un mensaje indicando que no se encontró
        return "Marca no encontrada";
    }
}
