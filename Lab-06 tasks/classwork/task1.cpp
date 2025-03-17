#include <iostream>
#include <string>

using namespace std;

class BankAcc {
protected:
    string accNum;
    double bal;
public:
    BankAcc(string num, double b) : accNum(num), bal(b) {}
    virtual ~BankAcc() {}
    virtual void dep(double amt) { bal += amt; }
    virtual void wd(double amt) {
        if (amt <= bal)
            bal -= amt;
        else
            cout << "Insufficient funds!\n";
    }
    virtual void update() {}
    virtual void show() const {
        cout << "Account: " << accNum << " | Balance: " << bal << "\n";
    }
    void setBalance(double newBal) { bal = newBal; }
};

class SavAcc : public BankAcc {
    double rate;
public:
    SavAcc(string num, double b, double r) : BankAcc(num, b), rate(r) {}
    void update() override { bal += bal * rate; }
};

class ChkAcc : public BankAcc {
    double odLimit;
public:
    ChkAcc(string num, double b, double limit) : BankAcc(num, b), odLimit(limit) {}
    void wd(double amt) override {
        if (bal - amt >= -odLimit) {
            bal -= amt;
            if (bal < 0)
                cout << "Alert: Overdraft used!\n";
        } else {
            cout << "Overdraft limit exceeded!\n";
        }
    }
};

class BusAcc : public BankAcc {
    double tax;
public:
    BusAcc(string num, double b, double t) : BankAcc(num, b), tax(t) {}
    void dep(double amt) override { bal += amt - (amt * tax); }
};

class User {
protected:
    string name;
public:
    User(string n) : name(n) {}
    virtual ~User() {}
    virtual void trans(BankAcc &acc, double amt, bool isDep) {
        if (isDep)
            acc.dep(amt);
        else
            acc.wd(amt);
    }
};

class Cust : public User {
public:
    Cust(string n) : User(n) {}
};

class Emp : public User {
public:
    Emp(string n) : User(n) {}
    virtual void freeze(BankAcc &acc) {
        cout << "Account frozen by " << name << "\n";
    }
};

class Tel : public Emp {
public:
    Tel(string n) : Emp(n) {}
};

class Mgr : public Emp {
public:
    Mgr(string n) : Emp(n) {}
    void overrideAcc(BankAcc &acc, double newBal) {
        cout << "Manager overriding balance!\n";
        acc.setBalance(newBal);
    }
};

int main() {
    BankAcc* accounts[3];
    accounts[0] = new SavAcc("L999", 1000, 0.05);
    accounts[1] = new ChkAcc("F007", 500, 200);
    accounts[2] = new BusAcc("M231", 2000, 0.10);
    
    for (int i = 0; i < 3; i++) {
        accounts[i]->update();
        accounts[i]->show();
    }
    
    for (int i = 0; i < 3; i++) {
        delete accounts[i];
    }
    
    return 0;
}
