#include<iostream>
#include<string>
using namespace std;

class Student{
private:
    double fees;
    // Properties/Attributes
public:
    // Non-Parameterized Constructor
    // Student(){
    //     std = "12th";
    // }

    // Parameterized Constructor
    Student(string n, string st, string su, double fe){
        name = n;
        subject = su;
        std = st;

    }

    string name;
    string std;
    string subject;

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
    // s1.name = "PRAYASH";
    // s1.std = "12th";
    // s1.subject = "Business Studies";
    // s1.setFees(50000);

    // Printing the Output
    // cout << "Name of the student is :- " << s1.name << endl;
    // cout << "Fees of the student is :- " << s1.getFees() << endl;
    // cout << "Standard of the student is :- " << s1.std << endl;

    s1.displayInfo();
    return 0;   
}