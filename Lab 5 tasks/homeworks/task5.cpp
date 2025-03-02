#include <iostream>

using namespace std;

class Car {
public:
    int hp;
    int seats;
    int speakers;

    void setAttrs(int h, int s, int sp) {
        hp = h;
        seats = s;
        speakers = sp;
    }

    void displayAttrs() const {
        cout << "Horsepower: " << hp << endl;
        cout << "Seats: " << seats << endl;
        cout << "Speakers: " << speakers << endl;
    }
};

int main() {
    Car car;
    int h, s, sp;

    cout << "Enter horsepower: ";
    cin >> h;
    cout << "Enter seats: ";
    cin >> s;
    cout << "Enter speakers: ";
    cin >> sp;

    car.setAttrs(h, s, sp);
    car.displayAttrs();

    return 0;
}
