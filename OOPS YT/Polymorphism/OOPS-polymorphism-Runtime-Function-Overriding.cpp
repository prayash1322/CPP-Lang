#include<iostream>
#include<string>
using namespace std;

class Parent{
public:
    void getInfo() {
        cout << "Parent class" << endl;
    }

    virtual void hello(){
        cout << "Hello Parent" << endl;
    }
};

class Child : public Parent{
public:
    void getInfo() {     //Function Overriding
        cout << "Child class" << endl;
    }

    void hello(){
        cout << "Hello Child" << endl;
    }
};

int main(){
    Child c1;
    c1.hello();
    return 0;
}