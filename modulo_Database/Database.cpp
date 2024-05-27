/**
 * @author: Iñigo Martínez
 * 
 * Module: modulo_Database
 * 
 * @class Database
 * 
 * This class allows loading and managing data from the .CSV file to be analyzed, storing them
 * in vectors of strings. It also provides methods to obtain this data as well as the column headers.
 */
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
    ifstream file("modulo_Database/DATABASE.csv");
    if (!file.is_open()) {
        cout << "Error with the file" << endl;
        exit(0);
    }

    // Clear any existing data in the data and headers vectors
    data.clear();
    headers.clear();

    string line;
    // Read the first line, which contains the headers
    if (getline(file, line)) {
        /**
         * Since the line we are reading contains various data within it, to facilitate extraction
         * of these, we use a stringstream variable that allows us to split our line based on our
         * CSV delimiter which is ;
        */
        stringstream stream(line);
        string header;

        // Separate the headers using ; as delimiter and store them in the headers vector
        while (getline(stream, header, ';')) {
            headers.push_back(header);
        }
    }

    // Iterate through the rest of the lines in the CSV
    while (getline(file, line)) {
        stringstream stream(line); // Similar to headers, we need to declare a stringstream variable
        vector<string> row; // Vector to store row data
        string cell;

        // Separate the row data using ; as delimiter and store them in the row vector
        while (getline(stream, cell, ';')) {
            row.push_back(cell);
        }

        // Add the row of data to the data vector
        data.push_back(row);
    }

    file.close();
}