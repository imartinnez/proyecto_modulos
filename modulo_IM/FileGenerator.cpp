#include "FileGenerator.hpp"
using namespace std;

FileGenerator::FileGenerator(string licensePlate, carModel carDetails, string name, string id, double price) {
    this->licensePlate = licensePlate;
    this->carDetails = carDetails;
    this->name = name;
    this->id = id;
    this->price = price;
}

void FileGenerator::generatePolicy() {
    
    
    
    // Obtener el tiempo actual
    time_t now = time(0);
    // Convertir el tiempo actual a una estructura tm
    tm time = *localtime(&now);                                

    ofstream file("PolicyFile.txt");
    if (file.is_open()) {
        file << "------------------------------------------------------------------------------------\n\n";
        file << "                                POLICY CERTIFICATE\n";
        file << "------------------------------------------------------------------------------------\n\n";
        file << "POLICY NUMBER: 201294845                                     INSURER ID: 20339560tY\n";
        file << "LICENSE PLATE: " << licensePlate << "\n";
        file << "VEHICLE:       " << carDetails.brand << "  " << carDetails.year << "\n";
        file << "OWNER:         " << name << "\n\n";
        file << "CONTRACT DATE: " << time.tm_mday << "/" << time.tm_mon + 1 << "/" << time.tm_year + 1900 << "\n"; //tm_mon es el número de meses desde enero (0-11) y tm_year es el número de años desde 1900 por eso se le suma 1900
        file << "------------------------------------------------------------------------------------\n\n";
        file << "INSURED DETAILS\n";
        file << "NAME: " << name << "\n";
        file << "ID:   " << id << "\n\n";
        file << "COVERAGES:\n";
        file << "- MANDATORY CIVIL LIABILITY INSURANCE                INCLUDED\n";
        file << "- THE TYPE OF INSURANCE                              "                                 "\n";
        file << "- THE PRICE OF THE INSURANCE WITHOUT VAT:            " << (price - (price*0.21)) << "\n";
        file << "- THE PRICE OF THE INSURANCE WITH VAT:               " << price << "\n\n";
        file << "This certificate must be accompanied by the International Motor Insurance Certificate for circulation within the territorial scope of the European Economic Area.\n\n";
        file << "And for it to be so noted for the purposes of evidence of the existence of the insurance policy before the Traffic Department, its Agents and other competent authorities, the present is issued,\n\n";
        file << "For the Company,\n\n";
        file << "------------------------------------------------------------------------------------\n";
        file << "Chief Technical Officer\n";
        file << "Madrid, Spain   " << time.tm_mday << "/" << time.tm_mon + 1 << "/" << time.tm_year + 1900 << "\n";
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }
}

void FileGenerator::showPolicy() {
    // Display the contents of the file on the console
    ifstream file("PolicyFile.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Unable to open file for reading" << endl;
    }
}
