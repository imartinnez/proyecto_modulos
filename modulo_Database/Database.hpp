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
#ifndef DATABASE_HPP
#define DATABASE_HPP


#include <iostream>  // To use cout, cin...
#include <fstream>   // For file management, fstream and ofstream use
#include <sstream>   // To work with stringstream
#include <vector>    // To use vector<>
#include <string>    // To handle strings
using namespace std;

class Database {
private:
    vector<vector<string>> data; // Vector that stores the rows of the .CSV and their respective data as vectors of strings.
    vector<string> headers;      // Vector that stores the headers of each column.

public:
    /**
     * Constructor of the Database class.
     */
    Database();

    /**
     * Gets the data from the database.
     * 
     * @return Vector that stores the rows of the .CSV and their respective data as vectors of strings.
     */
    vector<vector<string>> getData();

    /**
     * Gets the headers from the database.
     * 
     * @return Vector that stores the headers of each column.
     */
    vector<string> getHeaders();

    /**
     * This method reads the .CSV file and stores the data in the `data` and `headers` vectors.
     */
    void loadCSV();
};

#endif // DATABASE_HPP
