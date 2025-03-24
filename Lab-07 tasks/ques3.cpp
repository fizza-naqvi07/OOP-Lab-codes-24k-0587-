#include <iostream>
#include <string>
using namespace std;

class Currency
{
protected:
    double *amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate;

public:
    Currency(double amt, string code, string symbol, double rate)
    {
        amount = new double(amt);
        currencyCode = code;
        currencySymbol = symbol;
        exchangeRate = rate;
    }

    virtual ~Currency()
    {
        delete amount;
    }

    virtual double convertToBase()
    {
        return (*amount) * exchangeRate;
    }

    virtual double convertTo(Currency *targetCurrency)
    {
        return convertToBase() / targetCurrency->exchangeRate;
    }

    virtual void displayCurrency()
    {
        cout << currencySymbol << *amount << " (" << currencyCode << ")" << endl;
    }
};

class Dollar : public Currency
{
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}
};

class Euro : public Currency
{
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 1.1) {}
};

class Rupee : public Currency
{
public:
    Rupee(double amt) : Currency(amt, "INR", "₹", 0.012) {}
};

int main()
{
    Currency *d = new Dollar(545);
    Currency *e = new Euro(220);
    Currency *r = new Rupee(1000);

    d->displayCurrency();
    cout << "Converted to Euro: " << d->convertTo(e) << " EUR" << endl;
    cout << "Converted to Rupee: " << d->convertTo(r) << " INR" << endl;

    e->displayCurrency();
    cout << "Converted to Dollar: " << e->convertTo(d) << " USD" << endl;
    cout << "Converted to Rupee: " << e->convertTo(r) << " INR" << endl;

    r->displayCurrency();
    cout << "Converted to Dollar: " << r->convertTo(d) << " USD" << endl;
    cout << "Converted to Euro: " << r->convertTo(e) << " EUR" << endl;

    delete d;
    delete e;
    delete r;

    return 0;
}
