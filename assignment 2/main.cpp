#include <iostream>
#include <string>
#include <limits>
#include "Student.h"
#include "Course.h"

// Maximum number of students and courses in the database
const int MAX_STUDENTS = 10;
const int MAX_COURSES = 10;

// Function prototypes for menu options
void addStudent(Student* students[], int& numStudents);
void addCourse(Course* courses[], int& numCourses);
void enrollStudent(Student* students[], int numStudents, Course* courses[], int numCourses);
void dropStudent(Student* students[], int numStudents, Course* courses[], int numCourses);
void listFaculty(Student* students[], int numStudents);
void removeCourse(Student* students[], int numStudents, Course* courses[], int& numCourses);
void printStudentInfo(Student* students[], int numStudents);
void printCourseRoster(Course* courses[], int numCourses);

// Helper functions
Student* findStudentByID(Student* students[], int numStudents, int id);
Course* findCourseByName(Course* courses[], int numCourses, const std::string& name);
void printMenu();

/**
 * Main function - database system for managing students and courses
 */
int main() {
    // Database arrays - store pointers to Student and Course objects
    Student* students[MAX_STUDENTS];
    Course* courses[MAX_COURSES];
    
    // Track number of students and courses currently in database
    int numStudents = 0;
    int numCourses = 0;
    
    // Initialize arrays to nullptr
    for (int i = 0; i < MAX_STUDENTS; i++) {
        students[i] = nullptr;
    }
    for (int i = 0; i < MAX_COURSES; i++) {
        courses[i] = nullptr;
    }
    
    int choice;
    bool running = true;
    
    std::cout << "Welcome to the Student-Course Database System!" << std::endl;
    std::cout << std::endl;
    
    // Main program loop
    while (running) {
        printMenu();
        std::cout << "Enter your choice: ";
        
        // Handle invalid input for menu choice
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 9." << std::endl;
            std::cout << std::endl;
            continue;
        }
        
        // Clear input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (choice) {
            case 1:
                addStudent(students, numStudents);
                break;
            case 2:
                addCourse(courses, numCourses);
                break;
            case 3:
                enrollStudent(students, numStudents, courses, numCourses);
                break;
            case 4:
                dropStudent(students, numStudents, courses, numCourses);
                break;
            case 5:
                listFaculty(students, numStudents);
                break;
            case 6:
                removeCourse(students, numStudents, courses, numCourses);
                break;
            case 7:
                printStudentInfo(students, numStudents);
                break;
            case 8:
                printCourseRoster(courses, numCourses);
                break;
            case 9:
                running = false;
                std::cout << "Thank you for using the Student-Course Database System!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 9." << std::endl;
                break;
        }
        std::cout << std::endl;
    }
    
    // Clean up dynamically allocated memory
    for (int i = 0; i < numStudents; i++) {
        delete students[i];
    }
    for (int i = 0; i < numCourses; i++) {
        delete courses[i];
    }
    
    return 0;
}

/**
 * Prints the main menu
 */
void printMenu() {
    std::cout << "========================================" << std::endl;
    std::cout << "           DATABASE MENU" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "1. Add a Student" << std::endl;
    std::cout << "2. Add a Course" << std::endl;
    std::cout << "3. Enroll a Student in a Course" << std::endl;
    std::cout << "4. Drop a Student from a Course" << std::endl;
    std::cout << "5. List All Faculty for Student" << std::endl;
    std::cout << "6. Remove a Course" << std::endl;
    std::cout << "7. Print Student Information" << std::endl;
    std::cout << "8. Print Course Roster" << std::endl;
    std::cout << "9. Quit" << std::endl;
    std::cout << "========================================" << std::endl;
}

/**
 * Helper function to find a student by ID
 * @param students - Array of student pointers
 * @param numStudents - Number of students in array
 * @param id - Student ID to search for
 * @return Pointer to student if found, nullptr otherwise
 */
Student* findStudentByID(Student* students[], int numStudents, int id) {
    for (int i = 0; i < numStudents; i++) {
        if (students[i] != nullptr && students[i]->getID() == id) {
            return students[i];
        }
    }
    return nullptr;
}

/**
 * Helper function to find a course by name
 * @param courses - Array of course pointers
 * @param numCourses - Number of courses in array
 * @param name - Course name to search for
 * @return Pointer to course if found, nullptr otherwise
 */
Course* findCourseByName(Course* courses[], int numCourses, const std::string& name) {
    for (int i = 0; i < numCourses; i++) {
        if (courses[i] != nullptr && courses[i]->getName() == name) {
            return courses[i];
        }
    }
    return nullptr;
}

/**
 * Menu option 1: Add a new student to the database
 */
void addStudent(Student* students[], int& numStudents) {
    if (numStudents >= MAX_STUDENTS) {
        std::cout << "Error: Maximum number of students (" << MAX_STUDENTS << ") reached." << std::endl;
        return;
    }
    
    std::string name;
    int id;
    
    std::cout << "Enter student name: ";
    std::getline(std::cin, name);
    
    std::cout << "Enter student ID: ";
    if (!(std::cin >> id)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: Invalid input. Student ID must be a number." << std::endl;
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    // Check if student ID already exists
    if (findStudentByID(students, numStudents, id) != nullptr) {
        std::cout << "Error: Student with ID " << id << " already exists." << std::endl;
        return;
    }
    
    // Create new student and add to database
    students[numStudents] = new Student(name, id);
    numStudents++;
    
    std::cout << "Student added successfully!" << std::endl;
}

/**
 * Menu option 2: Add a new course to the database
 */
void addCourse(Course* courses[], int& numCourses) {
    if (numCourses >= MAX_COURSES) {
        std::cout << "Error: Maximum number of courses (" << MAX_COURSES << ") reached." << std::endl;
        return;
    }
    
    std::string courseName, instructor;
    int capacity;
    
    std::cout << "Enter course name: ";
    std::getline(std::cin, courseName);
    
    std::cout << "Enter instructor name: ";
    std::getline(std::cin, instructor);
    
    std::cout << "Enter course capacity: ";
    if (!(std::cin >> capacity)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: Invalid input. Capacity must be a number." << std::endl;
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    // Validate capacity
    if (capacity <= 0) {
        std::cout << "Error: Capacity must be a positive number." << std::endl;
        return;
    }
    
    // Check if course name already exists
    if (findCourseByName(courses, numCourses, courseName) != nullptr) {
        std::cout << "Error: Course with name \"" << courseName << "\" already exists." << std::endl;
        return;
    }
    
    // Create new course and add to database
    courses[numCourses] = new Course(courseName, instructor, capacity);
    numCourses++;
    
    std::cout << "Course added successfully!" << std::endl;
}

/**
 * Menu option 3: Enroll a student in a course
 */
void enrollStudent(Student* students[], int numStudents, Course* courses[], int numCourses) {
    int studentID;
    std::string courseName;
    
    std::cout << "Enter student ID: ";
    if (!(std::cin >> studentID)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: Invalid input. Student ID must be a number." << std::endl;
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    Student* student = findStudentByID(students, numStudents, studentID);
    if (student == nullptr) {
        std::cout << "Error: Student with ID " << studentID << " not found." << std::endl;
        return;
    }
    
    std::cout << "Enter course name: ";
    std::getline(std::cin, courseName);
    
    Course* course = findCourseByName(courses, numCourses, courseName);
    if (course == nullptr) {
        std::cout << "Error: Course \"" << courseName << "\" not found." << std::endl;
        return;
    }
    
    // Check preconditions before attempting enrollment
    if (!course->isAvailable()) {
        std::cout << "Error: Course is at capacity." << std::endl;
        return;
    }
    
    if (student->getNumCourses() >= 5) {
        std::cout << "Error: Student has reached maximum course limit (5)." << std::endl;
        return;
    }
    
    // Check if already enrolled
    Course** studentCourses = student->getCourses();
    for (int i = 0; i < student->getNumCourses(); i++) {
        if (studentCourses[i] == course) {
            std::cout << "Error: Student is already enrolled in this course." << std::endl;
            return;
        }
    }
    
    // Enroll student in course (update both objects)
    // Both operations should succeed since we've checked preconditions
    bool courseAdded = course->addStudent(student);
    bool studentEnrolled = student->enroll(course);
    
    if (courseAdded && studentEnrolled) {
        std::cout << "Student enrolled successfully!" << std::endl;
    } else {
        // Rollback if either operation failed (shouldn't happen with preconditions, but safety check)
        if (courseAdded) course->removeStudent(student);
        if (studentEnrolled) student->drop(course);
        std::cout << "Error: Enrollment failed. Please try again." << std::endl;
    }
}

/**
 * Menu option 4: Drop a student from a course
 */
void dropStudent(Student* students[], int numStudents, Course* courses[], int numCourses) {
    int studentID;
    std::string courseName;
    
    std::cout << "Enter student ID: ";
    if (!(std::cin >> studentID)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: Invalid input. Student ID must be a number." << std::endl;
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    Student* student = findStudentByID(students, numStudents, studentID);
    if (student == nullptr) {
        std::cout << "Error: Student with ID " << studentID << " not found." << std::endl;
        return;
    }
    
    std::cout << "Enter course name: ";
    std::getline(std::cin, courseName);
    
    Course* course = findCourseByName(courses, numCourses, courseName);
    if (course == nullptr) {
        std::cout << "Error: Course \"" << courseName << "\" not found." << std::endl;
        return;
    }
    
    // Check if student is enrolled before attempting to drop
    bool isEnrolled = false;
    Course** studentCourses = student->getCourses();
    for (int i = 0; i < student->getNumCourses(); i++) {
        if (studentCourses[i] == course) {
            isEnrolled = true;
            break;
        }
    }
    
    if (!isEnrolled) {
        std::cout << "Error: Student is not enrolled in this course." << std::endl;
        return;
    }
    
    // Drop student from course (update both objects)
    bool courseRemoved = course->removeStudent(student);
    bool studentDropped = student->drop(course);
    
    if (courseRemoved && studentDropped) {
        std::cout << "Student dropped successfully!" << std::endl;
    } else {
        // Rollback if partial failure
        if (courseRemoved && !studentDropped) course->addStudent(student);
        if (studentDropped && !courseRemoved) student->enroll(course);
        std::cout << "Error: Drop operation failed. Please try again." << std::endl;
    }
}

/**
 * Menu option 5: List all faculty (instructors) for a student
 */
void listFaculty(Student* students[], int numStudents) {
    int studentID;
    
    std::cout << "Enter student ID: ";
    if (!(std::cin >> studentID)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: Invalid input. Student ID must be a number." << std::endl;
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    Student* student = findStudentByID(students, numStudents, studentID);
    if (student == nullptr) {
        std::cout << "Error: Student with ID " << studentID << " not found." << std::endl;
        return;
    }
    
    Course** courses = student->getCourses();
    int numCourses = student->getNumCourses();
    
    if (numCourses == 0) {
        std::cout << "Student is not enrolled in any courses." << std::endl;
        return;
    }
    
    std::cout << "Faculty for Student ID " << studentID << " (" << student->getName() << "):" << std::endl;
    
    // Use a set-like approach to avoid duplicate instructor names
    std::string instructors[10];
    int numInstructors = 0;
    
    for (int i = 0; i < numCourses; i++) {
        if (courses[i] != nullptr) {
            std::string instructor = courses[i]->getInstructor();
            
            // Check if instructor already in list
            bool found = false;
            for (int j = 0; j < numInstructors; j++) {
                if (instructors[j] == instructor) {
                    found = true;
                    break;
                }
            }
            
            // Add instructor if not already in list
            if (!found && numInstructors < 10) {
                instructors[numInstructors] = instructor;
                numInstructors++;
            }
        }
    }
    
    // Print all unique instructors
    for (int i = 0; i < numInstructors; i++) {
        std::cout << "  - " << instructors[i] << std::endl;
    }
}

/**
 * Menu option 6: Remove a course from the database
 */
void removeCourse(Student* students[], int numStudents, Course* courses[], int& numCourses) {
    // Note: students and numStudents parameters are kept for consistency with function signature
    // but are not needed since we get enrolled students directly from the course object
    (void)students;      // Suppress unused parameter warning
    (void)numStudents;   // Suppress unused parameter warning
    std::string courseName;
    
    std::cout << "Enter course name: ";
    std::getline(std::cin, courseName);
    
    Course* course = findCourseByName(courses, numCourses, courseName);
    if (course == nullptr) {
        std::cout << "Error: Course \"" << courseName << "\" not found." << std::endl;
        return;
    }
    
    // Remove course from all enrolled students
    // Get a copy of the enrolled students list before modifying
    Student** enrolledStudents = course->getStudents();
    int numEnrolled = course->getNumStudents();
    
    // Create a temporary array to store student pointers (since the course array will be modified)
    Student* tempStudents[100];
    for (int i = 0; i < numEnrolled; i++) {
        tempStudents[i] = enrolledStudents[i];
    }
    
    // Drop the course from all enrolled students
    for (int i = 0; i < numEnrolled; i++) {
        if (tempStudents[i] != nullptr) {
            tempStudents[i]->drop(course);
        }
    }
    
    // Remove course from database array
    int index = -1;
    for (int i = 0; i < numCourses; i++) {
        if (courses[i] == course) {
            index = i;
            break;
        }
    }
    
    if (index != -1) {
        // Delete the course object
        delete courses[index];
        
        // Shift remaining courses to fill the gap
        for (int i = index; i < numCourses - 1; i++) {
            courses[i] = courses[i + 1];
        }
        courses[numCourses - 1] = nullptr;
        numCourses--;
        
        std::cout << "Course removed successfully!" << std::endl;
    }
}

/**
 * Menu option 7: Print student information
 */
void printStudentInfo(Student* students[], int numStudents) {
    int studentID;
    
    std::cout << "Enter student ID: ";
    if (!(std::cin >> studentID)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: Invalid input. Student ID must be a number." << std::endl;
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    Student* student = findStudentByID(students, numStudents, studentID);
    if (student == nullptr) {
        std::cout << "Error: Student with ID " << studentID << " not found." << std::endl;
        return;
    }
    
    student->print();
}

/**
 * Menu option 8: Print course roster
 */
void printCourseRoster(Course* courses[], int numCourses) {
    std::string courseName;
    
    std::cout << "Enter course name: ";
    std::getline(std::cin, courseName);
    
    Course* course = findCourseByName(courses, numCourses, courseName);
    if (course == nullptr) {
        std::cout << "Error: Course \"" << courseName << "\" not found." << std::endl;
        return;
    }
    
    Student** enrolledStudents = course->getStudents();
    int numEnrolled = course->getNumStudents();
    
    std::cout << "========================================" << std::endl;
    std::cout << "Course: " << course->getName() << std::endl;
    std::cout << "Instructor: " << course->getInstructor() << std::endl;
    std::cout << "Enrolled Students: " << numEnrolled << " / " << course->getCapacity() << std::endl;
    std::cout << "========================================" << std::endl;
    
    if (numEnrolled == 0) {
        std::cout << "No students enrolled in this course." << std::endl;
    } else {
        std::cout << "Roster:" << std::endl;
        for (int i = 0; i < numEnrolled; i++) {
            if (enrolledStudents[i] != nullptr) {
                enrolledStudents[i]->print();
            }
        }
    }
}

