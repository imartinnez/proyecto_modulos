#ifndef CAR_MODEL_LIST_HPP
#define CAR_MODEL_LIST_HPP

#include <iostream>
#include <string>
#include "../modulo_dev/Database.hpp"
#include "../modulo_IM/carModel.hpp"

using namespace std;

class CarModelList {
private:
    carModel carDetails;

public:
    CarModelList();
    CarModelList(string brand, int year);
    string getCarBrand();
    int getCarYear();
    void setCarDetails(string brand, int year);
    
    void showBrands();
    string getRangeLevel();
};

#endif //CAR_MODEL_LIST_HPP