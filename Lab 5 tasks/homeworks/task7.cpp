#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    const int roll_no;

    Student() : roll_no(0) {}

    void assignRollNo(int roll) {
        const_cast<int&>(roll_no) = roll;
    }

    void display() {
        cout << "Student Roll Number: " << roll_no << endl;
    }
};

int main() {
    Student student;
    int roll;
    
    cout << "Enter the roll number: ";
    cin >> roll;

    student.assignRollNo(roll);
    student.display();

    return 0;
}
