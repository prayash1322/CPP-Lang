#include<iostream>
#include<string>
using namespace std;

class BankAccount{
    private:
    int accountNumber;
    int balance;
    string accountHolderName;

    public:
    void setBalance(int b){
        balance = b;
    }

    int getBalance(){
        return balance;
    }

    void setAccountNumber(int a){
        accountNumber = a;
    }
    
    int getAccountNumber(){
        return accountNumber;
    }
    
    void setAccountHolderName(string name){
        accountHolderName = name;
    }
    
    string getAccountHolderName(){
        return accountHolderName;
    }
    
    void showData(){
        cout<<"Account Number: "<<accountNumber<<endl;
        cout<<"Account Holder Name: "<<accountHolderName<<endl;
        cout<<"Balance: "<<balance<<endl;
    }

    void deposit(int amount){
        balance += amount;
    }

    void withdraw(int amount){
        if(balance >= amount){
            balance -= amount;
        }
        else{
            cout<<"Insufficient Balance"<<endl;
            exit(0);
        }
    }

};

int main(){
    BankAccount acc;
    int accNum, initialBalance, amount;
    string name;
    
    cout<<"Enter Account Number: ";
    cin>>accNum;
    acc.setAccountNumber(accNum);
    
    cout<<"Enter Account Holder Name: ";
    cin.ignore();
    getline(cin, name);
    acc.setAccountHolderName(name);
    
    cout<<"Enter Initial Balance: ";
    cin>>initialBalance;
    acc.setBalance(initialBalance);
    
    cout<<"\nInitial Account Details:"<<endl;
    acc.showData();
    
    cout<<"\nEnter amount to deposit: ";
    cin>>amount;
    acc.deposit(amount);
    acc.showData();
    
    cout<<"\nEnter amount to withdraw: ";
    cin>>amount;
    acc.withdraw(amount);

    acc.showData();
    
    return 0;
}