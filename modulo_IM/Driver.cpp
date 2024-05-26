/**
 * @author: Iñigo Martínez
 * 
 * Module: modulo_IM
 * 
 * @class Driver
 * 
 * This class contains detailed information about a driver, including their name,
 * ID, vehicle license plate, location, driver license age, car details, and policy price.
 * It also provides methods to manage and display the driver's information and their policy.
 */
#include "Driver.hpp"
using namespace std;

Driver::Driver(string name, string id, string licencePlate, string location, int driverLicenceAge, carModel carDetails, int policyType) {
    this->name = name;
    this->id = id;
    this->licencePlate = licencePlate;
    this->location = location;
    this->driverLicenceAge = driverLicenceAge;
    this->carDetails.brand = carDetails.brand;
    this->carDetails.year = carDetails.year;
    this->policyType = policyType;
}

void Driver::setPolicyPrice() {
    //Instances the objects of the classes CarModelList and PriceCalulator to set the price of the policy
    CarModelList cm(carDetails.brand, carDetails.year);
    string carRangeLevel = cm.getRangeLevel();

    Policy p(policyType, policyPrice, carRangeLevel, location, carDetails, driverLicenceAge);
    policyPrice = p.calculatePolicyPrice();
}

void Driver::showDriverDetails(bool policyCalculated) {
    cout << "--------------------------------------" << endl;
    cout << "1.Name: " << name << endl;
    cout << "2.ID: " << id << endl;
    cout << "3.Licence Plate: " << licencePlate << endl;
    cout << "4.Location: " << location << endl;
    cout << "5.Driver Licence Age: " << driverLicenceAge << " years" << endl;
    cout << "6.Car Brand: " << carDetails.brand << endl;
    cout << "7.Car Year: " << carDetails.year << endl;
    if(policyCalculated) {cout << "8.Policy Price: " << policyPrice << "$" << endl;}  //In case the price has not been calculated yet, displays a message of not calculated
    else {cout << "8.Policy Price: " << "Not calculated yet" << endl;}
    if(policyType == 0) {cout << "9.Policy Type: " << "Third-party insurance" << endl;} 
    else {cout << "9.Policy Type: " << "Comprehensive insurance" << endl;}
    cout << "--------------------------------------" << endl << endl << endl;
}

void Driver::updateDriverDetails() {
    CarModelList cm;
    int choice;
    string input;
    
    //Generates a loop where a menu is displayed for the user to choose the attribute they want to modify
    do {
        cout << "Which attribute would you like to modify?" << endl;
        cout << "1. Name" << endl;
        cout << "2. ID" << endl;
        cout << "3. Licence Plate" << endl;
        cout << "4. Location" << endl;
        cout << "5. Driver Licence Age" << endl;
        cout << "6. Car Brand" << endl;
        cout << "7. Car Year" << endl;
        cout << "8. Policy Type" << endl;
        cout << "9. Exit" << endl;
        sleep(1);
        cout << "Enter the number: " << endl;
        cin >> choice;

        //Once the user has decided the attribute he wants to change, a switch is made to filter the chosen option
        switch (choice) {
            case 1:
                cout << "Enter new name: ";
                getline(cin, name);
                break;
            case 2:
                cout << "Enter new ID: ";
                cin >> id;
                break;
            case 3:
                cout << "Enter new licence plate: ";
                cin >> licencePlate;
                break;
            case 4:
                cout << "Enter new location from the list: " << endl;;
                sleep(1);
                cm.showUSAStates();
                cout << endl;
                cout << "Enter the abreviation of your state: ";
                cin >> location;
                break;
            case 5:
                cout << "Enter new driver licence age: ";
                cin >> driverLicenceAge;
                break;
            case 6:
                cout << "Enter new car model from the list:";
                sleep(1);
                cm.showBrands();
                cout << endl;
                cout << "Enter your car brand: ";
                cin >> carDetails.brand;
                break;
            case 7:
                cout << "Enter new car year: ";
                cin >> carDetails.year;
                break;
            case 8:
                cout << "Enter new policy type: ";
                cin >> policyType;
                break;
            case 9:
                cout << "Exiting modification menu." << endl << endl << endl;
                sleep(1);
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 9);
}

double Driver::getPolicyPrice() {
    return policyPrice;
}

void Driver::generatePolicyFile() {
    //Generates the . txt file by invoking the method of the FileGenerator class
    FileGenerator f(licencePlate, carDetails, policyType, name, id, policyPrice);
    f.generatePolicy();
}

void Driver::showPolicyFile() {
    //Display the . txt file by calling the method of the FileGenerator class
    FileGenerator f(licencePlate, carDetails, policyType, name, id, policyPrice);
    f.showPolicy();
}