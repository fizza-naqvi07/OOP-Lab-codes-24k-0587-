#include <iostream>
#include <string>
using namespace std;

class Car {
protected:
    string model;
    double price;

public:
    Car(string m) : model(m), price(0.0) {}

    string getModel() {
        return model;
    }

    double getPrice() {
        return price;
    }

    void setModel(string m) {
        model = m;
    }

    virtual void setPrice(double p) = 0;
};

class Color : public Car {
private:
    string color;

public:
    Color(string m, string c) : Car(m), color(c) {}

    void setPrice(double p) override {
        price = p + 10000;
    }

    void display() {
        cout << "Model: " << model << ", Color: " << color << ", Price: " << price << endl;
    }
};

class Company : public Car {
private:
    string company;

public:
    Company(string m, string comp) : Car(m), company(comp) {}

    void setPrice(double p) override {
        price = p + 20000;
    }

    void display() {
        cout << "Model: " << model << ", Company: " << company << ", Price: " << price << endl;
    }
};

int main() {
    Color c1("Civic", "Black");
    c1.setPrice(3500000);

    Company c2("Corolla", "Toyota");
    c2.setPrice(2850000);

    c1.display();
    c2.display();

    return 0;
}
