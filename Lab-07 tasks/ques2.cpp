#include <iostream>
using namespace std;

class Shape
{
protected:
    int x, y;
    string color;
    double borderThickness;

public:
    Shape(int x, int y, string color, double borderThickness = 1.0)
        : x(x), y(y), color(color), borderThickness(borderThickness) {}

    virtual void draw() = 0;
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;
};

class Circle : public Shape
{
    double radius;

public:
    Circle(int x, int y, string color, double radius, double borderThickness = 1.0)
        : Shape(x, y, color, borderThickness), radius(radius) {}

    void draw() override
    {
        cout << "Drawing Circle at (" << x << ", " << y << ") with radius " << radius << " and color " << color << endl;
    }

    double calculateArea() override
    {
        return 3.142 * radius * radius;
    }

    double calculatePerimeter() override
    {
        return 2 * 3.142 * radius;
    }
};

class Rectangle : public Shape
{
    double width, height;

public:
    Rectangle(int x, int y, string color, double width, double height, double borderThickness = 1.0)
        : Shape(x, y, color, borderThickness), width(width), height(height) {}

    void draw() override
    {
        cout << "Drawing Rectangle at (" << x << ", " << y << ") with width " << width << " and height " << height << " and color " << color << endl;
    }

    double calculateArea() override
    {
        return width * height;
    }

    double calculatePerimeter() override
    {
        return 2 * (width + height);
    }
};

class Triangle : public Shape
{
    double side1, side2, side3;

public:
    Triangle(int x, int y, string color, double s1, double s2, double s3, double borderThickness = 1.0)
        : Shape(x, y, color, borderThickness), side1(s1), side2(s2), side3(s3) {}

    void draw() override
    {
        cout << "Drawing Triangle at (" << x << ", " << y << ") with sides " << side1 << ", " << side2 << ", " << side3 << " and color " << color << endl;
    }

    double calculateArea() override
    {
        double s = (side1 + side2 + side3) / 2;
        double approxSqrt = s * (s - side1) * (s - side2) * (s - side3);
        return (approxSqrt > 0) ? approxSqrt : 0;
    }

    double calculatePerimeter() override
    {
        return side1 + side2 + side3;
    }
};

int main()
{
    Circle c(3, 5, "golden", 7);
    c.draw();
    cout << "Area: " << c.calculateArea() << " units^2 "<< endl;
    cout << "Perimeter: " << c.calculatePerimeter() << " units" << endl;

    Rectangle r(2, 3, "silver", 8, 4);
    r.draw();
    cout << "Area: " << r.calculateArea() << " units^2" << endl;
    cout << "Perimeter: " << r.calculatePerimeter() << " units" <<  endl;

    Triangle t(1, 6, "black", 3, 4, 5);
    t.draw();
    cout << "Area: " << t.calculateArea() << " units^2" << endl;
    cout << "Perimeter: " << t.calculatePerimeter() << " units" << endl;

    return 0;
}
