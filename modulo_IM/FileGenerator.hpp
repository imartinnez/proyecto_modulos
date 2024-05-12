#ifndef FILE_GENERATOR_HPP
#define FILE_GENERATOR_HPP

#include <iostream>
#include <string>
#include "modulo_dev/Database.hpp"
#include "carModel.hpp"
#include "Policy.hpp"
using namespace std;

class FileGenerator {
private:
    string fileName;
    Policy policy;

public:
    FileGenerator(string fileName, Policy policy);
    void setFileName(string fileName);
    void setPolicy(Policy policy);

     void generatePolicy(Policy policy);
};




#endif //FILE_GENERATOR_HPP