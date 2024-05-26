/**
 * @author: Iñigo Martínez
 *
 * Module: modulo_IM
 * 
 * @struct carModel
 *
 * Structured data type that stores basic information about a car model,
 * including the brand of the car and the year it was manufactured.
 */
#ifndef CARMODEL_HPP
#define CARMODEL_HPP

#include <string>    // To handle strings
using namespace std;

struct carModel {
    string brand;
    int year; 
};

#endif // CARMODEL_HPP
