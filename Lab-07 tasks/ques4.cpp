# include <iostream>
# include <string>
using namespace std;

class Person
{
protected:
    string name;
    int id;
    string address;
    string ph_num;
    string email;

public:
    Person(string n, int Id, string add, string num, string mail) : name(n), id(Id), address(add), ph_num(num), email(mail) {}

    virtual void displayInfo()
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << ph_num << endl;
        cout << "Email Address: " << email << endl;
       
    }

    void updateInfo()
    {
        int opt;
        cout << "(1) ID\n(2) Name\n(3) Address\n(4) Phone Number\n(5) Email Address\nEnter your choice to update: " << endl;
        cin >> opt;
        switch (opt)
        {
        case 1:
            cout << "Enter new ID: " << endl;
            cin >> id;
            break;
        case 2:
            cout << "Enter new name: " << endl;
            cin >> name;
            break;
        case 3:
            cout << "Enter new address: " << endl;
            cin >> address;
            break;
        case 4:
            cout << "Enter new phone number: " << endl;
            cin >> ph_num;
            break;
        case 5:
            cout << "Enter new email address: " << endl;
            cin >> email;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    }
};

class Student : public Person
{
    string coursesEnrolled;
    double GPA;
    int enrollmentYear;

public:
    Student(string n, int Id, string add, string num, string mail, string courses, double gpa, int year)
        : Person(n, Id, add, num, mail), coursesEnrolled(courses), GPA(gpa), enrollmentYear(year) {}

    void displayInfo() override
    {
        Person::displayInfo();
        cout << "Courses Enrolled: " << coursesEnrolled << endl;
        cout << "GPA: " << GPA << endl;
        cout << "Enrollment Year: " << enrollmentYear << endl;
        cout << "--------------------------" << endl;
    }
};

class Professor : public Person
{
    string department;
    string coursesTaught;
    double salary;

public:
    Professor(string n, int Id, string add, string num, string mail, string dept, string courses, double sal)
        : Person(n, Id, add, num, mail), department(dept), coursesTaught(courses), salary(sal) {}

    void displayInfo() override
    {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Courses Taught: " << coursesTaught << endl;
        cout << "Salary: " << salary << endl;
        cout << "--------------------------" << endl;
    }
};

class Staff : public Person
{
    string department;
    string position;
    double salary;

public:
    Staff(string n, int Id, string add, string num, string mail, string dept, string pos, double sal)
        : Person(n, Id, add, num, mail), department(dept), position(pos), salary(sal) {}

    void displayInfo() override
    {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << endl;
        cout << "--------------------------" << endl;
    }
};

class Course
{
    int courseId;
    string courseName;
    int credits;
    string instructor;
    string schedule;

public:
    Course(int id, string name, int cred, string instr, string sched)
        : courseId(id), courseName(name), credits(cred), instructor(instr), schedule(sched) {}

    void displayCourse()
    {
        cout << "Course ID: " << courseId << endl;
        cout << "Course Name: " << courseName << endl;
        cout << "Credits: " << credits << endl;
        cout << "Instructor: " << instructor << endl;
        cout << "Schedule: " << schedule << endl;
        cout << "--------------------------" << endl;
    }
};

int main()
{
    Student student("Laiba Naqvi", 101, "Soldier Bazar", "+923004704546", "laibanaqvi1101@gmail.com", "Math, Science", 3.8, 2022);
    student.displayInfo();
    student.updateInfo();
    student.displayInfo();

    Professor professor("Naheel Rizvi", 201, "Malir Cantt", "+923218381125", "rizvinaheel2311@yahoo.com", "Computer Science", "Algorithms, AI", 85000);
    professor.displayInfo();

    Staff staff("Manahil Hassan", 572, "North Nazimabad", "+923414799257", "manahilabd112@gmail.com", "Administration", "Registrar", 50000);
    staff.displayInfo();

    Course course(101, "Data Structures", 3, "Dr. Fizza", "Mon-Wed 10 AM");
    course.displayCourse();

    return 0;
}
