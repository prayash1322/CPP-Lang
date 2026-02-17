#include<iostream>

using namespace std;

int main(){
    int fir, sec;
    cout << "Enter the first number: ";
    cin >> fir;
    cout << "Enter the second number: ";
    cin >> sec;
    
    int count = 0;
    for(int i = fir; i <= sec; i++){
        if((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)){
            count++;
        }
    }
    
    int leapYears[count];
    int index = 0;
    for(int i = fir; i <= sec; i++){
        if((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)){
            leapYears[index++] = i;
        }
    }
    
    cout << "The array is: ";
    for(int i = 0; i < count; i++){
        cout << leapYears[i];
        cout << " ";
    }
    cout << endl;
    
    return 0;
}