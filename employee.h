#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee{
private:
    std::string name;
    int idNumber;
    std::string address;
    double salary;
    int yearWorked;

public:
    Employee();

    Employee(std::string new_name, int new_idNumber, std::string new_address, double new_salary, int new_yearWorked);
        std::string get_name()const{return name;}
        int get_idNumber()const{return idNumber;}
        std::string get_address()const{return address;}
        double get_salary()const{return salary;}
        int get_yearWorked()const{return yearWorked;}

        void output(std::ostream& out);
        void input(std::istream& in);

};
std::ostream& operator <<(std::ostream&, Employee& tmp);
std::istream& operator >>(std::istream&, Employee& tmp);

#endif
