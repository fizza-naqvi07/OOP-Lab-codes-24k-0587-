#include <iostream>
using namespace std;

class Circle
{
public:
    Circle(double r) : radius(r) {}

    double getArea()
    {
        return 3.1416 * radius * radius;
    }

    double getPer()
    {
        return 2 * 3.1416 * radius;
    }

private:
    double radius;
};

int main()
{
    double radius;
    cout << "Enter the radius of the circle: ";
    cin >> radius;

    Circle cir(radius);
    cout << "Area of the circle: " << cir.getArea() << endl;
    cout << "Perimeter of the circle: " << cir.getPer() << endl;

    return 0;
}
