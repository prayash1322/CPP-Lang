#include<iostream>
#include<string>
#include<cstring>

using namespace std;

class Student {
private:
    char* name;
    int rollNumber;
    float gpa;

public:
    Student() {
        name = nullptr;
        rollNumber = 0;
        gpa = 0.0;
    }
    
    Student(string studentName, int roll, float studentGPA) {
        this->rollNumber = roll;
        this->gpa = studentGPA;
        this->name = new char[studentName.length() + 1];
        strcpy(this->name, studentName.c_str());
    }
    
    Student(Student& other) {
        this->rollNumber = other.rollNumber;
        this->gpa = other.gpa;
        if (other.name != nullptr) {
            this->name = new char[strlen(other.name) + 1];
            strcpy(this->name, other.name);
        } else {
            this->name = nullptr;
        }
    }
    
    ~Student() {
        if (this->name != nullptr) {
            delete[] this->name;
        }
    }
    
    char* getName() {
        if (this->name != nullptr) {
            return this->name;
        } else {
            return nullptr;
        }
    }
    
    int getRollNumber() {
        return this->rollNumber;
    }
    
    float getGPA() {
        return this->gpa;
    }
};

class StudentRecordManager {
private:
    Student* students;
    int capacity;
    int count;
    
    void resize() {
        capacity = capacity * 2;
        Student* temp = new Student[capacity];
        for (int i = 0; i < count; i++) {
            temp[i] = students[i];
        }
        delete[] students;
        students = temp;
    }

public:
    StudentRecordManager() {
        capacity = 5;
        count = 0;
        students = new Student[capacity];
    }
    
    ~StudentRecordManager() {
        delete[] students;
    }
    
    void addStudent(Student& student) {
        if (count == capacity) {
            resize();
        }
        students[count] = student;
        count++;
    }
    
    void displayAll() {
        cout << "\n=== All Student Records ===\n";
        for (int i = 0; i < count; i++) {
            cout << "Name: " << students[i].getName()
                 << ", Roll Number: " << students[i].getRollNumber()
                 << ", GPA: " << students[i].getGPA() << endl;
        }
    }
    
    Student* searchByRoll(int roll) {
        for (int i = 0; i < count; i++) {
            if (students[i].getRollNumber() == roll) {
                return &students[i];
            }
        }
        return nullptr;
    }
};

int main() {
    StudentRecordManager manager;
    
    Student s1("Rahul Sharma", 101, 3.8);
    Student s2("Priya Patel", 102, 3.5);
    Student s3("Arjun Kumar", 103, 3.9);
    
    cout << "Adding students...\n";
    manager.addStudent(s1);
    manager.addStudent(s2);
    manager.addStudent(s3);
    
    manager.displayAll();
    
    cout << "\n=== Searching for Roll Number 102 ===\n";
    Student* found = manager.searchByRoll(102);
    if (found != nullptr) {
        cout << "Found Student: " << found->getName() 
             << ", GPA: " << found->getGPA() << endl;
    } else {
        cout << "Student not found.\n";
    }
    
    cout << "\n=== Testing Copy Constructor ===\n";
    Student s4 = s1;
    cout << "Original student: " << s1.getName() << endl;
    cout << "Copied student: " << s4.getName() << endl;
    cout << "Both have different memory addresses (deep copy)\n";
    
    return 0;
}