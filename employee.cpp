#include <iostream>
#include <string>
#include <limits>
#include "employee.h"

Employee::Employee(){
    idNumber = 0;
     salary = 0;
    yearWorked = 0;
}

Employee::Employee(std::string new_name, int new_idNumber, std::string new_address, double new_salary, int new_yearWorked){
    name = new_name;
    idNumber = new_idNumber;
    address = new_address;
    salary = new_salary;
    yearWorked = new_yearWorked;

}

void Employee::output(std::ostream& out){
    if(&out == &std::cout){
        out << "Name: " << name << '\n';
        out << "ID number: " << idNumber << '\n';
        out << "Address: " << address << '\n';
        out << "Salary: " << salary << '\n';
        out << "Years worked at the company : " << yearWorked << '\n';
    }

    else{
        out << name << '\n';
        out << idNumber << '\n';
        out << address << '\n';
        out << salary << '\n';
        out << yearWorked << '\n';
    }
}

void Employee::input(std::istream& in){
    if(&in == &std::cin){
        if(in.peek() == '\n') in.ignore();
        std::cout << "Type Name: ";
        getline(in, name);

        std::cout << "Enter ID number: ";
        while (!(in >> idNumber)) {
            in.clear(); // Clear error state
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore wrong input
            std::cout << "Invalid input. Please enter a number for ID: ";
        }

        if(in.peek() == '\n') in.ignore();
        std::cout << "Enter Address: ";
        getline(in, address);

        std::cout << "Enter Salary: ";
        while (!(in >> salary)) {
            in.clear(); // Clear error state
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore wrong input
            std::cout << "Invalid input. Please enter a number for salary: ";
        }

        std::cout << "Enter the number of years the employee has worked: ";
        while (!(in >> yearWorked)) {
            in.clear(); // Clear error state
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore wrong input
            std::cout << "Invalid input. Please enter a number for years worked: ";
        }
    }
    else{
        if(in.peek() == '\n') in.ignore();
        getline(in, name);
        if (!(in >> idNumber)) in >> idNumber;
        if(in.peek() == '\n') in.ignore();
        getline(in, address);
        if (!(in >> salary)) in >> salary;
        if (!(in >> yearWorked)) in >> yearWorked;
    }
}

//To allow objects to be outputted to various output streams
std::ostream& operator <<(std::ostream& out, Employee& tmp){
    tmp.output(out);
    return out;
}

//To allow input to objects from various input streams
std::istream& operator >>(std::istream& in, Employee& tmp){
    tmp.input(in);
    return in;
}
