#include<iostream>
#include<string>
using namespace std;

const int MAX_ITEMS = 100;

class LibraryItem {
private:
    string title;
    string author;
    string dueDate;
    
public:
    LibraryItem(string t = "", string a = "", string d = "") : title(t), author(a), dueDate(d) {}
    virtual ~LibraryItem() {}
    
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getDueDate() const { return dueDate; }
    
    void setTitle(string newTitle) { title = newTitle; }
    void setAuthor(string newAuthor) { author = newAuthor; }
    void setDueDate(string newDueDate) { dueDate = newDueDate; }
    
    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;
};

class Book : public LibraryItem {
private:
    string isbn;
    int quantity;
    bool checkedOut;
    
public:
    Book(string t, string a, string i, int q) : LibraryItem(t, a, ""), isbn(i), quantity(q), checkedOut(false) {
        if(q < 0) throw invalid_argument("Quantity cannot be negative");
        if(i.length() < 10) throw invalid_argument("Invalid ISBN format");
    }
    
    void checkOut() override {
        if(checkedOut) {
            cout << "Book is already checked out.\n";
        } else if(quantity <= 0) {
            cout << "Book is not available.\n";
        } else {
            checkedOut = true;
            quantity--;
            cout << "Book checked out successfully.\n";
            cout << "Enter due date (DD/MM/YYYY): ";
            string date;
            cin >> date;
            setDueDate(date);
        }
    }
    
    void returnItem() override {
        if(!checkedOut) {
            cout << "Book was not checked out.\n";
        } else {
            checkedOut = false;
            quantity++;
            setDueDate("");
            cout << "Book returned successfully.\n";
        }
    }
    
    void displayDetails() override {
        cout << "\n--- Book Details ---\n";
        cout << "Title: " << getTitle() << "\n";
        cout << "Author: " << getAuthor() << "\n";
        cout << "ISBN: " << isbn << "\n";
        cout << "Quantity: " << quantity << "\n";
        cout << "Status: " << (checkedOut ? "Checked Out" : "Available") << "\n";
        if(checkedOut && !getDueDate().empty()) {
            cout << "Due Date: " << getDueDate() << "\n";
        }
    }
};

class DVD : public LibraryItem {
private:
    int duration;
    bool checkedOut;
    
public:
    DVD(string t, string a, int d) : LibraryItem(t, a, ""), duration(d), checkedOut(false) {
        if(d < 0) throw invalid_argument("Duration cannot be negative");
    }
    
    void checkOut() override {
        if(checkedOut) {
            cout << "DVD is already checked out.\n";
        } else {
            checkedOut = true;
            cout << "DVD checked out successfully.\n";
            cout << "Enter due date (DD/MM/YYYY): ";
            string date;
            cin >> date;
            setDueDate(date);
        }
    }
    
    void returnItem() override {
        if(!checkedOut) {
            cout << "DVD was not checked out.\n";
        } else {
            checkedOut = false;
            setDueDate("");
            cout << "DVD returned successfully.\n";
        }
    }
    
    void displayDetails() override {
        cout << "\n--- DVD Details ---\n";
        cout << "Title: " << getTitle() << "\n";
        cout << "Author/Director: " << getAuthor() << "\n";
        cout << "Duration: " << duration << " minutes\n";
        cout << "Status: " << (checkedOut ? "Checked Out" : "Available") << "\n";
        if(checkedOut && !getDueDate().empty()) {
            cout << "Due Date: " << getDueDate() << "\n";
        }
    }
};

class Magazine : public LibraryItem {
private:
    int issueNumber;
    bool checkedOut;
    
public:
    Magazine(string t, string a, int issue) : LibraryItem(t, a, ""), issueNumber(issue), checkedOut(false) {
        if(issue < 0) throw invalid_argument("Issue number cannot be negative");
    }
    
    void checkOut() override {
        if(checkedOut) {
            cout << "Magazine is already checked out.\n";
        } else {
            checkedOut = true;
            cout << "Magazine checked out successfully.\n";
            cout << "Enter due date (DD/MM/YYYY): ";
            string date;
            cin >> date;
            setDueDate(date);
        }
    }
    
    void returnItem() override {
        if(!checkedOut) {
            cout << "Magazine was not checked out.\n";
        } else {
            checkedOut = false;
            setDueDate("");
            cout << "Magazine returned successfully.\n";
        }
    }
    
    void displayDetails() override {
        cout << "\n--- Magazine Details ---\n";
        cout << "Title: " << getTitle() << "\n";
        cout << "Author: " << getAuthor() << "\n";
        cout << "Issue Number: " << issueNumber << "\n";
        cout << "Status: " << (checkedOut ? "Checked Out" : "Available") << "\n";
        if(checkedOut && !getDueDate().empty()) {
            cout << "Due Date: " << getDueDate() << "\n";
        }
    }
};

class LibraryManagementSystem {
private:
    LibraryItem* libraryItems[MAX_ITEMS];
    int itemCount;
    
public:
    LibraryManagementSystem() : itemCount(0) {
        for(int i = 0; i < MAX_ITEMS; i++) {
            libraryItems[i] = nullptr;
        }
    }
    
    ~LibraryManagementSystem() {
        for(int i = 0; i < itemCount; i++) {
            delete libraryItems[i];
        }
    }
    
    void addBook() {
        try {
            if(itemCount >= MAX_ITEMS) {
                cout << "Library is full!\n";
                return;
            }
            
            string title, author, isbn;
            int quantity;
            
            cin.ignore();
            cout << "Enter book title: ";
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter ISBN (min 10 chars): ";
            cin >> isbn;
            cout << "Enter quantity: ";
            cin >> quantity;
            
            libraryItems[itemCount++] = new Book(title, author, isbn, quantity);
            cout << "Book added successfully!\n";
        } catch(const exception& e) {
            cout << "Error: " << e.what() << "\n";
        }
    }
    
    void addDVD() {
        try {
            if(itemCount >= MAX_ITEMS) {
                cout << "Library is full!\n";
                return;
            }
            
            string title, director;
            int duration;
            
            cin.ignore();
            cout << "Enter DVD title: ";
            getline(cin, title);
            cout << "Enter director: ";
            getline(cin, director);
            cout << "Enter duration (minutes): ";
            cin >> duration;
            
            libraryItems[itemCount++] = new DVD(title, director, duration);
            cout << "DVD added successfully!\n";
        } catch(const exception& e) {
            cout << "Error: " << e.what() << "\n";
        }
    }
    
    void addMagazine() {
        try {
            if(itemCount >= MAX_ITEMS) {
                cout << "Library is full!\n";
                return;
            }
            
            string title, author;
            int issue;
            
            cin.ignore();
            cout << "Enter magazine title: ";
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter issue number: ";
            cin >> issue;
            
            libraryItems[itemCount++] = new Magazine(title, author, issue);
            cout << "Magazine added successfully!\n";
        } catch(const exception& e) {
            cout << "Error: " << e.what() << "\n";
        }
    }
    
    void searchItem() {
        if(itemCount == 0) {
            cout << "Library is empty!\n";
            return;
        }
        
        string searchTitle;
        cin.ignore();
        cout << "Enter title to search: ";
        getline(cin, searchTitle);
        
        bool found = false;
        for(int i = 0; i < itemCount; i++) {
            if(libraryItems[i]->getTitle().find(searchTitle) != string::npos) {
                libraryItems[i]->displayDetails();
                found = true;
            }
        }
        
        if(!found) {
            cout << "No items found with that title.\n";
        }
    }
    
    void checkOutItem() {
        if(itemCount == 0) {
            cout << "Library is empty!\n";
            return;
        }
        
        string title;
        cin.ignore();
        cout << "Enter title to check out: ";
        getline(cin, title);
        
        for(int i = 0; i < itemCount; i++) {
            if(libraryItems[i]->getTitle() == title) {
                libraryItems[i]->checkOut();
                return;
            }
        }
        
        cout << "Item not found.\n";
    }
    
    void returnItemMenu() {
        if(itemCount == 0) {
            cout << "Library is empty!\n";
            return;
        }
        
        string title;
        cin.ignore();
        cout << "Enter title to return: ";
        getline(cin, title);
        
        for(int i = 0; i < itemCount; i++) {
            if(libraryItems[i]->getTitle() == title) {
                libraryItems[i]->returnItem();
                return;
            }
        }
        
        cout << "Item not found.\n";
    }
    
    void displayAllItems() {
        if(itemCount == 0) {
            cout << "Library is empty!\n";
            return;
        }
        
        cout << "\n=== All Library Items ===\n";
        for(int i = 0; i < itemCount; i++) {
            libraryItems[i]->displayDetails();
        }
    }
};

int main() {
    LibraryManagementSystem lms;
    int choice;
    
    do {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. Add DVD\n";
        cout << "3. Add Magazine\n";
        cout << "4. Search Item\n";
        cout << "5. Check Out Item\n";
        cout << "6. Return Item\n";
        cout << "7. Display All Items\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        
        cin >> choice;
        
        if(cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        
        switch(choice) {
            case 1:
                lms.addBook();
                break;
            case 2:
                lms.addDVD();
                break;
            case 3:
                lms.addMagazine();
                break;
            case 4:
                lms.searchItem();
                break;
            case 5:
                lms.checkOutItem();
                break;
            case 6:
                lms.returnItemMenu();
                break;
            case 7:
                lms.displayAllItems();
                break;
            case 8:
                cout << "Thank you for using the Library Management System!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != 8);
    
    return 0;
}