#include <iostream>

using namespace std;

class Account
{
public:
    Account(int id, double int_bal) : cust_id(id), bal(int_bal) {}

    void credit(double amt)
    {
        bal += amt;
        cout << "Customer ID: " << cust_id << endl
             << " Credited Rs. " << amt << endl
             << " New Balance: Rs. " << bal << endl;
    }

    void debit(double amt)
    {
        if (amt <= bal)
        {
            bal -= amt;
            cout << "Customer ID: " << cust_id << endl
                 << " Debited Rs. " << amt << endl
                 << " New Balance: Rs. " << bal << endl;
        }
        else
        {
            cout << "Customer ID: " << cust_id << endl
                 << " tried to debit Rs. " << amt << ", but insufficient balance!" << endl;
        }
    }

    double getBal()
    {
        return bal;
    }

private:
    int cust_id;
    double bal;
};

int main()
{
    int id;
    double int_bal, amt;

    cout << "Enter customer ID: ";
    cin >> id;
    cout << "Enter initial balance: Rs. ";
    cin >> int_bal;

    Account acc(id, int_bal);

    cout << "Enter amount to credit: Rs. ";
    cin >> amt;
    acc.credit(amt);

    cout << "Enter amount to debit: Rs. ";
    cin >> amt;
    acc.debit(amt);

    return 0;
}
