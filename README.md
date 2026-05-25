# Employee Data Management System

A C++ console application for managing employee records.

## Features

- Add employee records
- Search for employee records
- Display employee information
- Remove employee records
- Sort and organize employee data
- Save employee data using text files

## Technologies Used

- C++
- Object-Oriented Programming
- File Handling
- Console-based User Interface

## Project Structure

```text
employee-data-management-system-cpp/
├── main.cpp
├── database.cpp
├── database.h
├── employee.cpp
├── employee.h
├── README.md
└── .gitignore
```

## How to Run

Compile the project from the project root:

```bash
g++ -std=c++17 main.cpp database.cpp employee.cpp -o employee-management
```

Run the application:
```bash
./employee-management
```

On Windows, you can also run:
```bash
employee-management.exe
```

## Notes

When the program asks for a file name, enter a name without the `.txt` extension. The application will create or use a text file for storing employee data.

Generated `.txt` data files and compiled `.exe` files are not included in the repository.

## Author

Ahmad Assi