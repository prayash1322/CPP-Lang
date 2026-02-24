#include<iostream>
#include<string>
using namespace std;

class Person{
public:
    string name;
    int age;

    // Person(string name, int age){
    //     this->name = name;
    //     this->age = age;
    // }

    // ~Person(){
    //     cout << "Person Destructor Called" << endl;
    // }
};

class Student : public Person{
public:
    int rollno;

    // Student(string name, int age, int rollno) : Person(name,age){
    //     this->rollno = rollno;
    // }
    // ~Student(){
    //     cout << "Student Destructor Called" << endl;
    // }

    // void getInfo(){
    //     cout << "Name: " << name << endl;
    //     cout << "Age: " << age << endl;
    //     cout << "Roll Number: " << rollno << endl;
    // }
};

class GradStudent : public Student{
public:
    string ResearchArea;
};

int main(){
    GradStudent s1;
    s1.name = "Rajat";
    s1.ResearchArea = "Machine Learning";

    cout << "Name:- " << s1.name << endl << "Research Area:- " << s1.ResearchArea << endl;  
    return 0;
}