#include<iostream>
#include<cstring>

using namespace std;

class FastFoodCafe {
private:
    int cafe_id;
    char cafe_name[50];
    char cafe_type[20];
    char cafe_rating[10];
    char cafe_location[30];
    int cafe_establish_year;
    int cafe_staff_quantity;

public:
    FastFoodCafe() {
        cout << "\n--- Enter Cafe Details ---\n";
        cout << "Cafe ID: ";
        cin >> this->cafe_id;
        cin.ignore();
        cout << "Cafe Name: ";
        cin.getline(this->cafe_name, 50);
        cout << "Cafe Type (rooftop/normal): ";
        cin.getline(this->cafe_type, 20);
        cout << "Cafe Rating (e.g., 5 Star): ";
        cin.getline(this->cafe_rating, 10);
        cout << "Cafe Location: ";
        cin.getline(this->cafe_location, 30);
        cout << "Established Year: ";
        cin >> this->cafe_establish_year;
        cout << "Staff Quantity: ";
        cin >> this->cafe_staff_quantity;
    }

    void display() {
        cout << "\nCafe ID: " << this->cafe_id;
        cout << "\nCafe Name: " << this->cafe_name;
        cout << "\nCafe Type: " << this->cafe_type;
        cout << "\nCafe Rating: " << this->cafe_rating;
        cout << "\nCafe Location: " << this->cafe_location;
        cout << "\nEstablished Year: " << this->cafe_establish_year;
        cout << "\nStaff Quantity: " << this->cafe_staff_quantity;
        cout << "\n----------------------------------------";
    }
};

int main() {
    int n;
    cout << "Enter number of fast food cafes: ";
    cin >> n;

    FastFoodCafe cafes[n];
    cout << "\n--- Thanks for providing the details ---";
    cout << "\n****** FAST FOOD CAFE RECORDS ******";
    for(int i = 0; i < n; i++) {
        cafes[i].display();
    }

    return 0;
}