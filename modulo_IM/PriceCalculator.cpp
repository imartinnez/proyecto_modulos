#include "PriceCalculator.hpp"
using namespace std;

PriceCalculator::PriceCalculator(Database db) { //, string carRangeLevel, int accidentSeverity, int accidentNumber) {
    this->db = db;
    /*
    this->carRangeLevel = carRangeLevel;
    this->accidentSeverity = accidentSeverity;
    this->accidentNumber = accidentNumber;
    this->weatherMultiplier = weatherMultiplier;
    */  //!!!!IMPORTANTE¡¡¡ cambiar los artributos de la clase e intentar combinarlos con, lo de los metodos 
}

double PriceCalculator::calculatePolicyBasePrice(carModel carDetails, string carRangeLevel, int driverLicenceAge, int policyType) {
    double basePrice; 

    //calculo del precio base
    if(carRangeLevel == "luxury") {basePrice = 3000.0;}
    else if(carRangeLevel == "high") {basePrice = 1500.0;}
    else if(carRangeLevel == "medium") {basePrice = 800.0;}
    else {basePrice = 400.0;}

    //edad del conductor  (el caso medio no se pone, ya que mantiene el precio base)
    if(driverLicenceAge < 5) {basePrice += 400.0;}
    else if(driverLicenceAge >= 20) {basePrice -= 100.0;}

    //tipo de seguro
    if(policyType == 1) {basePrice *= 2.5;} //si es igual a 1, es decir, una poliza a todo riesgo, se aumenta un 150%

    //año del coche
    if(carDetails.year >= 4 && carDetails.year < 10) {basePrice += 100.0;}
    else if(carDetails.year >= 10) {basePrice += 300.0;}

    return basePrice;
}


double PriceCalculator::calculatePolicyPrice(string location, double basePrice) {

    double totalAccidents; //total de accidentes
    double accidentCounter;  //accidentes de un estado, lo hacemos double para que cuando operemos con el las variables resultantes tengan decimales
    int stateIndex; //indice de la columna State

    db.loadCSV();
    vector<string> row; //vector para almacenar las filas de los accidentes
    vector<vector<string>> data = db.getData();
    vector<string> headers = db.getHeaders();
    totalAccidents = data.size();

    
    for(int h = 0; h < headers.size(); h++) {
        if(headers[h] == "State") {
            stateIndex = h;
            break;
        }
    }
    for(int i = 0; i < data.size(); i++) {
        row = data[i];
        if(row[stateIndex] == location) {
            accidentCounter++;
        }
    }

    //PASAMOS basePrice por referencia porque son funciones void que actualizan el valor de basePrice
    calculatePriceNumberAccidents(accidentCounter, basePrice);
    calculatePriceSeverityAccidents(data, headers, location, basePrice, stateIndex, totalAccidents, accidentCounter);
    calculatePriceWeatherAccidents(data, headers, location, basePrice, stateIndex, accidentCounter);

    return basePrice;
}



void PriceCalculator::calculatePriceNumberAccidents(double accidentCounter, double &basePrice) {
    //CALCULO DEL PRECIO EN FUNCION DEL NUMERO DE ACCIDENTES/ESTADO
    if(accidentCounter < 1000) {basePrice -= 25.0;}
    else if(accidentCounter > 5000) {basePrice += 50.0;}
}



void PriceCalculator::calculatePriceSeverityAccidents(vector<vector<string>> data, vector<string> headers, string location, double &basePrice, int stateIndex, double totalAccidents, double accidentCounter) {
    int severityCounter = 0; //suma de los valores de severity de un estado
    double severityAverage;//media de el valor severity de todos los accidentes
    double severityValue; //suma de los valores de severity de todos los accidentes
    int severityIndex; //indice de la columna Severity
    vector<string> row; //vector para almacenar las filas de los accidentes

    //CALCULO DEL PRECIO EN FUNCION DE LA PELIGROSIDAD DE LOS ACCIDENTES EN EL ESTADO
    for(int s = 0; s < headers.size(); s++) {
        if(headers[s] == "Severity") {
            severityIndex = s;
            break;
        }
    }
    for(int i = 0; i < data.size(); i++) {
        row = data[i];
        if(row[stateIndex] == location) {
            severityCounter +=  stoi(row[severityIndex]);    //hacemos uso de stoi, para castear las celdas de tipo string en int
        }
    }

    //calculo de la media del valor de AS
    for(int i = 0; i < data.size(); i++) {
        row = data[i];
        severityValue += stoi(row[severityIndex]);
    }

    severityAverage = severityValue/totalAccidents;//calulo de la suma de Severity de todos los accidentes entre el numero de los accidentes

    if(severityCounter/accidentCounter < severityAverage) {
        basePrice -= 50.0;
    }
}



void PriceCalculator::calculatePriceWeatherAccidents(vector<vector<string>> data, vector<string> headers, string location, double &basePrice, int stateIndex, double accidentCounter) {
    int weatherIndex; //indice de la columna Weather_Condition
    double weatherCounter; //suma de los valores de las weatherConditions
    double weatherMultiplier; //multiplicador al que se le multiplica al precio base, el cual se saca de la formula
    vector<string> row; //vector para almacenar las filas de los accidentes

    //CALCULO DEL PRECIO EN FUNCION DEL TIEMPO METEOROLOGICO EN UN ESTADO
    for(int w = 0; w < headers.size(); w++) {
        if(headers[w] == "Weather_Condition") {
            weatherIndex = w;
            break;
        }
    }
    for(int i = 0; i < data.size(); i++) {
        row = data[i];
        if(row[stateIndex] == location) {
            if(row[weatherIndex] == "Tornado") {weatherCounter += 6.0;}
            else if(row[weatherIndex] == "Heavy Snow") {weatherCounter += 5.0;}
            else if(row[weatherIndex] == "Heavy Rain" || row[weatherIndex] == "Hail") {weatherCounter += 4.0;}
            else if(row[weatherIndex] == "T-Storm" || row[weatherIndex] == "Snow") {weatherCounter += 3.0;}
            else if(row[weatherIndex] == "Rain" || row[weatherIndex] == "Fog") {weatherCounter += 2.0;}
            else {weatherCounter += 1.0;}
        }
    }

    weatherMultiplier = (weatherCounter/accidentCounter);
    basePrice *= weatherMultiplier;
}