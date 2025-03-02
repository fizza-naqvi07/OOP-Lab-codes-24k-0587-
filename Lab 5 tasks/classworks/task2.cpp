#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Car {
private:
    string name;
    int id;

public:
    Car(string name, int id) : name(name), id(id) {}

    void printDetails() {
        cout << "Car ID: " << id << "\nName: " << name << endl;
    }

    int getID() {
        return id;
    }
};

class Garage {
private:
    Car* car1;
    Car* car2;
    Car* car3;

public:
    Garage() : car1(nullptr), car2(nullptr), car3(nullptr) {}

    void parkCar(Car* car) {
        if (car1 == nullptr) car1 = car;
        else if (car2 == nullptr) car2 = car;
        else if (car3 == nullptr) car3 = car;
        else cout << "Garage is full!" << endl;
    }

    void listCars() {
        if (car1) car1->printDetails();
        if (car2) car2->printDetails();
        if (car3) car3->printDetails();
    }
};

int main() {
    string name;
    int id;
    Garage garage;

    for (int i = 0; i < 3; i++) {
        cout << "Enter the name of the car: ";
        cin >> name;
        cout << "Enter the ID of the car: ";
        cin >> id;

        Car* car = new Car(name, id);
        garage.parkCar(car);
    }

    cout << "\nListing all parked cars:" << endl;
    garage.listCars();

    return 0;
}
