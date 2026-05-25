#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <limits>
#include "employee.h"
#include "database.h"
using namespace std;

int menu();

void clearInputBuffer();

int main() {
    system("color e1"); //from <cstdlib> library

    Database database;
    Employee emp;
    string filename;

    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|                                          |EMPLOYEE MANAGEMENT SYSTEM|                                                |" << endl ;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

    cout << "Enter the name of the file (without extension): ";
    getline(cin, filename);
    filename += ".txt";

    ifstream fin(filename.c_str());

    if (!fin) {

        cout << "File does not exist, creating new file: " << filename << endl;
        ofstream new_file(filename.c_str());
        if (!new_file) {
            cout << "Failed to create file. Please check your permissions or path." << endl;
            return 1;  // Exit if file creation fails
        }
        new_file.close();
        fin.open(filename.c_str());  // Try opening the new file
    }

    if (!fin) {
        cout << "Failed to open file for reading after creating." << endl;
        return 1;
    }

    database.load(fin);
    fin.close();

    int choice = 0;
    while (choice != 8) {
        choice = menu();
            switch (choice) {
                case 1: {
                    //exception handling
                    try {
                        cin >> emp;
                        database.add(emp);
                        //to Catch any exceptions
                    } catch (const exception& e) {
                        cout << "Error adding employee: " << e.what() << endl;
                    }
                    break;
                }
                case 2: {
                    system("cls");
                    if (database.is_empty()) {
                        cout << "There are no employees to search for in the company. ADD EMPLOYEE'S!" << endl;
                        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
                    }
                    else{
                    string name;
                    cout << "Enter the employee's name: ";
                    if (cin.peek() == '\n') cin.ignore();
                    getline(cin, name);
                    try {
                        database.search(name);
                    } catch (const exception& e) {
                        cout << "Error searching employee: " << e.what() << endl;
                    }
                    }
                    break;
                }
                case 3: {
                    system("cls");
                    if (database.is_empty()) {
                        cout << "There are no employees to search for in the company. ADD EMPLOYEE'S!" << endl;
                        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
                    }
                    else{
                    int id;
                    cout << "Enter ID number: ";
                    cin >> id;
                    try {
                        database.search_id(id);
                    } catch (const exception& e) {
                        cout << "Error searching employee by ID: " << e.what() << endl;
                    }
                    }
                    break;
                }
                case 4: {
                    system("cls");
                    if (database.is_empty()) {
                        cout << "There are no employees in the database yet. PLEASE ADD EMPLOYEE'S!" << endl;
                        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
                    }
                    else{
                    cout << "All the employees in the database!" << endl;
                    database.display_all();
                    }
                    break;
                }
                case 5: {
                    system("cls");
                    if (database.is_empty()) {
                        cout << "There are no employees in the company to sack." << endl;
                        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
                    }
                    else{
                    string name;
                    cout << "Enter the name of the employee that was sacked: ";

                    if (cin.peek() == '\n') cin.ignore();
                    getline(cin, name);
                    try {
                        database.remove(name);
                    } catch (const exception& e) {
                        cout << "Error removing employee: " << e.what() << endl;
                    }
                    }
                    break;
                }
                case 6: {
                    system("cls");
                    try {
                        database.sort_salary();
                        if(database.is_empty()){
                            cout << "NO EMPLOYEES TO SORT IN DATABASE!" << endl;
                            cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
                        }
                        else{
                        cout << "Employees sorted by salary!" << endl;
                        database.display_all();
                        }
                    } catch (const exception& e) {
                        cout << "Error sorting by salary: " << e.what() << endl;
                    }
                    break;
                }
                case 7: {
                    system("cls");
                    try {
                        database.sort_name();
                        if (database.is_empty()) {
                            cout << "NO EMPLOYEES TO SORT IN DATABASE!" << endl;
                            cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
                        }
                        else{
                        cout << "Employees sorted by name!" << endl;
                        database.display_all();
                        }
                    } catch (const exception& e) {
                        cout << "Error sorting by name: " << e.what() << endl;
                    }
                    break;
                }
                case 8: {
                    break;
                }
                case 9: {
                    system("cls");

                    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "Welcome, this is an Employee Management System that helps you to save the informations of every employee in a certain " << endl;
                    cout << "company, and this how you can use it:)" << endl;
                    cout << endl;
                    cout << "If you press on [1] the system will ask you add the employees information. i.g. name, ID, salary...etc" << endl;
                    cout << endl;
                    cout << "If you press on [2] the system will ask you to search for the employees by name and if you put a wrong name the system  " << endl;
                    cout << "will say 'No employee by that name!' " << endl;
                    cout << endl;
                    cout << "If you press on [3] the system will ask you to search for the employees by ID and if you put a wrong ID the system  " << endl;
                    cout << "will say 'No employee by that ID!' " << endl;
                    cout << endl;
                    cout << "If you press on [4] the system will display all the employees in the company " << endl;
                    cout << endl;
                    cout << "If you press on [5] the system will ask you to enter the name of the employee that was sacked to remove him his info " << endl;
                    cout << endl;
                    cout << "If you press on [6] the system will sort all the employees by name " << endl;
                    cout << endl;
                    cout << "If you press on [7] the system will sort all the employees by salary " << endl;
                    cout << endl;
                    cout << "If you press on [8] the system will EXIT " << endl;
                    cout << endl;
                    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;


                    break;
                }
                default: {
                    system("cls");
                    cout << "NOT A VALID INPUT! " << endl;
                    break;
                }
            }
        }

        ofstream fout(filename.c_str());
    if (!fout) {
        cout << "Failed to open file for writing." << endl;
        return 1;
    }
    database.save(fout);
    fout.close();

    return 0;
}

int menu() {
    int choice;

    cout << "1. Add new employee." << endl;
    cout << "2. Search for employee by name." << endl;
    cout << "3. Search for employee by ID number." << endl;
    cout << "4. Display all current employees." << endl;
    cout << "5. Remove employee from database." << endl;
    cout << "6. Sort employees by salary." << endl;
    cout << "7. Sort employees by first name." << endl;
    cout << "8. Quit." << endl;
    cout << endl;
    cout << "**9. HOW TO USE.**" << endl;
    cout << endl;
    cout << "Enter your choice: ";

    cin >> choice;
    if (cin.fail()) {
        cin.clear();
        clearInputBuffer();
        cout << "Invalid input. Please enter a valid number." << endl;
    }
    return choice;
}

void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}




