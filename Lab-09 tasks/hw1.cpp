#include <iostream>
using namespace std;

class Shape
{
public:
    virtual double getArea() = 0;
};

class Rectangle : public Shape
{
private:
    double w, h;

public:
    Rectangle(double width, double height) : w(width), h(height) {}

    double getArea() override
    {
        return w * h;
    }
};

class Triangle : public Shape
{
private:
    double b, h;

public:
    Triangle(double base, double height) : b(base), h(height) {}

    double getArea() override
    {
        return 0.5 * b * h;
    }
};

int main()
{
    Rectangle r(10.0, 4.5);
    Triangle t(6.2, 7.0);

    cout << "Rectangle Area: " << r.getArea() << endl;
    cout << "Triangle Area: " << t.getArea() << endl;

    return 0;
}
