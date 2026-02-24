#include<iostream>
#include<cstring>

using namespace std;

class Hotel {
private:
    int hotel_id;
    char hotel_name[50];
    char hotel_type[20];
    char hotel_rating[10];
    char hotel_location[30];
    int hotel_establish_year;
    int hotel_staff_quantity;
    int hotel_room_quantity;
    static int total_hotels;

public:
    void setData(int id, char name[], char type[], char rating[], char location[], int year, int staff, int rooms) {
        this->hotel_id = id;
        strcpy(this->hotel_name, name);
        strcpy(this->hotel_type, type);
        strcpy(this->hotel_rating, rating);
        strcpy(this->hotel_location, location);
        this->hotel_establish_year = year;
        this->hotel_staff_quantity = staff;
        this->hotel_room_quantity = rooms;
        total_hotels++;
    }

    void getData() {
        cout << "\nHotel ID: " << this->hotel_id;
        cout << "\nName: " << this->hotel_name;
        cout << "\nType: " << this->hotel_type;
        cout << "\nRating: " << this->hotel_rating;
        cout << "\nLocation: " << this->hotel_location;
        cout << "\nEstablished Year: " << this->hotel_establish_year;
        cout << "\nStaff Quantity: " << this->hotel_staff_quantity;
        cout << "\nRoom Quantity: " << this->hotel_room_quantity;
        cout << "\n----------------------------------------";
    }

    static void displayTotalHotels() {
        cout << "\nTotal Hotels: " << total_hotels << "\n";
    }
};

int Hotel::total_hotels = 0;

int main() {
    int n;
    cout << "Enter number of hotels: ";
    cin >> n;

    Hotel *hotels = new Hotel[n];

    for(int i = 0; i < n; i++) {
        int id, year, staff, rooms;
        char name[50], type[20], rating[10], location[30];

        cout << "\n--- Enter details for Hotel " << i + 1 << " ---\n";
        cout << "Hotel ID: ";
        cin >> id;
        cin.ignore();
        cout << "Hotel Name: ";
        cin.getline(name, 50);
        cout << "Hotel Type (hotel/motel): ";
        cin.getline(type, 20);
        cout << "Hotel Rating (e.g., 5 Star): ";
        cin.getline(rating, 10);
        cout << "Hotel Location: ";
        cin.getline(location, 30);
        cout << "Established Year: ";
        cin >> year;
        cout << "Staff Quantity: ";
        cin >> staff;
        cout << "Room Quantity: ";
        cin >> rooms;

        hotels[i].setData(id, name, type, rating, location, year, staff, rooms);
    }

    cout << "\n****** HOTEL RECORD SYSTEM ******";
    for(int i = 0; i < n; i++) {
        hotels[i].getData();
    }

    Hotel::displayTotalHotels();

    delete[] hotels;
    return 0;
}