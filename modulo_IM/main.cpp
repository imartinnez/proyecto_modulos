#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "../modulo_dev/Database.hpp"
#include "../modulo_IM/carModel.hpp"
#include "../modulo_IM/CarModelList.hpp"
using namespace std;

int main() {

    carModel a;
    carModel b;
    CarModelList l1(a.brand, a.year);
    

    cout << "Bienvenido, escoja su marca de coche entre la siguiente lista:" << endl; //TIENE QUE SER EN INGLÉS
    l1.showBrands();
    cin >> a.brand;
    cout << "Ahora introduzca el año de fabricación de su coche:" << endl;
    cin >> a.year;
    l1.setCarDetails(a.brand, a.year);
    b = l1.getCarDetails();
    cout << b.brand << "    " << b.year; 
    


    return 0;
}