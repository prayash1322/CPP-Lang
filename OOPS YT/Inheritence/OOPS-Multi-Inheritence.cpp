#include<iostream>
#include<string>
using namespace std;

class Student{
public:
    string name;
    int rollno;
};

class Teacher{
public:
    string subject;
    double salary;
};

class TA: public Student, public Teacher{

};

int main(){
    TA t1;
    t1.name = "Rajat";
    t1.subject = "Computer Science";
    t1.salary = 50000;

    cout << "Name:- " << t1.name << endl;
    cout << "Subject:- " << t1.subject << endl;
    cout << "Salary:- " << t1.salary << endl;
    return 0;
}