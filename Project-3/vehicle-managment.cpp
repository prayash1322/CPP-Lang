#include<iostream>
#include<string>

using namespace std;

class Vehicle {
protected:
    int vehicleID;
    string manufacturer;
    string model;
    int year;
    static int totalVehicles;

public:
    Vehicle() {
        vehicleID = 0;
        manufacturer = "";
        model = "";
        year = 0;
    }

    Vehicle(int id, string mfr, string mdl, int yr) {
        vehicleID = id;
        manufacturer = mfr;
        model = mdl;
        year = yr;
        totalVehicles++;
    }

    virtual ~Vehicle() {}

    void setVehicleID(int id) { vehicleID = id; }
    void setManufacturer(string mfr) { manufacturer = mfr; }
    void setModel(string mdl) { model = mdl; }
    void setYear(int yr) { year = yr; }

    int getVehicleID() { return vehicleID; }
    string getManufacturer() { return manufacturer; }
    string getModel() { return model; }
    int getYear() { return year; }

    static int getTotalVehicles() { return totalVehicles; }

    virtual void display() {
        cout << "Vehicle ID: " << vehicleID << endl;
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

int Vehicle::totalVehicles = 0;

class Car : public Vehicle {
protected:
    string fuelType;

public:
    Car() : Vehicle() {
        fuelType = "";
    }

    Car(int id, string mfr, string mdl, int yr, string fuel) : Vehicle(id, mfr, mdl, yr) {
        fuelType = fuel;
    }

    void setFuelType(string fuel) { fuelType = fuel; }
    string getFuelType() { return fuelType; }

    void display() {
        Vehicle::display();
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class ElectricCar : public Car {
protected:
    int batteryCapacity;

public:
    ElectricCar() : Car() {
        batteryCapacity = 0;
    }

    ElectricCar(int id, string mfr, string mdl, int yr, string fuel, int battery) : Car(id, mfr, mdl, yr, fuel) {
        batteryCapacity = battery;
    }

    void setBatteryCapacity(int battery) { batteryCapacity = battery; }
    int getBatteryCapacity() { return batteryCapacity; }

    void display() {
        Car::display();
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
    }
};

class Aircraft {
protected:
    int flightRange;

public:
    Aircraft() {
        flightRange = 0;
    }

    Aircraft(int range) {
        flightRange = range;
    }

    void setFlightRange(int range) { flightRange = range; }
    int getFlightRange() { return flightRange; }
};

class FlyingCar : public Car, public Aircraft {
public:
    FlyingCar() : Car(), Aircraft() {}

    FlyingCar(int id, string mfr, string mdl, int yr, string fuel, int range) : Car(id, mfr, mdl, yr, fuel), Aircraft(range) {}

    void display() {
        Car::display();
        cout << "Flight Range: " << flightRange << " km" << endl;
    }
};

class SportsCar : public ElectricCar {
protected:
    int topSpeed;

public:
    SportsCar() : ElectricCar() {
        topSpeed = 0;
    }

    SportsCar(int id, string mfr, string mdl, int yr, string fuel, int battery, int speed) : ElectricCar(id, mfr, mdl, yr, fuel, battery) {
        topSpeed = speed;
    }

    void setTopSpeed(int speed) { topSpeed = speed; }
    int getTopSpeed() { return topSpeed; }

    void display() {
        ElectricCar::display();
        cout << "Top Speed: " << topSpeed << " km/h" << endl;
    }
};

class Sedan : public Car {
public:
    Sedan() : Car() {}

    Sedan(int id, string mfr, string mdl, int yr, string fuel) : Car(id, mfr, mdl, yr, fuel) {}

    void display() {
        cout << "Type: Sedan" << endl;
        Car::display();
    }
};

class SUV : public Car {
public:
    SUV() : Car() {}

    SUV(int id, string mfr, string mdl, int yr, string fuel) : Car(id, mfr, mdl, yr, fuel) {}

    void display() {
        cout << "Type: SUV" << endl;
        Car::display();
    }
};

class VehicleRegistry {
private:
    Vehicle* vehicles[100];
    int count;

public:
    VehicleRegistry() {
        count = 0;
    }

    void addVehicle(Vehicle* v) {
        if (count < 100) {
            vehicles[count++] = v;
            cout << "Vehicle added successfully!" << endl;
        } else {
            cout << "Registry is full!" << endl;
        }
    }

    void displayAll() {
        if (count == 0) {
            cout << "No vehicles in registry." << endl;
            return;
        }
        cout << "\n===== ALL VEHICLES =====" << endl;
        for (int i = 0; i < count; i++) {
            cout << "\n--- Vehicle " << i + 1 << " ---" << endl;
            vehicles[i]->display();
        }
    }

    void searchById(int id) {
        for (int i = 0; i < count; i++) {
            if (vehicles[i]->getVehicleID() == id) {
                cout << "\n===== VEHICLE FOUND =====" << endl;
                vehicles[i]->display();
                return;
            }
        }
        cout << "Vehicle not found!" << endl;
    }
};

int main() {
    VehicleRegistry registry;
    int choice;

    while (true) {
        cout << "\n===== VEHICLE REGISTRY SYSTEM =====" << endl;
        cout << "1. Add Car" << endl;
        cout << "2. Add Electric Car" << endl;
        cout << "3. Add Flying Car" << endl;
        cout << "4. Add Sports Car" << endl;
        cout << "5. Add Sedan" << endl;
        cout << "6. Add SUV" << endl;
        cout << "7. View All Vehicles" << endl;
        cout << "8. Search by ID" << endl;
        cout << "9. Show Total Vehicles" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 10) {
            cout << "Exiting..." << endl;
            break;
        }

        if (choice >= 1 && choice <= 6) {
            int id, year;
            string mfr, mdl, fuel;

            cout << "Enter Vehicle ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Manufacturer: ";
            getline(cin, mfr);
            cout << "Enter Model: ";
            getline(cin, mdl);
            cout << "Enter Year: ";
            cin >> year;
            cin.ignore();

            if (choice == 1 || choice == 3 || choice == 5 || choice == 6) {
                cout << "Enter Fuel Type: ";
                getline(cin, fuel);
            }

            if (choice == 1) {
                registry.addVehicle(new Car(id, mfr, mdl, year, fuel));
            } else if (choice == 2) {
                int battery;
                cout << "Enter Battery Capacity (kWh): ";
                cin >> battery;
                registry.addVehicle(new ElectricCar(id, mfr, mdl, year, "Electric", battery));
            } else if (choice == 3) {
                int range;
                cout << "Enter Flight Range (km): ";
                cin >> range;
                registry.addVehicle(new FlyingCar(id, mfr, mdl, year, fuel, range));
            } else if (choice == 4) {
                int battery, speed;
                cout << "Enter Battery Capacity (kWh): ";
                cin >> battery;
                cout << "Enter Top Speed (km/h): ";
                cin >> speed;
                registry.addVehicle(new SportsCar(id, mfr, mdl, year, "Electric", battery, speed));
            } else if (choice == 5) {
                registry.addVehicle(new Sedan(id, mfr, mdl, year, fuel));
            } else if (choice == 6) {
                registry.addVehicle(new SUV(id, mfr, mdl, year, fuel));
            }
        } else if (choice == 7) {
            registry.displayAll();
        } else if (choice == 8) {
            int id;
            cout << "Enter Vehicle ID to search: ";
            cin >> id;
            registry.searchById(id);
        } else if (choice == 9) {
            cout << "Total Vehicles: " << Vehicle::getTotalVehicles() << endl;
        } else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}