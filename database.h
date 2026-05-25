#ifndef DATABASE_H
#define DATABASE_H
#include "employee.h"
class Database{
    public:
        Database();
        ~Database();
        Database(const Database& other);
        void operator = (const Database& other);
        void search(std::string name);
        void search_id(int id);
        void add(const Employee& emp);
        void display_all();
        void remove(std::string name);
        void save(std::ostream& outs);
        void load(std::istream& ins);
        void sort_name();
        void sort_salary();

        bool is_empty() const {
        return used == 0;
    }

    private:
        void make_bigger();
        int capacity;
        Employee *data;
        int used;

};

#endif
