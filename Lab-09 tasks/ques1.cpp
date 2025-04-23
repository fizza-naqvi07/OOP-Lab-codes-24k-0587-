#include <iostream>
#include <string>
using namespace std;

class Wallet
{
private:
    double bal;
    int d_count; // d_count = daily deposit count
    int w_count; // w_count = daily withdrawl count
    static const int MAX_TX = 5;
    static const double MAX_DEP;
    static const double MAX_WDR;

public:
    Wallet() : bal(0), d_count(0), w_count(0) {}

    bool dep(double amt)
    {
        if (d_count >= MAX_TX || amt <= 0 || amt > MAX_DEP)
        {
            cout << "Deposit failed.\n";
            return false;
        }
        bal += amt;
        d_count++;
        cout << "Deposited Rs." << amt << ". Balance: Rs." << bal << endl;
        return true;
    }

    bool wdr(double amt)
    {
        if (w_count >= MAX_TX || amt <= 0 || amt > MAX_WDR || amt > bal)
        {
            cout << "Withdrawal failed.\n";
            return false;
        }
        bal -= amt;
        w_count++;
        cout << "Withdrawn Rs." << amt << ". Balance: Rs." << bal << endl;
        return true;
    }

    double getBal() const
    {
        return bal;
    }
};

const double Wallet::MAX_DEP = 5000;
const double Wallet::MAX_WDR = 3000;

class User
{
private:
    int id;
    string name;
    Wallet w;

public:
    User(int i, string n) : id(i), name(n) {}

    void dep(double amt)
    {
        cout << "(" << name << ") ";
        w.dep(amt);
    }

    void wdr(double amt)
    {
        cout << "(" << name << ") ";
        w.wdr(amt);
    }

    void bal() const
    {
        cout << "(" << name << ") Balance: Rs." << w.getBal() << endl;
    }
};

int main()
{
    User u1(1, "fizza");
    User u2(2, "manahil");

    u1.dep(2000);
    u1.dep(3000);
    u1.dep(6000);
    u1.wdr(1000);
    u1.wdr(2500);
    u1.wdr(2000);
    u1.bal();

    cout << "--------------------------" << endl;

    u2.dep(4000);
    u2.wdr(1000);
    u2.bal();

    return 0;
}
