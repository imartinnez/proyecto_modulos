#include "Database.hpp"
using namespace std;


Database::Database() {};

const vector<vector<string>>& Database::getData() const {
    return data;
}
const vector<string>& Database::getHeaders() const {
    return headers;
}


void Database::loadCSV(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "El archivo no se ha podido abrir" << endl;
        return;
    }

    data.clear();
    headers.clear();

    string line;
    if (getline(file, line)) {
        stringstream ss(line);
        string header;

        while (getline(ss, header, ';')) {
            headers.push_back(header);
        }
    }

    while (getline(file, line)) {
        stringstream ss(line);
        vector<string> row;
        string cell;

        while (getline(ss, cell, ';')) {
            row.push_back(cell);
        }

        data.push_back(row);
    }

    file.close();
}




/*MAIN DE PRUEBA PARA COMPROBAR SI FUNCIONA
int main() {
    Database& db = Database::getInstance(); //Se hace uso del Singleton
    db.loadCSV("BDexcel.csv");             

    const vector<vector<string>>& datos = db.getData();       // Obtener los datos cargados
    const vector<string>& encabezados = db.getHeaders();       // Obtener los encabezados del archivo


    cout << "Encabezados:" << endl;
    for (const auto& header : encabezados) {
        cout << header << "\t";
    }
    cout << endl;


    cout << "Datos:" << endl;
    for (const auto& fila : datos) {
        for (const auto& celda : fila) {
            cout << celda << "\t";
        }
        cout << endl;
    }
    

    return 0;
}
*/