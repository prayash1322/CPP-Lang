#include<iostream>

using namespace std;

class TimeConverter {
public:
    void convertToTime(int totalSeconds) {
        int hours = totalSeconds / 3600;
        int minutes = (totalSeconds % 3600) / 60;
        int seconds = totalSeconds % 60;
        
        cout << "HH:MM:SS => " << hours << ":";
        
        if (minutes < 10) {
            cout << "0";
        }
        cout << minutes << ":";
        
        if (seconds < 10) {
            cout << "0";
        }
        cout << seconds << endl;
    }
    
    void convertToSeconds(int hours, int minutes, int seconds) {
        int totalSeconds = (hours * 3600) + (minutes * 60) + seconds;
        cout << "Total seconds: " << totalSeconds << endl;
    }
};

int main(){ 
    TimeConverter tc;
    int choice;
    
    cout << "1. Convert seconds to HH:MM:SS\n";
    cout << "2. Convert HH:MM:SS to seconds\n";
    cout << "Enter your choice: ";
    cin >> choice;
    
    switch(choice) {
        case 1: {
            int totalSeconds;
            cout << "Enter total seconds: ";
            cin >> totalSeconds;
            tc.convertToTime(totalSeconds);
            break;
        }
        case 2: {
            int hours, minutes, seconds;
            cout << "Enter hours: ";
            cin >> hours;
            cout << "Enter minutes: ";
            cin >> minutes;
            cout << "Enter seconds: ";
            cin >> seconds;
            tc.convertToSeconds(hours, minutes, seconds);
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
    }
    
    return 0;
}