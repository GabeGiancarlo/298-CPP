#include "Course.h"
#include "Student.h"
#include <iostream>

/**
 * Default constructor - initializes course with empty values
 */
Course::Course() : m_courseName(""), m_instructor(""), m_capacity(0), m_numStudents(0) {
    // Initialize all student pointers to nullptr
    for (int i = 0; i < 100; i++) {
        m_students[i] = nullptr;
    }
}

/**
 * Parameterized constructor - creates a course with name, instructor, and capacity
 * @param courseName - Name of the course
 * @param instructor - Instructor's name
 * @param capacity - Maximum number of students allowed
 */
Course::Course(const std::string& courseName, const std::string& instructor, int capacity)
    : m_courseName(courseName), m_instructor(instructor), m_capacity(capacity), m_numStudents(0) {
    // Initialize all student pointers to nullptr
    for (int i = 0; i < 100; i++) {
        m_students[i] = nullptr;
    }
}

/**
 * Destructor - cleans up when course object is destroyed
 */
Course::~Course() {
    // No dynamic memory to clean up (using pointers to external objects)
}

/**
 * Getter function for course name
 * @return Course name
 */
std::string Course::getName() const {
    return m_courseName;
}

/**
 * Getter function for instructor name
 * @return Instructor's name
 */
std::string Course::getInstructor() const {
    return m_instructor;
}

/**
 * Getter function for number of enrolled students
 * @return Number of students currently enrolled
 */
int Course::getNumStudents() const {
    return m_numStudents;
}

/**
 * Getter function for course capacity
 * @return Maximum number of students allowed
 */
int Course::getCapacity() const {
    return m_capacity;
}

/**
 * Getter function for students array
 * @return Pointer to array of student pointers
 */
Student** Course::getStudents() {
    return m_students;
}

/**
 * Checks if the course has available space
 * @return true if course has space, false if at capacity
 */
bool Course::isAvailable() const {
    return m_numStudents < m_capacity;
}

/**
 * Adds a student to the course
 * @param student - Pointer to the student to add
 * @return true if student added successfully, false if course is full or student already enrolled
 */
bool Course::addStudent(Student* student) {
    // Check if course is at capacity
    if (!isAvailable()) {
        return false;
    }
    
    // Check if student is already enrolled
    for (int i = 0; i < m_numStudents; i++) {
        if (m_students[i] == student) {
            return false; // Already enrolled
        }
    }
    
    // Add student to array
    m_students[m_numStudents] = student;
    m_numStudents++;
    return true;
}

/**
 * Removes a student from the course
 * @param student - Pointer to the student to remove
 * @return true if student removed successfully, false if student not found
 */
bool Course::removeStudent(Student* student) {
    // Find the student in the array
    int index = -1;
    for (int i = 0; i < m_numStudents; i++) {
        if (m_students[i] == student) {
            index = i;
            break;
        }
    }
    
    // If student not found, return false
    if (index == -1) {
        return false;
    }
    
    // Shift remaining students to fill the gap
    for (int i = index; i < m_numStudents - 1; i++) {
        m_students[i] = m_students[i + 1];
    }
    
    // Clear the last slot and decrement count
    m_students[m_numStudents - 1] = nullptr;
    m_numStudents--;
    return true;
}

