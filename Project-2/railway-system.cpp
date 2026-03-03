#include <iostream>
#include <cstring>

using namespace std;

class Train
{
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];
    static int trainCount;

public:
    Train()
    {
        trainNumber = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");
    }

    Train(int num, char *name, char *src, char *dest, char *time)
    {
        trainNumber = num;
        strcpy(trainName, name);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, time);
    }

    ~Train()
    {

    }

    void setTrainNumber(int num) { trainNumber = num; }
    void setTrainName(char *name) { strcpy(trainName, name); }
    void setSource(char *src) { strcpy(source, src); }
    void setDestination(char *dest) { strcpy(destination, dest); }
    void setTrainTime(char *time) { strcpy(trainTime, time); }

    int getTrainNumber() { 
        return trainNumber; 
    }
    char *getTrainName() { 
        return trainName; 
    }
    char *getSource() { 
        return source; 
    }
    char *getDestination() { 
        return destination; 
    }
    char *getTrainTime() { 
        return trainTime; 
    }

    static int getTrainCount() { 
        return trainCount; 
    }

    void inputTrainDetails()
    {
        cout << "Enter Train Number: ";
        while (!(cin >> trainNumber))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter a valid number: ";
        }
        cin.ignore();
        cout << "Enter Train Name: ";
        cin.getline(trainName, 50);
        cout << "Enter Source: ";
        cin.getline(source, 50);
        cout << "Enter Destination: ";
        cin.getline(destination, 50);
        cout << "Enter Train Time: ";
        cin.getline(trainTime, 10);
    }

    void displayTrainDetails()
    {
        cout << "Train Number: " << trainNumber << endl;
        cout << "Train Name: " << trainName << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Train Time: " << trainTime << endl;
        cout << endl;
    }
};

int Train::trainCount = 0;

class RailwaySystem
{
private:
    Train trains[100];
    int totalTrains;

public:
    RailwaySystem() : totalTrains(0) {}

    void addTrain()
    {
        if (totalTrains < 100)
        {
            trains[totalTrains].inputTrainDetails();
            totalTrains++;
            cout << "Your train data is added successfully thank you!" << endl;
            cout << endl;
        }
        else
        {
            cout << "Cannot add more trains. Maximum limit reached!" << endl;
            cout << endl;
        }
    }

    void displayAllTrains()
    {
        if (totalTrains == 0)
        {
            cout << "No train records available!" << endl;
            cout << endl;
            return;
        }
        for (int i = 0; i < totalTrains; i++)
        {
            cout << "Train " << (i + 1) << " details:" << endl;
            trains[i].displayTrainDetails();
        }
    }

    void searchTrainByNumber(int number)
    {
        for (int i = 0; i < totalTrains; i++)
        {
            if (trains[i].getTrainNumber() == number)
            {
                cout << "Train found!" << endl;
                trains[i].displayTrainDetails();
                return;
            }
        }
        cout << "Train with number " << number << " not found!" << endl;
        cout << endl;
    }
};

int main()
{
    RailwaySystem system;
    int choice, trainNum;

    do
    {
        cout << "--- Railway Reservation System Menu ---" << endl;
        cout << "1. Add New Train Record" << endl;
        cout << "2. Display All Train Records" << endl;
        cout << "3. Search Train by Number" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            system.addTrain();
            break;
        case 2:
            system.displayAllTrains();
            break;
        case 3:
            cout << "Enter Train Number to search: ";
            cin >> trainNum;
            cout << endl;
            system.searchTrainByNumber(trainNum);
            break;
        case 4:
            cout << "Exiting the system. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
            cout << endl;
        }
    } while (choice != 4);

    return 0;
}