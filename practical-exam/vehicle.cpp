#include <iostream>
using namespace std;

class Vehicle
{
public:
    virtual void startEngine() = 0;
    virtual void drive() = 0;
};

class Car : public Vehicle
{
public:
    void startEngine()
    {
        cout << "Car engine started successfully" << endl;
    }

    void drive()
    {
        cout << "Car is driving VROOOMMM VROOOMMM!!!!" << endl;
    }
};

class Bike : public Vehicle
{
public:
    void startEngine()
    {
        cout << "Bike engine has been started successfully, yooohoooo!!!" << endl;
    }

    void drive()
    {
        cout << "Bike is driving...." << endl;
    }
};

int main()
{

    Car c;
    Bike b;

    Vehicle *vehicles[2];
    vehicles[0] = &c;
    vehicles[1] = &b;

    for (int i = 0; i < 2; i++)
    {
        cout << endl;
        vehicles[i]->startEngine();
        vehicles[i]->drive();
    }

    return 0;
}
