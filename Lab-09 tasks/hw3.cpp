#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int id;

public:
    virtual void getData() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
    }

    virtual void displayData() {
        cout << "Name: " << name << ", ID: " << id << endl;
    }

    virtual void bonus() = 0; // pure virtual
};

class Admin : virtual public Person {
protected:
    double admin_salary;

public:
    void getData() override {
        Person::getData();
        cout << "Enter admin salary: ";
        cin >> admin_salary;
    }

    void displayData() override {
        Person::displayData();
        cout << "Admin Salary: " << admin_salary << endl;
    }

    void bonus() override {
        cout << "Admin Bonus: " << admin_salary * 0.10 << endl;
    }
};

class Account : virtual public Person {
protected:
    double account_salary;

public:
    void getData() override {
        Person::getData();
        cout << "Enter account salary: ";
        cin >> account_salary;
    }

    void displayData() override {
        Person::displayData();
        cout << "Account Salary: " << account_salary << endl;
    }

    void bonus() override {
        cout << "Account Bonus: " << account_salary * 0.12 << endl;
    }
};

class Master : public Admin, public Account {
private:
    double total_salary;

public:
    void getData() override {
        Person::getData();
        cout << "Enter admin salary: ";
        cin >> admin_salary;
        cout << "Enter account salary: ";
        cin >> account_salary;
        total_salary = admin_salary + account_salary;
    }

    void displayData() override {
        Person::displayData();
        cout << "Admin Salary: " << admin_salary << ", Account Salary: " << account_salary << endl;
    }

    void bonus() override {
        cout << "Master Bonus (15% of total): " << total_salary * 0.15 << endl;
    }
};

int main() {
    Person* ptr;

    Master m;
    cout << "\n--- Enter Master Employee Data ---" << endl;
    ptr = &m;
    ptr->getData();
    cout << "\n--- Displaying Master Data ---" << endl;
    ptr->displayData();
    ptr->bonus();

    return 0;
}
