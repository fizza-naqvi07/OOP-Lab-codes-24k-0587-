#include <iostream>
#include <string>

using namespace std;

class Vehicle {
protected:
    double price;
public:
    Vehicle(double p) : price(p) {}
    virtual void display() = 0;
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
protected:
    int seatingCapacity, numDoors;
    string fuelType;
public:
    Car(double p, int s, int d, string f) : Vehicle(p), seatingCapacity(s), numDoors(d), fuelType(f) {}
};

class Motorcycle : public Vehicle {
protected:
    int numCylinders, numGears, numWheels;
public:
    Motorcycle(double p, int c, int g, int w) : Vehicle(p), numCylinders(c), numGears(g), numWheels(w) {}
};

class Audi : public Car {
private:
    string modelType;
public:
    Audi(double p, int s, int d, string f, string m) : Car(p, s, d, f), modelType(m) {}
    void display() override {
        cout << "Audi Car Details:\nPrice: $" << price << "\nSeating Capacity: " << seatingCapacity
             << "\nNumber of Doors: " << numDoors << "\nFuel Type: " << fuelType
             << "\nModel Type: " << modelType << "\n";
    }
};

class Yamaha : public Motorcycle {
private:
    string makeType;
public:
    Yamaha(double p, int c, int g, int w, string m) : Motorcycle(p, c, g, w), makeType(m) {}
    void display() override {
        cout << "Yamaha Motorcycle Details:\nPrice: $" << price << "\nNumber of Cylinders: " << numCylinders
             << "\nNumber of Gears: " << numGears << "\nNumber of Wheels: " << numWheels
             << "\nMake Type: " << makeType << "\n";
    }
};

int main() {
    Vehicle* v1 = new Audi(50000, 5, 4, "Petrol", "A6");
    Vehicle* v2 = new Yamaha(15000, 2, 6, 2, "YZF-R1");
    
    v1->display();
    cout << "------------------\n";
    v2->display();
    
    delete v1;
    delete v2;
    
    return 0;
}
