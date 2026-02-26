#include<iostream>
#include<string>
#include<cstring>

using namespace std;

// Student class to store individual student information
class Student {
private:
    char* name;        // Using char* to demonstrate deep copy
    int rollNumber;
    float gpa;

public:
    // Default constructor - creates empty student
    Student() {
        name = nullptr;
        rollNumber = 0;
        gpa = 0.0;
    }
    
    // Parameterized constructor - creates student with given details
    Student(string studentName, int roll, float studentGPA) {
        rollNumber = roll;
        gpa = studentGPA;
        
        // Allocate memory for name and copy it
        name = new char[studentName.length() + 1];
        strcpy(name, studentName.c_str());
    }
    
    // Copy constructor - creates deep copy of another student
    Student(Student& other) {
        rollNumber = other.rollNumber;
        gpa = other.gpa;
        
        // Deep copy: allocate new memory for name
        if (other.name != nullptr) {
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        } else {
            name = nullptr;
        }
    }
    
    // Destructor - free allocated memory
    ~Student() {
        if (name != nullptr) {
            delete[] name;
        }
    }
    
    // Getter methods
    char* getName() {
        if (name != nullptr) {
            return name;
        } else {
            return nullptr;
        }
    }
    
    int getRollNumber() {
        return rollNumber;
    }
    
    float getGPA() {
        return gpa;
    }
};

// StudentRecordManager class to manage multiple students
class StudentRecordManager {
private:
    Student* students;    // Dynamic array to store students
    int capacity;         // Maximum capacity of array
    int count;            // Current number of students
    
    // Helper function to increase array size when full
    void resize() {
        capacity = capacity * 2;
        Student* temp = new Student[capacity];
        
        // Copy all students to new array
        for (int i = 0; i < count; i++) {
            temp[i] = students[i];
        }
        
        delete[] students;
        students = temp;
    }

public:
    // Constructor - initialize with empty array
    StudentRecordManager() {
        capacity = 5;
        count = 0;
        students = new Student[capacity];
    }
    
    // Destructor - free memory
    ~StudentRecordManager() {
        delete[] students;
    }
    
    // Add a new student (using reference to avoid copying)
    void addStudent(Student& student) {
        if (count == capacity) {
            resize();  // Increase size if array is full
        }
        students[count] = student;
        count++;
    }
    
    // Display all student records
    void displayAll() {
        cout << "\n=== All Student Records ===\n";
        for (int i = 0; i < count; i++) {
            cout << "Name: " << students[i].getName()
                 << ", Roll Number: " << students[i].getRollNumber()
                 << ", GPA: " << students[i].getGPA() << endl;
        }
    }
    
    // Search for a student by roll number
    Student* searchByRoll(int roll) {
        for (int i = 0; i < count; i++) {
            if (students[i].getRollNumber() == roll) {
                return &students[i];  // Return pointer to found student
            }
        }
        return nullptr;  // Return null if not found
    }
};

int main() {
    // Create a record manager
    StudentRecordManager manager;
    
    // Create some student objects
    Student s1("Rahul Sharma", 101, 3.8);
    Student s2("Priya Patel", 102, 3.5);
    Student s3("Arjun Kumar", 103, 3.9);
    
    // Add students to the manager
    cout << "Adding students...\n";
    manager.addStudent(s1);
    manager.addStudent(s2);
    manager.addStudent(s3);
    
    // Display all students
    manager.displayAll();
    
    // Search for a specific student
    cout << "\n=== Searching for Roll Number 102 ===\n";
    Student* found = manager.searchByRoll(102);
    if (found != nullptr) {
        cout << "Found Student: " << found->getName() 
             << ", GPA: " << found->getGPA() << endl;
    } else {
        cout << "Student not found.\n";
    }
    
    // Test copy constructor (deep copy)
    cout << "\n=== Testing Copy Constructor ===\n";
    Student s4 = s1;  // Copy constructor is called here
    cout << "Original student: " << s1.getName() << endl;
    cout << "Copied student: " << s4.getName() << endl;
    cout << "Both have different memory addresses (deep copy)\n";
    
    return 0;
}