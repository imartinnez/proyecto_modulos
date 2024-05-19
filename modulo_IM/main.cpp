#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unistd.h> //para la funcion sleep
#include "../modulo_dev/Database.hpp"
#include "../modulo_IM/Driver.hpp"
#include "../modulo_IM/carModel.hpp"
#include "../modulo_IM/CarModelList.hpp"
using namespace std;

void showUSAStates();

bool POLICYCALCULATED = false; //para poder controlar el flujo del programa
bool FILEGENERATED = false;

int main() {

    int option;
    string name;
    string id;
    string licencePlate;
    string location;
    int driverLicenceAge;
    carModel carDetails;
    int policyType;
    double policyPrice;
    CarModelList cm;


    cout << "                  WELCOME TO THE WORLD OF INSURANCE" << endl;
    cout << "=======================================================================" << endl << endl << endl;

    cout << "Before we start, it will be necessary for you to register with your information. For this, we will ask you some questions." << endl << endl;
    cout << "Enter your full name: ";
    getline(cin, name);
    cout << endl;
    cout << "Enter your ID: ";
    cin >> id;
    cout << endl;
    cout << "Enter your vehicle registration plate: ";
    cin >> licencePlate;
    cout << endl;
    cout << "To choose your location, enter the abbreviation corresponding to your state from the following list." << endl;
    sleep(2);
    showUSAStates();
    cout << endl;
    cout << "Enter the abreviation of your state: ";
    cin >> location;
    cout << endl;
    cout << "Enter the number of years you've had your driver's license: ";
    cin >> driverLicenceAge;
    cout << endl;
    cout << "From the following list, enter your car brand." << endl;
    sleep(2);
    cm.showBrands();
    cout << endl;
    cout << "Enter your car brand: ";
    cin >> carDetails.brand;   
    cout << endl;  
    cout << "Enter the year of manufacture of your car: ";
    cin  >> carDetails.year;
    cout << endl;
    cout << "Enter the type of insurance policy you want to contract (0-third party, 1-comprehensive): ";
    cin >> policyType;
    cout << endl << endl;
    cout << "Creating driver profile..." << endl;
    sleep(2);
    Driver d(name, id, licencePlate, location, carDetails, policyType);
    cout << "Driver profile successfully created!!" << endl << endl;
    sleep(2);

    do {
        
        cout << "Now, select an option:" << endl;
        cout << "1. Calculate insurance policy price" << endl;
        cout << "2. Generate .txt file of the policy" << endl;
        cout << "3. View .txt file of the policy" << endl;
        cout << "4. Exit" << endl;
        cout << "Option: ";
        cin >> option;

        // Perform actions based on the selected option
        switch (option) {
            case 1:
                d.setPolicyPrice();
                POLICYCALCULATED = true;
                break;
            case 2:
                if (POLICYCALCULATED) {
                    d.generatePolicyFile();
                    FILEGENERATED = true;
                } else {
                    cout << "You need to calculate the policy price first." << endl << endl;
                }
                break;
            case 3:
                if (FILEGENERATED) {
                    d.showPolicyFile();
                } else {
                    cout << "You need to generate the policy file first." << endl << endl;
                }
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid option. Please enter a number from 1 to 4." << endl;
        }
    } while (option != 4);

    return 0;
}


void showUSAStates() {
    // Abrir el archivo en modo lectura
    string line;
    ifstream file("modulo_IM/USA_States.txt");

    // Verificar si se pudo abrir el archivo correctamente
    if (!file.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        exit(0); // Salir del programa con código de error
    }

    // Leer el contenido del archivo línea por línea y mostrarlo por pantalla
    while (getline(file, line)) {
        cout << line << endl;
    }

    // Cerrar el archivo
    file.close();
}