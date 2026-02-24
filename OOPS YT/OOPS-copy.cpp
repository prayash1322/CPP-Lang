#include<iostream>
#include<string>
using namespace std;

class Student{
public:
        //properties
        string name;
        double* cgpaPtr;
        
        Student(string name,double cgpa){
            this->name = name;
            cgpaPtr = new double;
            *cgpaPtr = cgpa;
        }

        Student(Student &obj){
            this->name = obj.name;
            cgpaPtr = new double;
            *cgpaPtr = *obj.cgpaPtr;
        }

        void getInfo(){
            cout << "Name:- "<< name << endl;
            cout << "CGPA:-" << *cgpaPtr << endl;
        }
};

int main(){
    Student s1("Aman", 8.9);
    s1.getInfo();

    Student s2(s1);
    *(s2.cgpaPtr) = 9.2;
    s2.name = "neha";

    s2.getInfo(); 
    return 0;   
}