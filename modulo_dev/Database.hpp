#ifndef DATABASE_HPP
#define DATABASE_HPP


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class Database {
private:
    vector<vector<string>> data; // vector que almacena vectores de tipo string
    vector<string> headers;      // vector que almacena las cabeceras de cada columna

public:
    Database();
    vector<vector<string>> getData();
    vector<string> getHeaders();

    void loadCSV();
};

#endif //DATABASE_HPP