/**
 * @author: Iñigo Martínez, Luis Sánchez, Eduardo Hortelano
 * 
 * Module: modulo_MAIN
 * 
 * @class main
 * 
 * This class  is responsible for grouping all modules. It does so that once the
 * user has chosen the module, the main function of the module is invoked
 */
#include <iostream>   // To use cout, cin...
#include <string>     // To handle strings
#include <fstream>   // For file management, fstream and ofstream use
#include <unistd.h>   // To use the sleep() function
#include "../modulo_Database/Database.hpp"
#include "../modulo_LS/City.hpp"
#include "../modulo_LS/CityComparator.hpp"
#include "../modulo_LS/DriverProfile.hpp"
#include "../modulo_IM/Driver.hpp"
#include "../modulo_IM/carModel.hpp"
#include "../modulo_IM/CarModelList.hpp"
#include "../modulo_EH/GenerateJSON.hpp"
#include "../modulo_EH/json.hpp"
using namespace std;

//We have divided the code in three main functions, each one implements it´s module
int main_EH();
int main_IM();
int main_LS();

void carDrawing();
void menu_IM(Driver d);  //This function is responsible for generating a loop where a menu of module 1 is displayed, and the user must choose an option, and that action is performed



int main() {
    int option;

    carDrawing();
    while (option != 4) {
        // Options menu
        cout << "Select the module you want to access:\n";
        cout << "1. Module in which the price of your car insurance policy will be calculated based on your location\n";
        cout << "2. Module where you can access a city comparator analyzing car accidents and receiving personalized recommendations\n";
        cout << "3. Module where you can generate a .json file to see the cities with car accidents and the weather at the time of the accidents\n";
        cout << "4.Exit\n";
        cout << "Enter your option: ";
        cin >> option;

        if(option == 4) {
            cout << "Leaving the program..." << endl;
            sleep(1);
            cout << "Goodbye!!" << endl << endl << endl;
            return 0;
        }

        switch(option) {
            case 1:
                cout << "Accessing module 1..." << endl << endl;
                sleep(2);
                main_IM();
                break;
            case 2:
                cout << "Accessing module 2..." << endl << endl;
                sleep(2);
                main_LS();
                break;
            case 3:
                cout << "Accessing module 3..." << endl << endl;
                sleep(2);
                main_EH();
                break;
            case 4:
                cout << "Exiting the program..." << endl;
                sleep(1);
                cout << "Goodbye!!";
                break;
            default:
                cout << "Invalid option. Enter an option from the list.\n";
        }
    }
    return 0;
}


void carDrawing() {
    cout << "                ______" << endl;
    cout << "               //  ||\\ \\" << endl;
    cout << "          ____//___||_\\ \\___" << endl;
    cout << "          )  _          _    \\" << endl;
    cout << "          |_/ \\________/ \\___|" << endl;
    cout << "         ___\\_/________\\_/______" << endl;
    cout << "            /  O           O  \\" << endl << endl;
    cout << "==============================================" << endl;
    cout << "COMPREHENSIVE CAR ACCIDENT ANALYSIS PROGRAMME" << endl;
    cout << "==============================================" << endl << endl << endl;
}




int main_EH(){
    Database db;
    GenerateJSON json(db);
    json.generateJSON();
    cout << "File .json generated successfully!!" << endl << endl << endl;
    return 0;
}






int main_IM() {

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

    cin.ignore();

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
    menu_IM(d);
    return 0;
}


void menu_IM(Driver d) {
    int option;
    bool POLICYCALCULATED = false; //Boolean to control if the policy price has been calculated
    bool FILEGENERATED = false;    //Boolean to control if the .txt file has been generated

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






int main_LS(){
    Database database;
    database.loadCSV();

    //initialize the comparator and driver profile
    CityComparator comparator(database);
    DriverProfile profile;

    cout << "---------------------------------------------------------------------" << endl;
    cout << "                ROAD SAFETY: CITIES COMPARISON:                      " << endl;
    cout << "---------------------------------------------------------------------" << endl;

    comparator.selectCities();

        cout << "---------------------------------------------------------------------" << endl;
    vector<string> cities = comparator.getCities();

    //Create a City object. 
    //Retrieve state, county, and accident statistics.
    //Print the accident statistics for the state, county, and city
    for(int i = 0; i < cities.size(); i++) {
        //gets the list of selected cities
        string city = cities[i];
        City city_obj;
        city_obj.SetName(city);
        string state = city_obj.getStateByCity(city, database);
        string county = city_obj.getCountyByCity(city, database);
        int numStateAcc = city_obj.CountAccidentsInState(state, database);
        cout << "Accidents in " << city << " STATE " << "<<" << state << ">> is: " << numStateAcc << endl;

        int numCountyAcc = city_obj.CountAccidentsInCounty(county, database);
        cout << "Accidents in " << city << " COUNTY " << "<<" << county << ">> is: " << numCountyAcc << endl;

        int numCityAcc = city_obj.CountAccidentsInCity(city, database);
        cout << "Accidents in " << city << " is: " << numCityAcc << endl;
        cout << "---------------------------------------------------------------------" << endl;
    }

    //calculates the average severity
    map<string, double> severityByCity = comparator.CalculateSeverityMeanByCity(database);

    cout << "Average SEVERITY by city: " << endl;
    cout << "(between 1 and 4, where 1 indicates the least impact on traffic):" << endl;
    for (int i = 0; i < cities.size(); i++) {
        string city = cities[i];
        //Checks if the city is present in the severityByCity map.
        //Compares the iterator returned by find with the iterator returned by end(). If they are not equal, it means the city key was found in the map
        if (severityByCity.find(city) != severityByCity.end()) {
            cout << "City: " << city << ", Average Severity: " << severityByCity[city] << endl;
        } else {
            cout << "City: " << city << ", Average Severity: Data not available" << endl;
        }
    }

    cout << "---------------------------------------------------------------------" << endl;
    int opcion;
    cout << "Would you like to customize the city comparison by making a question" << endl;
    cout <<  "form about road safety?(YES: 1, NO: 0): ";
    cin >> opcion;
    if(opcion == 1){
        profile.collectPreferences();
        string bestCity = profile.recommendCity(cities, database, comparator);
        cout << "The best city for you based on your preferences is: " << bestCity << endl;
    } else if (opcion == 0){
        cout << "The program is finished. THANKS!" << endl << endl << endl;
        return 0;
    } else{
        cout << "invalid option" << endl;
    }
    return 0;
}