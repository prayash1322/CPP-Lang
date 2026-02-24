#include<iostream>
#include<cstring>

using namespace std;

class DiamondCompany {
private:
    int comp_id;
    char comp_name[50];
    int comp_staff_quantity;
    double comp_revenue;
    int comp_import_raw_diamonds;
    int comp_export_diamonds;
    char comp_ceo[50];

public:
    DiamondCompany() {
        this->comp_id = 0;
    }

    DiamondCompany(int id, char name[], int staff, double revenue, int import, int export_d, char ceo[]) {
        this->comp_id = id;
        strcpy(this->comp_name, name);
        this->comp_staff_quantity = staff;
        this->comp_revenue = revenue;
        this->comp_import_raw_diamonds = import;
        this->comp_export_diamonds = export_d;
        strcpy(this->comp_ceo, ceo);
    }

    void display() {
        cout << "\nCompany ID: " << this->comp_id;
        cout << "\nCompany Name: " << this->comp_name;
        cout << "\nStaff Quantity: " << this->comp_staff_quantity;
        cout << "\nRevenue (per year): ₹" << this->comp_revenue;
        cout << "\nRaw Diamonds Imported: " << this->comp_import_raw_diamonds;
        cout << "\nDiamonds Exported: " << this->comp_export_diamonds;
        cout << "\nCEO: " << this->comp_ceo;
        cout << "\n----------------------------------------";
    }
};

int main() {
    int n;
    cout << "Enter number of diamond companies: ";
    cin >> n;

    DiamondCompany companies[n];

    for(int i = 0; i < n; i++) {
        int id, staff, import, export_d;
        double revenue;
        char name[50], ceo[50];

        cout << "\n--- Enter details for Company " << i + 1 << " ---\n";
        cout << "Company ID: ";
        cin >> id;
        cin.ignore();
        cout << "Company Name: ";
        cin.getline(name, 50);
        cout << "Staff Quantity: ";
        cin >> staff;
        cout << "Revenue (per year): ";
        cin >> revenue;
        cout << "Raw Diamonds Imported (per year): ";
        cin >> import;
        cout << "Diamonds Exported (per year): ";
        cin >> export_d;
        cin.ignore();
        cout << "CEO Name: ";
        cin.getline(ceo, 50);

        companies[i] = DiamondCompany(id, name, staff, revenue, import, export_d, ceo);
    }

    cout << "\n****** DIAMOND COMPANY RECORDS ******";
    for(int i = 0; i < n; i++) {
        companies[i].display();
    }

    return 0;
}