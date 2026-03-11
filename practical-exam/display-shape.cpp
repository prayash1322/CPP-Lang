#include<iostream>
#include<string>
using namespace std;

class Shape{
private:
    string color;
    float area;

public:
    void setColor(string c){
        color = c;
    }

    string getColor(){
        return color;
    }

    void setArea(float a){
        area = a;
    }

    float getArea(){
        return area;
    }

    virtual void displayDetails(){
        cout<<"Color: "<<color<<endl;
        cout<<"Area: "<<area<<endl;
    }
};

class Circle : public Shape{
private:
    float radius;

public:
    void setRadius(float r){
        radius = r;
    }

    void calculateArea(){
        float a = 3.14 * radius * radius;
        setArea(a);
    }

    void displayDetails(){
        cout<<"Shape: Circle"<<endl;
        cout<<"Color: "<<getColor()<<endl;
        cout<<"Radius: "<<radius<<endl;
        cout<<"Area: "<<getArea()<<endl;
    }
};

class Rectangle : public Shape{
private:
    float length, width;

public:
    void setLength(float l){
        length = l;
    }

    void setWidth(float w){
        width = w;
    }

    void calculateArea(){
        float a = length * width;
        setArea(a);
    }

    void displayDetails(){
        cout<<"Shape: Rectangle"<<endl;
        cout<<"Color: "<<getColor()<<endl;
        cout<<"Length: "<<length<<endl;
        cout<<"Width: "<<width<<endl;
        cout<<"Area: "<<getArea()<<endl;
    }
};

int main(){
    Circle c1;
    Rectangle r1;
    string color1;
    float radius, length, width;

    cout<<"Enter color of circle: ";
    cin>>color1;
    c1.setColor(color1);
    cout<<"Enter radius of circle: ";
    cin>>radius;
    c1.setRadius(radius);
    c1.calculateArea();

    cout<<"\nEnter color of rectangle: ";
    cin>>color1;
    r1.setColor(color1);
    cout<<"Enter length of rectangle: ";
    cin>>length;
    r1.setLength(length);
    cout<<"Enter width of rectangle: ";
    cin>>width;
    r1.setWidth(width);
    r1.calculateArea();

    Shape* shapes[2];
    shapes[0] = &c1;
    shapes[1] = &r1;

    cout<<"\nDisplaying details:"<<endl;
    for(int i=0; i<2; i++){
        cout<<endl;
        shapes[i]->displayDetails();
    }

    return 0;
}