#include<iostream>
#include<string>
using namespace std;

class Print{
public:
    void show(int x){
        cout << "integer: "<< x << endl;
    }
    
    void show(char ch){
        cout << "character: "<< ch << endl;
    }
};

int main(){
    Print p1;
    p1.show('A');

    return 0;
}