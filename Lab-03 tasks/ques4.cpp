#include <iostream>
#include <cstdlib>
#include "emp.h"
using namespace std;

int main(int argc, char *argv[])
{

    string f_name = argv[1];
    string l_name = argv[2];
    double m_sal = atof(argv[3]);
    string f_name2 = argv[4];
    string l_name2 = argv[5];
    double sal2 = atof(argv[6]);

    Employee Emp1;
    Emp1.f_name = f_name;
    Emp1.l_name = l_name;
    Emp1.m_sal = m_sal;

    Employee Emp2;
    Emp2.f_name = f_name2;
    Emp2.l_name = l_name2;
    Emp2.m_sal = sal2;

    Emp1.display();
    Emp2.display();

    cout << "Congratulations! You got a raise of 10%" << endl;

    Emp1.display2();
    Emp2.display2();

    return 0;
}
