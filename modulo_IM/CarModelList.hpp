/**
 * @author: Iñigo Martínez
 * 
 * Module: modulo_IM
 * 
 * @class CarModelList
 * 
 * The CarModelList class allows managing the list of car brands as well as their
 * brand status and the list of USA state abbreviations.
 */
#ifndef CAR_MODEL_LIST_HPP
#define CAR_MODEL_LIST_HPP

#include <iostream>  // To use cout, cin...
#include <fstream>   // For file management, fstream and ofstream use
#include <string>    // To handle strings
#include "../modulo_IM/carModel.hpp"

using namespace std;

class CarModelList {
private:
    carModel carDetails; // Structured data type that contains car details.

public:
    /**
     * Constructor of the CarModelList class.
     */
    CarModelList();

    /**
     * Constructor that initializes the car details with a brand and a year.
     */
    CarModelList(string brand, int year);

    /**
     * Gets the car brand from user input by searching for it
     * in a .txt file.
     * 
     * @return Car brand.
     */
    string getCarBrand();

    /**
     * Gets the car year.
     * 
     * @return Car year.
     */
    int getCarYear();

    /**
     * Sets the car details.
     * 
     * @param brand Car brand.
     * @param year Car year.
     */
    void setCarDetails(string brand, int year);
    
    /**
     * Displays the available car brands, showing part of the
     * .txt file on screen, where the brands appear.
     */
    void showBrands();

    /**
     * Displays the USA states as well as their identifiers which
     * are the abbreviations of those states.
     */
    void showUSAStates();

    /**
     * Gets the car's range level by searching for it in the
     * .txt file from user input.
     * 
     * @return Car range level.
     */
    string getRangeLevel();
};

#endif //CAR_MODEL_LIST_HPP

