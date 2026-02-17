#include<iostream>

using namespace std;

int main(){
    int size;
    cout << "Enter array size: ";
    cin >> size;
    
    int arr[size];
    cout << "Enter array elements :" << endl;
    for(int i = 0; i < size; i++){
        cout << "Array of element [" << i << "] = ";
        cin >> arr[i];
    }
    
    cout << "\nOutput:" << endl;
    cout << "Even elements in Array: ";
    for(int i = 0; i < size; i++){
        if(arr[i] % 2 == 0){
            cout << arr[i];
            cout << " ";
        }
    }
    cout << endl;
    
    return 0;
}