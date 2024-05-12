#ifndef CAR_MODEL_LIST_HPP
#define CAR_MODEL_LIST_HPP

#include <iostream>
#include <string>
#include "../modulo_dev/Database.hpp"
#include "carModel.hpp"

using namespace std;

class CarModelList {
private:
    carModel carDetails;

public:
    CarModelList(string brand, int year);
    carModel getCarDetails();
    void setCarDetails(string brand, int year);
    
    void showBrands();
    string getRangeLevel(carModel carDetails);
};

#endif //CAR_MODEL_LIST_HPP