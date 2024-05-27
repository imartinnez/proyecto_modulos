/**
 * @author: Iñigo Martínez
 * 
 * Module: modulo_IM
 * 
 * @class CarModelList
 * 
 * The CarModelList class allows managing the list of car brands as well as their
 * brand status and the list of USA state abbreviations.
 */
#include "CarModelList.hpp"
using namespace std;

CarModelList::CarModelList() {}

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
    bool header = true; // We use this variable to skip the headers
    int pos_coma;
    
    /**
     * We analyze the file line by line using getline(), and identify the 
     * position of the comma which separates the brand from its status. Once done, we
     * print each line of the .txt file.
    */
    if (file.is_open()) {
        while (getline(file, line)) {
            if(header){
                header = false;
            }
            else{
                // Find the position of the comma
                pos_coma = line.find(",");
                cout << line.substr(0, pos_coma) << endl;
            }
        }
        file.close();
    } else {
        cout << "Could not open the file." << endl;
    }

}

string CarModelList::getRangeLevel() {
    ifstream file("modulo_IM/carTypes.txt");
    string line;
    string brand;
    bool found = false;
    int pos_coma;

    /**
    * We perform the same process as in the previous function, but in this case, we look for the comma
    * to compare if the part before the comma matches the brand entered
    * by the user, and if so, it returns the part after the comma, the status
    */
    if (file.is_open()) {
        while (getline(file, line)) {
            pos_coma = line.find(",");
            brand = line.substr(0, pos_coma);

            if (brand == carDetails.brand) {
                // If found
                found = true;
                // Return the type of the brand
                return line.substr(pos_coma + 1);
            }
        }
        file.close();
        if (!found) {
        return "Brand not found";
        }
    } 
    
    cout << "Could not open the file." << endl;
    return "-1";
    
}

void CarModelList::showUSAStates() {
    // Open the file in read mode
    string line;
    ifstream file("modulo_IM/USA_States.txt");

    if (!file.is_open()) {
        cout << "Could not open the file." << endl;
        exit(0);
    }
    // Read each line of the file where the states of the USA are listed and display them on the screen
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}