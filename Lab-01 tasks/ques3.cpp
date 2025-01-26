#include <iostream>
using namespace std;

float CalculateBill(float units);
void Surcharge(float bill);

int main()
{
    int ID;
    string name;
    float units, charges;

    cout << "Enter customer's ID: " << endl;
    cin >> ID;
    cout << "Enter customer's name: " << endl;
    cin >> name;
    cout << "Enter consumed units: " << endl;
    cin >> units;

    charges = CalculateBill(units);

    cout << "Customer ID:" << ID << endl;
    cout << "Customer Name:" << name << endl;
    cout << "Units Consumed:" << units << endl;
    cout << "Amount Charges:" << charges << endl;

    Surcharge(charges);

    return 0;
}
float CalculateBill(float units)
{
    float bill;
    if (units > 0 && units <= 199)
    {
        bill = units * 16.20;
        return bill;
    }
    else if (units >= 200 && units < 300)
    {
        bill = units * 20.10;
        return bill;
    }
    else if (units >= 300 && units < 500)
    {
        bill = units * 27.10;
        return bill;
    }
    else if (units >= 500)
    {
        bill = units * 35.90;
        return bill;
    }
    else
    {
        cout << "Invalid value!" << endl;
    }
    return 0;
}
void Surcharge(float bill)
{
    float sc;
    if (bill >= 18000)
    {
        sc = 0.15 * bill;
        cout << "Surcharge Amount: ";
        bill = bill + sc;
        cout << "Net amount paid by the customer: " << bill << endl;
    }
    else
    {
        cout << "No surcharge applicable!" << endl;
    }
}