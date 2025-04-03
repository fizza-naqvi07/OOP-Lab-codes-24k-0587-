#include<iostream>
using namespace std;

class Shape {
    float area;
public:
    Shape(float a) : area(a) {}

    float Area() { return area; }

    Shape operator+(const Shape& s) {
        return Shape(this->area + s.area);
    }

    void display() {
        cout << "Area: " << area << endl;
    }
};

int main() {
    Shape shape1(10.5), shape2(20.3);
    Shape shape3 = shape1 + shape2;
    shape3.display();
    return 0;
}
