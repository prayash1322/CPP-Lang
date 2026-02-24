#include<iostream>
#include<string>
using namespace std;

// void func(){
//     static int x = 0; // initialisation statement will run only 1 time
//     cout << "x: " << x << endl;
//     x++;
// }

class A{
public:
    int x;

    void incX(){
        x = x + 1;
    }
};

int main(){
    A obj1;
    A obj2;
    obj1.x = 100;
    obj2.x = 200;
    obj1.incX();
    cout << obj1.x << endl;
    obj2.incX();
    cout << obj2.x << endl;
    return 0;
}