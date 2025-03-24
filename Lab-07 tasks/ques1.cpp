#include <iostream>
#include <string>
using namespace std;

class Account
{
protected:
    int accNum;
    double balance;
    string holder;
    string accountType;
    string transactionHistory;

public:
    Account(int num, double bal, const string &name, const string &type) 
        : accNum(num), balance(bal), holder(name), accountType(type), transactionHistory("") {}

    virtual void deposit(double amount)
    {
        balance += amount;
        transactionHistory += "Deposited Rs." + to_string(amount) + "\n";
        cout << "Rs." << amount << " has been deposited in your account." << endl;
    }

    virtual void withdraw(double amount)
    {
        if (balance < amount)
        {
            cout << "Insufficient balance for the withdrawal." << endl;
        }
        else
        {
            balance -= amount;
            transactionHistory += "Withdrawn Rs." + to_string(amount) + "\n";
            cout << "Rs." << amount << " withdrawn from your account." << endl;
            cout << "Remaining Balance: Rs." << balance << endl;
        }
    }

    virtual double calculateInterest() = 0;

    virtual void printStatement()
    {
        getAccountInfo();
        cout << "Transaction History:\n";
        if (transactionHistory.empty())
        {
            cout << "No transactions found." << endl;
        }
        else
        {
            cout << transactionHistory;
        }
    }

    void getAccountInfo()
    {
        cout << "Account Number: " << accNum << endl;
        cout << "Account Holder: " << holder << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: Rs." << balance << endl;
    }
};

class SavingsAccount : public Account
{
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(int num, double bal, const string &name) 
        : Account(num, bal, name, "savings"), interestRate(0.04), minimumBalance(1000) {}

    double calculateInterest() override
    {
        return balance * interestRate;
    }

    void withdraw(double amount) override
    {
        if ((balance - amount) < minimumBalance)
        {
            cout << "Cannot withdraw. Minimum balance requirement not met." << endl;
        }
        else
        {
            Account::withdraw(amount);
        }
    }
};

class CheckingAccount : public Account
{
public:
    CheckingAccount(int num, double bal, const string &name) 
        : Account(num, bal, name, "checking") {}

    double calculateInterest() override
    {
        return 0;
    }
};

class FixedDepositAccount : public Account
{
    double fixedInterestRate;
    int maturityPeriod;

public:
    FixedDepositAccount(int num, double bal, const string &name, int maturity) 
        : Account(num, bal, name, "fixed deposit"), fixedInterestRate(0.06), maturityPeriod(maturity) {}

    double calculateInterest() override
    {
        return balance * fixedInterestRate * (maturityPeriod / 12.0);
    }

    void withdraw(double amount) override
    {
        cout << "Withdrawals are not allowed before maturity." << endl;
    }
};

int main()
{
    cout << "---- Savings Account ----\n";
    SavingsAccount sa(12345, 5000, "Fizza Naqvi");
    sa.deposit(2000);
    sa.withdraw(1000);
    sa.printStatement();
    cout << "Interest Earned: Rs." << sa.calculateInterest() << endl;

    cout << "\n---- Checking Account ----\n";
    CheckingAccount ca(67890, 3000, "Fizza Naqvi");
    ca.deposit(1000);
    ca.withdraw(500);
    ca.printStatement();

    cout << "\n---- Fixed Deposit Account ----\n";
    FixedDepositAccount fda(11111, 10000, "Naheel Raza", 12);
    fda.printStatement();
    cout << "Fixed Deposit Interest Earned: Rs." << fda.calculateInterest() << endl;
    fda.withdraw(2000);

    return 0;
}
