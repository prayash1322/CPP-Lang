#include<iostream>
#include<cstring>

using namespace std;

class Customer {
private:
    int cust_id;
    char cust_name[50];
    int cust_age;
    char cust_city[30];
    char cust_mobile_number[15];
    int cust_simcard_validity;
    char cust_telecom_brand_name[20];

public:
    void setData(int id, char name[], int age, char city[], char mobile[], int validity, char brand[]) {
        this->cust_id = id;
        strcpy(this->cust_name, name);
        this->cust_age = age;
        strcpy(this->cust_city, city);
        strcpy(this->cust_mobile_number, mobile);
        this->cust_simcard_validity = validity;
        strcpy(this->cust_telecom_brand_name, brand);
    }

    void getData() {
        cout << "\nCustomer ID: " << this->cust_id;
        cout << "\nName: " << this->cust_name;
        cout << "\nAge: " << this->cust_age;
        cout << "\nCity: " << this->cust_city;
        cout << "\nMobile Number: " << this->cust_mobile_number;
        cout << "\nSIM Validity: " << this->cust_simcard_validity << " years";
        cout << "\nTelecom Brand: " << this->cust_telecom_brand_name;
        cout << "\n----------------------------------------";
    }
};

int main() {
    Customer customers[5];

    customers[0].setData(201, (char*)"Rajesh Kumar", 28, (char*)"Mumbai", (char*)"9876543210", 2, (char*)"Jio");
    customers[1].setData(202, (char*)"Rucha Desai", 35, (char*)"Delhi", (char*)"9123456789", 1, (char*)"Airtel");
    customers[2].setData(203, (char*)"Vikram Singh", 42, (char*)"Bangalore", (char*)"9988776655", 3, (char*)"Vi");
    customers[3].setData(204, (char*)"Meera Iyer", 30, (char*)"Chennai", (char*)"9876512345", 2, (char*)"BSNL");
    customers[4].setData(205, (char*)"Karan Mehta", 25, (char*)"Pune", (char*)"9765432108", 1, (char*)"Airtel");

    cout << "****** CUSTOMER RECORD SYSTEM ******\n";
    for(int i = 0; i < 5; i++) {
        customers[i].getData();
    }

    return 0;
}