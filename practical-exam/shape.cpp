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

    cout<<"\nCircle Details:"<<endl;
    cout<<"Color: "<<c1.getColor()<<endl;
    cout<<"Area: "<<c1.getArea()<<endl;

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

    cout<<"\nRectangle Details:"<<endl;
    cout<<"Color: "<<r1.getColor()<<endl;
    cout<<"Area: "<<r1.getArea()<<endl;

    return 0;
}
