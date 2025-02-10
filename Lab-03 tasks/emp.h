#ifndef EMP_H
#define EMP_H

#include <iostream>
using namespace std;

class Employee
{
public:
    string f_name;
    string l_name;
    double m_sal;

    double Raise()
    {
        double n_sal;
        n_sal = m_sal + (m_sal * 0.10);
        return n_sal;
    }

    void display()
    {
        cout << "Employee Name: " << f_name << " " << l_name << endl;
        cout << "Monthly Salary: Rs." << m_sal << endl;
        cout << "Yearly Salary: Rs." << m_sal * 12 << endl;
    }

    void display2()
    {
        double newSal = Raise();
        cout << "Employee Name: " << f_name << " " << l_name << endl;
        cout << "New Yearly Salary: Rs." << newSal * 12 << endl;
    }
};

#endif
