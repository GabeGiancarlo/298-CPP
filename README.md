# CPSC 298 C++ - Programming Assignments

This repository contains all programming assignments for CPSC 298 C++ (Fall 2025).

## Repository Structure

```
298-CPP/
├── assignment 1/          # Programming Assignment 1
│   ├── calculator.cpp    # Interactive calculator program
│   ├── verifier.cpp      # Exponent calculation verifier
│   └── README.md         # Assignment 1 documentation
├── assignment 2/          # Programming Assignment 2
│   ├── main.cpp          # Main database program
│   ├── Student.h/cpp     # Student class implementation
│   ├── Course.h/cpp      # Course class implementation
│   └── README.md         # Assignment 2 documentation
└── README.md             # This file
```

## Assignments

### Assignment 1: Basic C++ Programs
**Topics Covered:** Input/Output, Branching, Loops, Mathematical Operations

Two C++ programs demonstrating fundamental programming concepts:
- **verifier.cpp**: Compares `pow()` function vs loop-based exponent calculations
- **calculator.cpp**: Interactive calculator with basic arithmetic operations

[View Assignment 1 README](assignment%201/README.md)

### Assignment 2: Student-Course Database System
**Topics Covered:** Arrays, Pointers, Functions, Classes and Objects

A menu-driven database system for managing students and courses:
- Object-oriented design with `Student` and `Course` classes
- Pointer-based architecture for data consistency
- Comprehensive input validation and error handling
- Full CRUD operations for students and courses

[View Assignment 2 README](assignment%202/README.md)

## Building and Running

### Prerequisites
- C++ compiler supporting C++11 or later (g++, clang++, etc.)
- Standard C++ library

### Assignment 1
```bash
cd "assignment 1"
g++ calculator.cpp -o calculator
g++ verifier.cpp -o verifier
./calculator
./verifier
```

### Assignment 2
```bash
cd "assignment 2"
g++ -std=c++11 main.cpp Student.cpp Course.cpp -o database
./database
```

## Student Information

- **Name**: Gabriel Giancarlo
- **Course**: CPSC 298 C++
- **Semester**: Fall 2025
- **Institution**: [Your Institution]

## Repository Information

- **Repository**: [298-CPP](https://github.com/GabeGiancarlo/298-CPP)
- **Language**: C++
- **License**: Educational Use Only

## Notes

- Executable files are excluded from version control (see `.gitignore`)
- Each assignment includes its own detailed README with build and execution instructions
- Code follows C++ best practices and includes comprehensive comments

