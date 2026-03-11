#include<iostream>
#include<string>
using namespace std;

class laptop{
    private:
        string name;
        int price;
        string processor;
    public:

        laptop(string name, int price, string processor){
            cout<<"Parametrized constructor called"<<endl;
            this->name = name;
            this->price = price;
            this->processor = processor;
        }
    void displayspecs(){
            cout << "Laptop name is:- "<< name << endl;
            cout << "Laptop's Price is :- "<< price << endl;
            cout << "Processor of laptop is :- " << processor<< endl;
        }
    
};

int main(){
    laptop l1("lenevo LOQ", 80000, "i5 12th gen");
    l1.displayspecs();
    return 0;
}