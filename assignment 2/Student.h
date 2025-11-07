#ifndef STUDENT_H
#define STUDENT_H

#include <string>

// Forward declaration
class Course;

/**
 * Student class represents a student in the database system.
 * Each student can enroll in up to 5 courses.
 */
class Student {
private:
    std::string m_name;           // Student's name
    int m_ID;                      // Student ID
    int m_numCourses;              // Number of courses currently enrolled
    Course* m_courses[5];          // Array of pointers to enrolled courses (max 5)

public:
    // Constructors
    Student();
    Student(const std::string& name, int id);
    
    // Destructor
    ~Student();
    
    // Getter functions
    std::string getName() const;
    int getID() const;
    Course** getCourses();         // Returns array of course pointers
    int getNumCourses() const;     // Helper function to get number of courses
    
    // Course management functions
    bool enroll(Course* course);   // Enroll in a course, returns true if successful
    bool drop(Course* course);     // Drop a course, returns true if successful
    
    // Display function
    void print() const;            // Print student information
};

#endif // STUDENT_H

