#include <iostream>
using namespace std;

struct Employee
{
    int e_id;
    string e_name;
    float e_salary;
};

struct Organisation
{
    string org_name;
    string org_num;
    struct Employee emp;
};

int main()
{
    struct Organisation org;
    org.org_name = "NU-Fast";
    org.org_num = "NUFAST123ABC";
    org.emp.e_id = 127;
    org.emp.e_name = "Linus Sebastian";
    org.emp.e_salary = 400000;

    cout << "The size of the structure organistaion: " << sizeof(Organisation) << endl;
    cout << "Organisation Name: " << org.org_name << endl;
    cout << "Organisation Number: " << org.org_num << endl;
    cout << "Employee ID: " << org.emp.e_id << endl;
    cout << "Employee Name: " << org.emp.e_name << endl;
    cout << "Employee Salary: " << org.emp.e_salary << endl;

    return 0;
}