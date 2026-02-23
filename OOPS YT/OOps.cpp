#include<iostream>

using namespace std;
class Student{
    public:
        int rollno;
        float percentage;
};
int main(){
    Student Prayash;
    Prayash.rollno = 12;
    Prayash.percentage = 98.21;
    cout << "This is the roll number of the student: " << Prayash.rollno << endl;
    cout << "This is the percentage of the student: " << Prayash.percentage << endl;
    return 0;
}