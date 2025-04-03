#include<iostream>
using namespace std;

class Person {
protected:
    int empID;
public:
    void getData(int id) { empID = id; }
    void displayData() { cout << "Employee ID: " << empID << endl; }
};

class Admin : public Person {
    string name;
    float monthlyIncome;
public:
    void getData(int id, string n, float income) {
        Person::getData(id);
        name = n;
        monthlyIncome = income;
    }
    
    void displayData() {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: " << monthlyIncome << endl;
    }
    
    void bonus() {
        float annualBonus = (monthlyIncome * 12) * 0.05;
        cout << "Bonus: " << annualBonus << endl;
    }
};

class Accounts : public Person {
    string name;
    float monthlyIncome;
public:
    void getData(int id, string n, float income) {
        Person::getData(id);
        name = n;
        monthlyIncome = income;
    }
    
    void displayData() {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: " << monthlyIncome << endl;
    }
    
    void bonus() {
        float annualBonus = (monthlyIncome * 12) * 0.05;
        cout << "Bonus: " << annualBonus << endl;
    }
};

int main() {
    Admin admin1;
    admin1.getData(101, "Fizza", 5000);
    admin1.displayData();
    admin1.bonus();
    
    cout << endl;
    
    Accounts account1;
    account1.getData(102, "Manahil", 4000);
    account1.displayData();
    account1.bonus();
    
    return 0;
}
