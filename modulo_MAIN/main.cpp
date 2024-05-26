/**
 * @author: Luis Sánchez
 * 
 * Module: modulo_MAIN
 * 
 * @class main
 * 
 * This class  is responsible for grouping all modules. It does so that once the
 * user has chosen the module, the . exe of the module is invoked
 */
#include <iostream>   // To use cout, cin...
#include <unistd.h>   // To use the sleep() function
#include <cstdlib>    // To use the system() function
#include <filesystem> // To use std::filesystem

using namespace std;
/**
 * When programs are run directly from their modules, the relative path to the
 * .CSV file works because it is relative to the directory from which the 
 * program is run. However, when they are run through the main menu, the 
 * working directory is different, causing relative paths to fail. To fix this, 
 * we use std::filesystem, changing the working directory while the program 
 * runs.
*/
namespace filesys = std::filesystem;

void carDrawing();

int main() {
    
    
    int option;

    carDrawing();
    // Options menu
    cout << "Select the module you want to access:\n";
    cout << "1. Module in which the price of your car insurance policy will be calculated based on your location\n";
    cout << "2. Module where you can access a city comparator analyzing car accidents and receiving personalized recommendations\n";
    cout << "3. Module where you can generate a .json file to see the cities with car accidents and the weather at the time of the accidents\n";
    cout << "Enter your option: ";
    cin >> option;

    switch(option) {
        case 1:
            cout << "Accessing module 1..." << endl;
            sleep(2);
            filesys::current_path("modulo_IM"); // Change directory to Modulo_IM
            system("program_IM.exe");           // Run main_IM.cpp of Modulo_IM
            filesys::current_path("..");        // Return to the main directory
            break;
        case 2:
            cout << "Accessing module 2..." << endl;
            sleep(2);
            filesys::current_path("modulo_LS"); // Change directory to Modulo_LS
            system("program_LS.exe");           // Run main_LS.cpp of Modulo_LS
            filesys::current_path("..");        // Return to the main directory
            break;
        case 3:
            cout << "Accessing module 3..." << endl;
            sleep(2);
            filesys::current_path("modulo_EH"); // Change directory to Modulo_EH
            system("program_EH.exe");           // Run main_EH.cpp of Modulo_EH
            filesys::current_path("..");        // Return to the main directory
            break;
        case 4:
            cout << "Exiting the program..." << endl;
            sleep(1);
            cout << "Goodbye!!";
            break;
        default:
            cout << "Invalid option. Enter an option from the list.\n";
    }
    return 0;
}


void carDrawing() {
    cout << "                ______" << endl;
    cout << "               //  ||\\ \\" << endl;
    cout << "          ____//___||_\\ \\___" << endl;
    cout << "          )  _          _    \\" << endl;
    cout << "          |_/ \\________/ \\___|" << endl;
    cout << "         ___\\_/________\\_/______" << endl;
    cout << "            /  O           O  \\" << endl << endl;
    cout << "==============================================" << endl;
    cout << "COMPREHENSIVE CAR ACCIDENT ANALYSIS PROGRAMME" << endl;
    cout << "==============================================" << endl << endl << endl;
}