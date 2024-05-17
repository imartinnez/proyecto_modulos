#include "Database.hpp"
using namespace std;


Database::Database() {};

vector<vector<string>> Database::getData() {
    return data;
}
vector<string> Database::getHeaders() {
    return headers;
}


void Database::loadCSV() {
    ifstream file("modulo_dev/DATABASE.csv");
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
    Database db;
    db.loadCSV();
    vector<vector<string>> datos = db.getData();
    vector<string> encabezados = db.getHeaders();

    cout << "Encabezados:" << endl;
    for (string header : encabezados) {
        cout << header << "\t";
    }
    cout << endl;


    cout << "Datos:" << endl;
    for (vector<string> fila : datos) {
        for (string celda : fila) {
            cout << celda << "\t";
        }
        cout << endl;
    }
    

    return 0;
}
*/