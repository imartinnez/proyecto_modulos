#include "CarModelList.hpp"
using namespace std;

CarModelList::CarModelList(string brand, int year) {
    this->carDetails.brand = brand;
    this->carDetails.year = year;
}

string CarModelList::getCarBrand() {
    return carDetails.brand;
}

int CarModelList::getCarYear() {
    return carDetails.year;
}

void CarModelList::setCarDetails(string brand, int year) {
    carDetails.brand = brand;
    carDetails.year = year;
}

void CarModelList::showBrands() {
    ifstream file("modulo_IM/carTypes.txt");
    string line;
    bool header = true;
    int pos_coma;
    
    if (file.is_open()) {
        while (getline(file, line)) {
            if(header){
                header = false;
            }
            else{
                // Buscar la posición de la coma
                pos_coma = line.find(",");
                cout << line.substr(0, pos_coma) << endl;
            }
        }
        file.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }

}

string CarModelList::getRangeLevel() {
    ifstream file("modulo_IM/carTypes.txt");
    string line;
    string brand;
    bool found = false;
    int pos_coma;

    if (file.is_open()) {
        while (getline(file, line)) {
            pos_coma = line.find(",");
            brand = line.substr(0, pos_coma);

            if (brand == carDetails.brand) {
                found = true;
                return line.substr(pos_coma + 1); // Devolver el tipo de la marca
            }
        }
        file.close();
        if (!found) {
        return "Marca no encontrada";
        }
    } 
    
    cout << "No se pudo abrir el archivo." << endl;
    return "-1";
    
}