#include<iostream>

using namespace std;

class X {
protected:
    int a, b, c;
};

class Y : public X {
public:
    void setData() {
        cout << "Enter three numbers: ";
        cin >> a >> b >> c;
    }

    void getData() {
        int cubeA = a * a * a;
        int cubeB = b * b * b;
        int cubeC = c * c * c;
        cout << "Cubes: " << cubeA << ", " << cubeB << ", " << cubeC << endl;
        cout << "Sum of cubes: " << (cubeA + cubeB + cubeC) << endl;
    }
};

int main() {
    Y obj;
    obj.setData();
    obj.getData();
    return 0;
}