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

class TA: public Teacher{

};

int main(){
    TA t1;
    t1.name = "Rajat";
    t1.subject = "Computer Science";

    cout << "Name:- " << t1.name << endl;
    cout << "Subject:- " << t1.subject << endl;
    return 0;
}