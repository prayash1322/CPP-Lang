#include<iostream>
#include<string>
using namespace std;

class Op{
public:
    void Opa(int a){
        int b = 5;
        a = b;
        cout<<a<<endl;
    }
    void Opa(string a){
        string b = "hello i am string Operator Overloader";
        a = b;
        cout<<a<<endl;
    }
    // This is called Opearator overloading
};

int main(){
    Op o1;
    o1.Opa("prayash");
    return 0;
}