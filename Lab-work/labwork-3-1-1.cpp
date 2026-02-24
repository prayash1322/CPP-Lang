#include<iostream>
#include<cstring>

using namespace std;

class Student {
private:
    int stu_id;
    char stu_name[50];
    int stu_age;
    char stu_course[50];
    char stu_city[30];
    char stu_email[50];
    char stu_college[50];

public:
    void setData(int id, char name[], int age, char course[], char city[], char email[], char college[]) {
        stu_id = id;
        strcpy(stu_name, name);
        stu_age = age;
        strcpy(stu_course, course);
        strcpy(stu_city, city);
        strcpy(stu_email, email);
        strcpy(stu_college, college);
    }

    void getData() {
        cout << "\nStudent ID: " << stu_id;
        cout << "\nName: " << stu_name;
        cout << "\nAge: " << stu_age;
        cout << "\nCourse: " << stu_course;
        cout << "\nCity: " << stu_city;
        cout << "\nEmail: " << stu_email;
        cout << "\nCollege: " << stu_college;
        cout << "\n----------------------------------------";
    }
};

int main() {
    Student students[5];

    students[0].setData(101, (char*)"Rahul Sharma", 20, (char*)"Computer Science", (char*)"Mumbai", (char*)"rahul@email.com", (char*)"IIT Bombay");
    students[1].setData(102, (char*)"Priya Patel", 21, (char*)"Electrical Engineering", (char*)"Delhi", (char*)"priya@email.com", (char*)"IIT Delhi");
    students[2].setData(103, (char*)"Amit Kumar", 19, (char*)"Mechanical Engineering", (char*)"Bangalore", (char*)"amit@email.com", (char*)"IIT Madras");
    students[3].setData(104, (char*)"Sneha Reddy", 22, (char*)"Civil Engineering", (char*)"Hyderabad", (char*)"sneha@email.com", (char*)"NIT Warangal");
    students[4].setData(105, (char*)"Arjun Singh", 20, (char*)"Information Technology", (char*)"Pune", (char*)"arjun@email.com", (char*)"BITS Pilani");

    cout << "****** STUDENT RECORD SYSTEM ******\n";
    for(int i = 0; i < 5; i++) {
        students[i].getData();
    }

    return 0;
}