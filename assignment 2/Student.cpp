#include "Student.h"
#include "Course.h"
#include <iostream>
#include <iomanip>

/**
 * Default constructor - initializes student with empty values
 */
Student::Student() : m_name(""), m_ID(0), m_numCourses(0) {
    // Initialize all course pointers to nullptr
    for (int i = 0; i < 5; i++) {
        m_courses[i] = nullptr;
    }
}

/**
 * Parameterized constructor - creates a student with name and ID
 * @param name - Student's name
 * @param id - Student ID
 */
Student::Student(const std::string& name, int id) 
    : m_name(name), m_ID(id), m_numCourses(0) {
    // Initialize all course pointers to nullptr
    for (int i = 0; i < 5; i++) {
        m_courses[i] = nullptr;
    }
}

/**
 * Destructor - cleans up when student object is destroyed
 */
Student::~Student() {
    // No dynamic memory to clean up (using pointers to external objects)
}

/**
 * Getter function for student name
 * @return Student's name
 */
std::string Student::getName() const {
    return m_name;
}

/**
 * Getter function for student ID
 * @return Student ID
 */
int Student::getID() const {
    return m_ID;
}

/**
 * Getter function for courses array
 * @return Pointer to array of course pointers
 */
Course** Student::getCourses() {
    return m_courses;
}

/**
 * Getter function for number of courses
 * @return Number of courses student is enrolled in
 */
int Student::getNumCourses() const {
    return m_numCourses;
}

/**
 * Enrolls the student in a course
 * @param course - Pointer to the course to enroll in
 * @return true if enrollment successful, false if already enrolled or at capacity
 */
bool Student::enroll(Course* course) {
    // Check if student is already enrolled in this course
    for (int i = 0; i < m_numCourses; i++) {
        if (m_courses[i] == course) {
            return false; // Already enrolled
        }
    }
    
    // Check if student has reached maximum course limit
    if (m_numCourses >= 5) {
        return false; // At capacity
    }
    
    // Add course to array
    m_courses[m_numCourses] = course;
    m_numCourses++;
    return true;
}

/**
 * Drops the student from a course
 * @param course - Pointer to the course to drop
 * @return true if drop successful, false if not enrolled
 */
bool Student::drop(Course* course) {
    // Find the course in the array
    int index = -1;
    for (int i = 0; i < m_numCourses; i++) {
        if (m_courses[i] == course) {
            index = i;
            break;
        }
    }
    
    // If course not found, return false
    if (index == -1) {
        return false;
    }
    
    // Shift remaining courses to fill the gap
    for (int i = index; i < m_numCourses - 1; i++) {
        m_courses[i] = m_courses[i + 1];
    }
    
    // Clear the last slot and decrement count
    m_courses[m_numCourses - 1] = nullptr;
    m_numCourses--;
    return true;
}

/**
 * Prints student information including name, ID, and enrolled courses
 */
void Student::print() const {
    std::cout << "Student Name: " << m_name << std::endl;
    std::cout << "Student ID: " << m_ID << std::endl;
    std::cout << "Number of Courses: " << m_numCourses << std::endl;
    
    if (m_numCourses > 0) {
        std::cout << "Enrolled Courses:" << std::endl;
        for (int i = 0; i < m_numCourses; i++) {
            if (m_courses[i] != nullptr) {
                std::cout << "  - " << m_courses[i]->getName() << std::endl;
            }
        }
    } else {
        std::cout << "No courses enrolled." << std::endl;
    }
    std::cout << std::endl;
}

