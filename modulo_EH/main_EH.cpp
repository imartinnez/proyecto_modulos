/**
 * @author: Eduardo Hortelano
 * 
 * Module: modulo_EH
 * 
 * @class main_EH
 * 
 * main Class to generate json 
 */
#include <iostream>
#include "GenerateJSON.hpp"
#include "../modulo_Database/Database.hpp"
#include "json.hpp"
using namespace std;
int main(){
    Database db;
    GenerateJSON json(db);
    json.generateJSON();
    cout << "File .json generated successfully!!" << endl << endl << endl;
    return 0;
}