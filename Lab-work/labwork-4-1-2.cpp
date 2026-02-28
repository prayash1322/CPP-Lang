#include<iostream>
using namespace std;

class P {
protected:
    float temperature;
public:
    void setTemperature(float temp) {
        temperature = temp;
    }
};

class Q : public P {
protected:
    float fahrenheit;
public:
    void toFahrenheit() {
        fahrenheit = (temperature * 9.0 / 5.0) + 32;
        cout << "Temperature in Fahrenheit: " << fahrenheit << endl;
    }
};

class R : public Q {
public:
    void toKelvin() {
        float kelvin = (fahrenheit - 32) * 5.0 / 9.0 + 273.15;
        cout << "Temperature in Kelvin: " << kelvin << endl;
    }
};

int main() {
    R obj;
    float celsius;
    cout << "Enter temperature in Celsius: ";
    cin >> celsius;
    obj.setTemperature(celsius);
    obj.toFahrenheit();
    obj.toKelvin();
    return 0;
}