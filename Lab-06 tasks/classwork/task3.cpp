#include <iostream>
#include <string>

using namespace std;

class Employee {
protected:
    int id;
    string name;
public:
    Employee(int i, string n) : id(i), name(n) {}
    virtual ~Employee() {}
};

class IOrderTaker {
public:
    virtual void takeOrder(string order) = 0;
    virtual ~IOrderTaker() {}
};

class IOrderPreparer {
public:
    virtual void prepareOrder(string order) = 0;
    virtual ~IOrderPreparer() {}
};

class IBiller {
public:
    virtual void generateBill(double amount) = 0;
    virtual ~IBiller() {}
};

class Waiter : public Employee, public IOrderTaker {
public:
    Waiter(int i, string n) : Employee(i, n) {}
    void takeOrder(string order) override {
        cout << name << " took order: " << order << "\n";
    }
};

class Chef : public Employee, public IOrderPreparer {
public:
    Chef(int i, string n) : Employee(i, n) {}
    void prepareOrder(string order) override {
        cout << name << " is preparing: " << order << "\n";
    }
};

class Cashier : public Employee, public IBiller {
public:
    Cashier(int i, string n) : Employee(i, n) {}
    void generateBill(double amount) override {
        cout << name << " generated bill: $" << amount << "\n";
    }
};

class Manager : public Employee, public IOrderTaker, public IBiller {
public:
    Manager(int i, string n) : Employee(i, n) {}
    void takeOrder(string order) override {
        cout << name << " (Manager) took order: " << order << "\n";
    }
    void generateBill(double amount) override {
        cout << name << " (Manager) generated bill: $" << amount << "\n";
    }
};

class Menu {
public:
    virtual double calcTotal(double basePrice) = 0;
    virtual ~Menu() {}
};

class FoodMenu : public Menu {
public:
    double calcTotal(double basePrice) override { return basePrice; }
};

class BeverageMenu : public Menu {
public:
    double calcTotal(double basePrice) override { return basePrice * 1.1; }
};

int main() {
    Employee* staff[] = { new Waiter(101, "Arham"), new Chef(102, "Laiba"), new Cashier(103, "Fazl"), new Manager(201, "Razi") };
    
    for (int i = 0; i < 4; i++) {
        if (IOrderTaker* ot = dynamic_cast<IOrderTaker*>(staff[i]))
            ot->takeOrder("Pizza and Soda");
        if (IOrderPreparer* op = dynamic_cast<IOrderPreparer*>(staff[i]))
            op->prepareOrder("Pizza");
        if (IBiller* b = dynamic_cast<IBiller*>(staff[i]))
            b->generateBill(15.99);
    }
    
    for (int i = 0; i < 4; i++) delete staff[i];
    
    return 0;
}
