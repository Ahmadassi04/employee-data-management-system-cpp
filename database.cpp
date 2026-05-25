#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include "database.h"
using namespace std;

Database::Database(){
    used = 0;
    capacity = 5;
    data = new Employee[capacity];
}

//To create a new Database object as a copy of an existing Database object (other).
Database::Database(const Database& other){
    used = other.used;
    capacity = other.capacity;
    data = new Employee[capacity];
    copy(other.data,other.data+used,data); //Beginning \ Ending \ Distination
}

//To clean up resources when a Database object is destroyed.
Database::~Database(){
    delete []data; //free the memory allocated, to prevent memory leaks.
}

//To assign one Database object (other) to another existing Database object.
void Database::operator=(const Database& other){
    if(&other == this){ //check if the other instance is the same as the current instance (this)
        return;
    }
    delete[]data;
    capacity = other.capacity;
    used = other.used;
    data = new Employee[capacity];
    copy(other.data,other.data+used,data);
}

void Database::make_bigger(){
    Employee *tmp;
    tmp = new Employee[capacity + 5]; // + 5 is to make a temporary array with bigger capacity
     copy(data,data+used,tmp);
     delete []data;
     data = tmp;
     capacity += 5;
}

void Database::search(string name){
    int num_found = 0;
    for(int i = 0; i < used; i++ ){
        if(data[i].get_name() == name){
            cout << "Employee Found!" << endl;
            data[i].output(cout);
            num_found++;
            cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        }
    }
    if(num_found == 0){
        cout << "No employee by that name!" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    }
}

void Database::search_id(int id){
    int num_found = 0;
    for(int i = 0; i < used; i++ ){
        if(data[i].get_idNumber() == id){
            cout << "Employee Found!" << endl;
            data[i].output(cout);
            num_found++;
            cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        }
    }
    if(num_found == 0){
        cout << "No employee by that ID!" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    }
}

void Database::add(const Employee& emp){
    if(used >= capacity){
        make_bigger();
    }
    data[used] = emp;
    used ++;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
}

void Database::display_all(){
    for(int i = 0; i < used; i++){
        data[i].output(cout);
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    }
}

void Database::remove(string name) {
    bool found = false;
    for (int i = 0; i < used; i++) {
        if (data[i].get_name() == name) {
            data[i] = data[used - 1];
            used--;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "THIS EMPLOYEE DOES NOT WORK IN THIS COMPANY!" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    }
}

void Database::save(ostream& outs){
    sort_name();
    for(int i = 0; i < used; i++){
        outs << data[i];
    }
}

void Database::load(istream& ins){
    Employee tmp;
    while(ins >> tmp){
        if(used >= capacity){
            make_bigger();
        }
        data[used] = tmp;
        used++;
    }
}

void Database::sort_name(){  // Bubble sorting(swapping elements in an array)

    bool done = false;
    Employee tmp;
    while(!done){
        done = true;
        for(int i = 0; i < used - 1; i++){
            if(data[i].get_name() > data[i+1].get_name()){
                done = false;
                tmp = data[i];
                data[i] = data[i+1];
                data[i+1] = tmp;
            }
        }
    }
}

void Database::sort_salary(){
    bool done = false;
    Employee tmp;
    while(!done){
        done = true;
        for(int i = 0; i < used - 1; i++){
            if(data[i].get_salary() > data[i+1].get_salary()){
                done = false;
                tmp = data[i];
                data[i] = data[i+1];
                data[i+1] = tmp;
            }
        }
    }
}

