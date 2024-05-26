/**
 * @author: Iñigo Martínez
 * 
 * Module: modulo_IM
 * 
 * @class FileGenerator
 * 
 * The FileGenerator class handles the creation and display of .txt policy files,
 * using car information and client data.
 */
#include "FileGenerator.hpp"
using namespace std;

FileGenerator::FileGenerator(string licensePlate, carModel carDetails, int policyType, string name, string id, double price) {
    this->licensePlate = licensePlate;
    this->carDetails = carDetails;
    this->policyType = policyType;
    this->name = name;
    this->id = id;
    this->price = price;
}

void FileGenerator::generatePolicy() {
    string insuranceType;
    
    // We convert the policy type attribute to a string to display it in the .txt file
    if(policyType == 0) {insuranceType = "TTHIRD-PARTY INSURANCE";}
    else {insuranceType = "COMPREHENSIVE INSURANCE";}
    
    // Thanks to the ctime library, we get the current time and convert it into a tm structure
    time_t now = time(0);
    tm time = *localtime(&now);                                

    // We open the file and write all the attributes of the policy in it
    ofstream file("PolicyFile.txt");
    if (file.is_open()) {
        file << "-------------------------------------------------------------------------------------------------\n";
        file << "                                    POLICY CERTIFICATE\n";
        file << "-------------------------------------------------------------------------------------------------\n\n";
        file << "POLICY NUMBER: 201294845                                     INSURER ID: 20339560tY\n";
        file << "LICENSE PLATE: " << licensePlate << "\n";
        file << "VEHICLE:       " << carDetails.brand << "  " << carDetails.year << "\n";
        file << "OWNER:         " << name << "\n\n";
        // Since tm_mon is the number of months since January (0-11) we add 1, and since tm_year is the number of years since 1900 until now we add 1900
        file << "CONTRACT DATE: " << time.tm_mday << "/" << time.tm_mon + 1 << "/" << time.tm_year + 1900 << "\n\n";
        file << "-------------------------------------------------------------------------------------------------\n";
        file << "INSURED DETAILS\n";
        file << "-------------------------------------------------------------------------------------------------\n";
        file << "NAME: " << name << "\n";
        file << "ID:   " << id << "\n\n";
        file << "-------------------------------------------------------------------------------------------------\n";
        file << "COVERAGES:\n";
        file << "- MANDATORY CIVIL LIABILITY INSURANCE                INCLUDED\n";
        file << "- THE TYPE OF INSURANCE                              " << insuranceType << "\n";
        file << "- THE PRICE OF THE INSURANCE WITHOUT VAT:            " << (price - (price*0.21)) << "$\n";
        file << "- THE PRICE OF THE INSURANCE WITH VAT:               " << price << "$\n\n\n";
        file << "This    certificate   must  be accompanied   by   the   International  Motor    Insurance\n\n"; 
        file << "Certificate   for circulation withinthe territorial scope of the European Economic  Area.\n\n";
        file << "And for it to be so noted for the purposes of evidence   of   the  existence   of     the\n\n";
        file << "insurance   policy   before the Traffic   Department,   its Agents  and other   competent\n\n"; 
        file << "authorities, the present is issued, Madrid, " << time.tm_mday << "/" << time.tm_mon + 1 << "/" << time.tm_year + 1900 << "\n\n";
        file << "For the Company\n\n";
        file << "-------------------------------------------------------------------------------------------------\n";
        file << "Chief Technical Officer\n";
        file << "Madrid, Spain   " << time.tm_mday << "/" << time.tm_mon + 1 << "/" << time.tm_year + 1900 << "\n";
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }
}

void FileGenerator::showPolicy() {
    // We open the file and print it line by line thanks to getline()
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
    cout << endl << endl << endl;
}
