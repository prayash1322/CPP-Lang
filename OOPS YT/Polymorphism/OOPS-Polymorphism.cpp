#include<iostream>
#include<string>
using namespace std;

class Student{
public:
    string name;
    int rollno;

    Student(){
        cout << "This is Non Parameterised Constructor" << endl;
    }

    Student(string name, int rollno){
        this->name = name;
        this->rollno = rollno;
        cout << "This is Parameterised Constructor" << endl;
    }
};

int main(){
    Student s1("Tony",1234);

    return 0;
}