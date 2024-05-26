/**
 * @author: Iñigo Martínez
 * 
 * Module: modulo_IM
 * 
 * @class main_IM
 * 
 * This class is responsible for gathering all the functionalities of the other
 * classes in the modulo_IM module and collecting user information through questions. Additionally,
 * it uses a menu function that shows the different actions the user can perform.
 */
#include <iostream>   // To use cout, cin...
#include <string>     // To handle strings
#include <unistd.h>   // To use the sleep() function
#include "../modulo_IM/Driver.hpp"
#include "../modulo_IM/carModel.hpp"
#include "../modulo_IM/CarModelList.hpp"
using namespace std;

void menu(Driver d);  //This function is responsible for generating a loop where a menu is displayed, and the user must choose an option, and that action is performed

bool POLICYCALCULATED = false; //Boolean to control if the policy price has been calculated
bool FILEGENERATED = false;    //Boolean to control if the .txt file has been generated

int main() {

    //Initialize all necessary variables
    string name;
    string id;
    string licencePlate;
    string location;
    int driverLicenceAge;
    carModel carDetails;
    int policyType;
    double policyPrice;
    CarModelList cm;

    cout << "==========================================================================================================================" << endl;
    cout << "                                             WELCOME TO THE WORLD OF INSURANCE" << endl;
    cout << "==========================================================================================================================" << endl << endl << endl;

    //Throughout the main_IM code, we use the sleep function to avoid the immediate appearance of information
    sleep(1);
    cout << "Before we start, it will be necessary for you to register with your information. For this, we will ask you some questions." << endl << endl;
    sleep(2);

    cout << "Enter your full name: ";
    getline(cin, name);
    cout << endl;

    cout << "Enter your ID: ";
    cin >> id;
    cout << endl;

    cout << "Enter your vehicle registration plate: ";
    cin >> licencePlate;
    cout << endl;

    //To have the user enter their location, we show them the list of USA states and their corresponding abbreviation
    cout << "To choose your location, enter the abbreviation corresponding to your state from the following list." << endl;
    sleep(2);
    cm.showUSAStates();
    cout << endl;
    cout << "Enter the abbreviation of your state: ";
    cin >> location;
    cout << endl;

    cout << "Enter the number of years you've had your driver's license: ";
    cin >> driverLicenceAge;
    cout << endl;

    //To have the user enter their car brand, we show them the list of car brands to choose from
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

    cout << "Enter the type of insurance policy you want to contract (0-Third-party insurance, 1-Comprehensive insurance): ";
    cin >> policyType;
    cout << endl << endl;

    cout << "Creating driver profile..." << endl;
    sleep(2);
    //Instantiate an object of the Driver class to save the attributes entered by the user
    Driver d(name, id, licencePlate, location, driverLicenceAge, carDetails, policyType);
    cout << "Driver profile successfully created!!" << endl << endl;
    sleep(2);

    //Call the menu() function
    menu(d);
    return 0;
}

void menu(Driver d) {
    int option;

    do {
        
        cout << "Now, select an option:" << endl << endl;
        cout << "1. Calculate insurance policy price" << endl;
        cout << "2. Show the attributes of the driver profile" << endl;
        cout << "3. Update the attributes of the driver profile" << endl;
        cout << "4. Generate .txt file of the policy" << endl;
        cout << "5. View .txt file of the policy" << endl;
        cout << "6. Exit" << endl << endl;
        cout << "Option: ";
        cin >> option;

        //We use a switch to filter the option
        switch (option) {
            case 1:
                cout << "Calculating the price..." << endl;
                d.setPolicyPrice();
                POLICYCALCULATED = true;  //Set the boolean indicating the policy price has been calculated
                cout << "Price successfully calculated!" << endl << endl;
                sleep(1);
                break;
            case 2:
                cout << "Showing the driver profile..." << endl;
                d.showDriverDetails(POLICYCALCULATED);
                sleep(1);
                break;
            case 3:
                d.updateDriverDetails();
                break;
            case 4:
                if (POLICYCALCULATED) {
                    cout << "Generating the policy file..." << endl;
                    d.generatePolicyFile();
                    FILEGENERATED = true;  //Set the boolean indicating the .txt file has been generated
                    sleep(1);
                    cout << "File successfully generated!" << endl << endl;
                } else {
                    sleep(1);
                    cout << "You need to calculate the policy price first." << endl << endl;
                }
                break;
            case 5:
                //If the .txt file has been generated, show it on screen; otherwise, display an error message
                if (FILEGENERATED) {
                    cout << "Loading the file..." << endl;
                    sleep(1);
                    d.showPolicyFile();
                } else {
                    sleep(1);
                    cout << "You need to generate the policy file first." << endl << endl;
                }
                break;
            case 6:
                cout << "Leaving the session..." << endl;
                sleep(2);
                cout << "Goodbye!" << endl << endl << endl;
                break;
            default:
                cout << "Invalid option. Please enter a number from 1 to 4." << endl;
                sleep(1);
        }
    } while (option != 6);
}

