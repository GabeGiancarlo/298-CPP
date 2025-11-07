#ifndef COURSE_H
#define COURSE_H

#include <string>

// Forward declaration
class Student;

/**
 * Course class represents a course in the database system.
 * Each course has a capacity limit for enrolled students.
 */
class Course {
private:
    std::string m_courseName;      // Name of the course
    std::string m_instructor;      // Instructor's name
    int m_capacity;                // Maximum number of students allowed
    int m_numStudents;             // Number of students currently enrolled
    Student* m_students[100];      // Array of pointers to enrolled students (assuming max 100)

public:
    // Constructors
    Course();
    Course(const std::string& courseName, const std::string& instructor, int capacity);
    
    // Destructor
    ~Course();
    
    // Getter functions
    std::string getName() const;
    std::string getInstructor() const;
    int getNumStudents() const;
    int getCapacity() const;       // Returns the course capacity
    Student** getStudents();       // Returns array of student pointers
    
    // Course management functions
    bool isAvailable() const;      // Returns true if course has space
    bool addStudent(Student* student); // Adds a student, returns true if successful
    
    // Student removal function (needed for dropping)
    bool removeStudent(Student* student); // Removes a student, returns true if successful
};

#endif // COURSE_H

