# Programming Assignment 2

## 1. Name and Description of the Project

This project implements a simple database system for managing students and courses in C++. The system allows users to:

- Add students and courses to the database
- Enroll students in courses and drop them from courses
- View student information and course rosters
- List all faculty (instructors) for a given student
- Remove courses from the database (automatically dropping all enrolled students)

The program uses object-oriented programming principles with separate `Student` and `Course` classes, each with their own member variables and functions. The system maintains consistency between student and course objects using pointers, ensuring that changes in one location are reflected across all references.

**Key Features:**
- Interactive menu-driven interface
- Support for up to 10 students and 10 courses
- Each student can enroll in up to 5 courses
- Course capacity management
- Bidirectional relationship management (students know their courses, courses know their students)

## 2. Identifying Information

- **Student Name**: Gabriel Giancarlo
- **Course**: CPSC 298 C++
- **Semester**: Fall 2025
- **Assignment**: Programming Assignment 2
- **Date**: October 2025

## 3. Source Files

The following source code files are included in this submission:

1. `main.cpp` - Main program with menu system and database management
2. `Student.h` - Header file for Student class definition
3. `Student.cpp` - Implementation file for Student class
4. `Course.h` - Header file for Course class definition
5. `Course.cpp` - Implementation file for Course class
6. `README.md` - This documentation file

## 4. References

- C++ Standard Library documentation for string handling and I/O operations
- Course materials (lecture slides and ZyBooks) for class design, pointers, and arrays
- C++ reference documentation for object-oriented programming concepts

**Note**: No external websites, AI tools, or peer collaboration were used in the development of this code beyond standard C++ documentation.

## 5. Known Errors

- **Compilation Warnings**: The program compiles with two minor warnings about unused parameters in the `removeCourse()` function. These parameters are included for consistency with the function signature pattern but are not strictly needed since the function retrieves enrolled students directly from the course object. The functionality is correct and the warnings do not affect program behavior.

- **Input Validation**: The program performs basic input validation (checking for existing students/courses, capacity limits, etc.), but does not validate all edge cases such as:
  - Non-numeric input for student IDs or course capacity (will cause program to fail)
  - Empty strings for names (will be accepted but may not be desired)
  - Negative capacity values (handled with error message)

- **Memory Management**: The program uses dynamic memory allocation (`new`) for Student and Course objects. Memory is properly deallocated in the main function's cleanup section, but if the program is terminated unexpectedly (e.g., via Ctrl+C), memory may not be freed.

## 6. Build Instructions

To compile the program, use the following command in a terminal:

```bash
g++ -std=c++11 -Wall -Wextra main.cpp Student.cpp Course.cpp -o database
```

**Requirements:**
- A C++ compiler that supports C++11 or later (g++, clang++, etc.)
- Standard C++ library with support for `<iostream>`, `<string>`, and `<limits>`

**Alternative compilation (if using separate object files):**
```bash
g++ -std=c++11 -c main.cpp -o main.o
g++ -std=c++11 -c Student.cpp -o Student.o
g++ -std=c++11 -c Course.cpp -o Course.o
g++ main.o Student.o Course.o -o database
```

**Note**: All source files must be in the same directory, or you must specify the correct paths to the header files.

## 7. Execution Instructions

### Running the Program:

```bash
./database
```

### Program Usage:

Upon execution, the program displays a menu with 9 options. The program will repeatedly prompt for menu choices until option 9 (Quit) is selected.

**Menu Options:**

1. **Add a Student**
   - Prompts for student name and ID
   - Creates a new student in the database
   - Example: Enter name "John Doe", ID "12345"

2. **Add a Course**
   - Prompts for course name, instructor name, and capacity
   - Creates a new course in the database
   - Example: Enter course "CPSC 298", instructor "Dr. Smith", capacity "30"

3. **Enroll a Student in a Course**
   - Prompts for student ID and course name
   - Enrolls the student if both exist and course has space
   - Updates both student and course objects
   - Example: Enter student ID "12345", course "CPSC 298"

4. **Drop a Student from a Course**
   - Prompts for student ID and course name
   - Removes the student from the course if enrolled
   - Updates both student and course objects
   - Example: Enter student ID "12345", course "CPSC 298"

5. **List All Faculty for Student**
   - Prompts for student ID
   - Displays all unique instructor names for courses the student is enrolled in
   - Example: Enter student ID "12345" → Shows "Dr. Smith", "Dr. Jones", etc.

6. **Remove a Course**
   - Prompts for course name
   - Removes the course from the database
   - Automatically drops all enrolled students from the course
   - Example: Enter course "CPSC 298"

7. **Print Student Information**
   - Prompts for student ID
   - Displays student name, ID, and list of enrolled courses
   - Example: Enter student ID "12345"

8. **Print Course Roster**
   - Prompts for course name
   - Displays course information and prints each enrolled student's information
   - Example: Enter course "CPSC 298"

9. **Quit**
   - Terminates the program and cleans up memory

### Example Session:

```
Welcome to the Student-Course Database System!

========================================
           DATABASE MENU
========================================
1. Add a Student
2. Add a Course
3. Enroll a Student in a Course
4. Drop a Student from a Course
5. List All Faculty for Student
6. Remove a Course
7. Print Student Information
8. Print Course Roster
9. Quit
========================================
Enter your choice: 1
Enter student name: Alice Johnson
Enter student ID: 1001
Student added successfully!

Enter your choice: 2
Enter course name: CPSC 298
Enter instructor name: Dr. Smith
Enter course capacity: 25
Course added successfully!

Enter your choice: 3
Enter student ID: 1001
Enter course name: CPSC 298
Student enrolled successfully!

Enter your choice: 7
Enter student ID: 1001
Student Name: Alice Johnson
Student ID: 1001
Number of Courses: 1
Enrolled Courses:
  - CPSC 298

Enter your choice: 9
Thank you for using the Student-Course Database System!
```

### Important Notes:

- Student IDs must be unique (duplicate IDs will be rejected)
- Course names must be unique (duplicate names will be rejected)
- Students cannot enroll in more than 5 courses
- Courses cannot exceed their capacity
- When removing a course, all enrolled students are automatically dropped
- The program maintains consistency between student and course objects using pointers

