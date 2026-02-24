#include<iostream>
#include<string>
using namespace std;

class Student{
private:
    double fees;
    // Properties/Attributes
public:
    string name;
    string std;
    string subject;
    // Non-Parameterized Constructor
    // Student(){
    //     std = "12th";
    // }

    // Parameterized Constructor
    Student(string name, string std, string subject, double fees){
        this->name = name;
        this->subject = subject;
        this->std = std;
        this->fees = fees;
    }
    //There can be mutltiple constructer which is know as constructor overloading (this is the concept of Polymorphism)

    // copy constructor
    Student(Student &orgObj){ // pass by refrence
        cout << "I am Custom Copy constructor invoked" << endl;
        this->name = orgObj.name;
        this->std = orgObj.std;
        this->subject = orgObj.subject;
    }

    // Methods / member functions
    void changeStd(string newStd) {
        std = newStd;
    }

    // Setter
    void setFees(double fee){
        fees = fee;
    }

    // Getter
    double getFees(){
        return fees;
    }

    void displayInfo(){
        cout << "Name of the student is :- " << name << endl;
        cout << "Subject of the student is :- " << subject << endl;
        cout << "Standard of the student is :- " << std << endl;
    }
};


int main(){
    Student s1("prayash", "12th", "bsc-it", 90000); // Constructor has been called
    Student s2(s1); // custom copy constructor -invoked
    // s1.name = "PRAYASH";
    // s1.std = "12th";
    // s1.subject = "Business Studies";
    // s1.setFees(50000);
    
    // Printing the Output
    // cout << "Name of the student is :- " << s1.name << endl;
    // cout << "Fees of the student is :- " << s1.getFees() << endl;
    // cout << "Standard of the student is :- " << s1.std << endl;
    
    s1.displayInfo();
    cout << endl;
    s2.displayInfo();
    return 0;   
}