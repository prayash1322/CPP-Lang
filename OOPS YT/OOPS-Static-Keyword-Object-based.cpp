#include<iostream>
#include<string>
using namespace std;

class ABC {
public: 
    ABC(){
        cout<<"Constructor Called"<<endl;
    }

    ~ABC(){
        cout<<"Destructor Called"<<endl;
    }
};

int main(){
    // if(true){
    //     ABC obj; // Stack Object - Constructor & Destructor will be called first and then it will end the Main Function
    // }
    if(true){
        static ABC obj; // Heap Object - Constructor will be called and then it will end the main function but Destructor will be called becz it is an static object it will stay in the memory for lifetime of the program untill main function ends.
    }

    cout << "End of Main Function" << endl;
    return 0;
}