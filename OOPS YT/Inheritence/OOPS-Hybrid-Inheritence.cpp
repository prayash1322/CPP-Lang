#include<iostream>
#include<string>
using namespace std;

class Person{
public: 
    string name;
    int age;
};

class Student : public Person{
public:
    int rollno;
};

class Teacher : public Person{
public:
    string subject;
};

class TA : public Student,public Teacher{

};

int main(){
    TA t1;
    t1.Student::name = "Rajat";
    t1.subject = "Computer Science";
    t1.rollno = 123;

    cout << "Name:- " << t1.Student::name << endl;
    cout << "Subject:- " << t1.subject << endl;
    return 0;
}