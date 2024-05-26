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
#ifndef FILE_GENERATOR_HPP
#define FILE_GENERATOR_HPP

#include <iostream>  // To use cout, cin...
#include <fstream>   // For file management, fstream and ofstream use
#include <string>    // To handle strings
#include <ctime>     // To use time()
#include "../modulo_Database/Database.hpp"
#include "../modulo_IM/carModel.hpp"
#include "../modulo_IM/Policy.hpp"
using namespace std;

class FileGenerator {
private:
    string licensePlate; // The car's license plate.
    carModel carDetails; // Car details.
    int policyType;      // Type of policy.
    string name;         // Policyholder's name.
    string id;           // Policyholder's ID.
    double price;        // Policy price.

public:
    /**
     * Constructor of the FileGenerator class. Initializes a 
     * FileGenerator object with the provided details.
     */
    FileGenerator(string licensePlate, carModel carDetails, int policyType, string name, string id, double price);

    /**
     * Generates the policy file. This method generates a file 
     * that contains the insurance policy information.
     */
    void generatePolicy();

    /**
     * This method prints the insurance policy details to the console.
     */
    void showPolicy();
};

#endif // FILE_GENERATOR_HPP

