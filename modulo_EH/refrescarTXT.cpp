// refrescarTXT.cpp
#include "refrescarTXT.hpp"

using json = nlohmann::json;
using namespace std;

RefrescarTXT::RefrescarTXT(Database db)  {
    this->db=db;
}

void RefrescarTXT::filterCityWeather() {
    db.loadCSV();
    int cityIndex;
    int weatherIndex;
    json cities;
    vector<vector<string>> data= db.getData();
    vector<string> headers=db.getHeaders();
    for(int i=0; i< headers.size(); i++){
        if(headers[i]=="City"){
            cityIndex=i;
        }
        else if(headers[i]=="Wheather_Condition"){
            weatherIndex=i;
        }
    }
    //TODO bucle for each
    // inicializar json vacio
    for(const auto& row : data){
        string city= row[cityIndex];
        string weather = row[weatherIndex];
        if(!cities.contains(city)){
            cities[city]= json::object();
            cities[city][weather] = {{"counter", 1}};
        }
        else{
            if(!cities[city].contains(weather)){
                cities[city][weather] = {{"counter", 1}};
            }
            else{
                cities[city][weather]["counter"] = cities[city][weather]["counter"].get<int>() + 1;
            }            
        }       
        //Si ciudad NO existe introducirla a json
            // Incluir weather con valor a 1
        // Si ciudad SI existe
            // Si weather NO existe
               // Incluir weather con valor a 1 
            // Si weather SI existe 
    }
    ofstream outputfile("citiesWeather.json");
    if(outputfile.is_open()){
        outputfile << cities.dump(4);
        outputfile.close();
    }else{
        cout<<"Error trying to generate .json file"<<endl;
    }
    // guardad json en archivo
}


