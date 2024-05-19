#ifndef FILE_GENERATOR_HPP
#define FILE_GENERATOR_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "../modulo_dev/Database.hpp"
#include "../modulo_IM/carModel.hpp"
#include "../modulo_IM/Policy.hpp"
using namespace std;

class FileGenerator {
private:
    string licensePlate;
    carModel carDetails;
    string name;
    string id;
    double price;

public:
    FileGenerator(string licensePlate, carModel carDetails, string name, string id, double price);
    void generatePolicy();
    void showPolicy();
};




#endif //FILE_GENERATOR_HPP