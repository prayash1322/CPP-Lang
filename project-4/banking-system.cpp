#include <iostream>
#include <string>

using namespace std;

class BankAccount {
protected:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount() : accountNumber(""), accountHolderName(""), balance(0) {}
    BankAccount(string accNum, string name, double bal) : accountNumber(accNum), accountHolderName(name), balance(bal) {}

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited: Rs." << amount << endl;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Successfully withdrawn Rs." << amount << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    double getBalance() { return balance; }

    virtual void displayAccountInfo() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: Rs." << balance << endl;
    }

    virtual void calculateInterest() {
        cout << "No interest for basic account" << endl;
    }

    string getAccountNumber() { return accountNumber; }
    virtual string getAccountType() { return "Basic Account"; }
    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount() : BankAccount(), interestRate(0) {}
    SavingsAccount(string accNum, string name, double bal, double rate)
        : BankAccount(accNum, name, bal), interestRate(rate) {}

    void calculateInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
        cout << "Interest calculated: Rs." << interest << endl;
        cout << "New balance: Rs." << balance << endl;
    }

    void displayAccountInfo() {
        cout << "=== Savings Account ===" << endl;
        BankAccount::displayAccountInfo();
        cout << "Interest Rate: " << interestRate << "%" << endl;
        cout << endl;
    }

    string getAccountType() { return "Savings Account"; }
};

class CurrentAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CurrentAccount() : BankAccount(), overdraftLimit(0) {}
    CurrentAccount(string accNum, string name, double bal, double limit)
        : BankAccount(accNum, name, bal), overdraftLimit(limit) {}

    void withdraw(double amount) {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
            cout << "Successfully withdrawn Rs." << amount << endl;
        } else {
            cout << "Exceeds overdraft limit!" << endl;
        }
    }

    void checkOverdraft() {
        if (balance < 0) {
            cout << "Account is overdrawn by: Rs." << -balance << endl;
        } else {
            cout << "Account is not overdrawn" << endl;
        }
    }

    void displayAccountInfo() {
        cout << "=== Current Account ===" << endl;
        BankAccount::displayAccountInfo();
        cout << "Overdraft Limit: Rs." << overdraftLimit << endl;
        cout << endl;
    }

    string getAccountType() { return "Current Account"; }
};

class FixedDepositAccount : public BankAccount {
private:
    int term;

public:
    FixedDepositAccount() : BankAccount(), term(0) {}
    FixedDepositAccount(string accNum, string name, double bal, int months)
        : BankAccount(accNum, name, bal), term(months) {}

    void withdraw(double amount) {
        cout << "Withdrawal not allowed from Fixed Deposit Account!" << endl;
    }

    void calculateInterest() {
        double rate = 7.5;
        double interest = balance * rate * term / (100 * 12);
        cout << "Fixed Deposit Interest for " << term << " months: Rs." << interest << endl;
        cout << "Maturity Amount: Rs." << balance + interest << endl;
    }

    void displayAccountInfo() {
        cout << "=== Fixed Deposit Account ===" << endl;
        BankAccount::displayAccountInfo();
        cout << "Term: " << term << " months" << endl;
        cout << endl;
    }

    string getAccountType() { return "Fixed Deposit Account"; }
};

int main() {
    BankAccount* accounts[10];
    int totalAccounts = 0;
    int choice;

    do {
        cout << "=== Banking System Menu ===" << endl;
        cout << "1. Create Savings Account" << endl;
        cout << "2. Create Current Account" << endl;
        cout << "3. Create Fixed Deposit Account" << endl;
        cout << "4. Display All Accounts" << endl;
        cout << "5. Deposit Money" << endl;
        cout << "6. Withdraw Money" << endl;
        cout << "7. Calculate Interest" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        if (choice >= 1 && choice <= 3) {
            if (totalAccounts >= 10) {
                cout << "Maximum accounts limit reached!" << endl;
                cout << endl;
                continue;
            }

            string accNum, name;
            double balance;

            cout << "Enter Account Number: ";
            cin >> accNum;
            cin.ignore();
            cout << "Enter Account Holder Name: ";
            getline(cin, name);
            cout << "Enter Initial Balance: Rs.";
            cin >> balance;

            if (choice == 1) {
                double rate;
                cout << "Enter Interest Rate (%): ";
                cin >> rate;
                accounts[totalAccounts] = new SavingsAccount(accNum, name, balance, rate);
            } else if (choice == 2) {
                double limit;
                cout << "Enter Overdraft Limit: Rs.";
                cin >> limit;
                accounts[totalAccounts] = new CurrentAccount(accNum, name, balance, limit);
            } else {
                int months;
                cout << "Enter Term (months): ";
                cin >> months;
                accounts[totalAccounts] = new FixedDepositAccount(accNum, name, balance, months);
            }
            totalAccounts++;
            cout << "Account created successfully!" << endl;
            cout << endl;
        }
        else if (choice == 4) {
            if (totalAccounts == 0) {
                cout << "No accounts found!" << endl;
                cout << endl;
            } else {
                for (int i = 0; i < totalAccounts; i++) {
                    cout << "Account " << i + 1 << ":" << endl;
                    accounts[i]->displayAccountInfo();
                }
            }
        }
        else if (choice == 5) {
            if (totalAccounts == 0) {
                cout << "No accounts available!" << endl;
                cout << endl;
            } else {
                cout << "Available Accounts:" << endl;
                for (int i = 0; i < totalAccounts; i++) {
                    cout << i + 1 << ". Account Number: " << accounts[i]->getAccountNumber() 
                         << " - " << accounts[i]->getAccountNumber() << endl;
                }
                int accIndex;
                double amount;
                cout << "Select Account (1-" << totalAccounts << "): ";
                cin >> accIndex;
                if (accIndex < 1 || accIndex > totalAccounts) {
                    cout << "Invalid account!" << endl;
                    cout << endl;
                } else {
                    cout << "Enter deposit amount: Rs.";
                    cin >> amount;
                    accounts[accIndex - 1]->deposit(amount);
                    cout << endl;
                }
            }
        }
        else if (choice == 6) {
            if (totalAccounts == 0) {
                cout << "No accounts available!" << endl;
                cout << endl;
            } else {
                cout << "Select Account Type:" << endl;
                cout << "1. Savings Account" << endl;
                cout << "2. Current Account" << endl;
                cout << "3. Fixed Deposit Account" << endl;
                cout << "Enter account type (1-3): ";
                int accType;
                cin >> accType;
                
                if (accType < 1 || accType > 3) {
                    cout << "Invalid account type!" << endl;
                    cout << endl;
                } else {
                    string targetType;
                    if (accType == 1) targetType = "Savings Account";
                    else if (accType == 2) targetType = "Current Account";
                    else targetType = "Fixed Deposit Account";
                    
                    string accNum;
                    int foundIndex = -1;
                    
                    while (foundIndex == -1) {
                        cout << "Enter Account Number: ";
                        cin >> accNum;
                        
                        for (int i = 0; i < totalAccounts; i++) {
                            if (accounts[i]->getAccountNumber() == accNum && accounts[i]->getAccountType() == targetType) {
                                foundIndex = i;
                                break;
                            }
                        }
                        
                        if (foundIndex == -1) {
                            cout << "Invalid account number or account type mismatch! Please try again." << endl;
                        }
                    }
                    
                    double amount;
                    cout << "Enter withdrawal amount: Rs.";
                    cin >> amount;
                    accounts[foundIndex]->withdraw(amount);
                    cout << endl;
                }
            }
        }
        else if (choice == 7) {
            if (totalAccounts == 0) {
                cout << "No accounts available!" << endl;
                cout << endl;
            } else {
                cout << "Available Accounts:" << endl;
                for (int i = 0; i < totalAccounts; i++) {
                    cout << i + 1 << ". Account Number: " << accounts[i]->getAccountNumber() 
                         << " - " << accounts[i]->getAccountNumber() << endl;
                }
                int accIndex;
                cout << "Select Account (1-" << totalAccounts << "): ";
                cin >> accIndex;
                if (accIndex < 1 || accIndex > totalAccounts) {
                    cout << "Invalid account!" << endl;
                    cout << endl;
                } else {
                    accounts[accIndex - 1]->calculateInterest();
                    cout << endl;
                }
            }
        }
        else if (choice == 8) {
            cout << "Thank you for using Banking System!" << endl;
        }
        else {
            cout << "Invalid choice!" << endl;
            cout << endl;
        }
    } while (choice != 8);

    for (int i = 0; i < totalAccounts; i++) {
        delete accounts[i];
    }

    return 0;
}