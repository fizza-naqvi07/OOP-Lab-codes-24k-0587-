#include <iostream>
using namespace std;

class student {
protected:
    int id;
    string name;
public:
    void getstudentdetails() {
        cout << "Enter Student ID: ";
        cin >> id;
        cout << "Enter Student Name: ";
        cin.ignore();
        getline(cin, name);
    }
    void displaystudentdetails() {
        cout << "-----------------------" << endl;
        cout << "Student ID: " << id << endl;
        cout << "Student Name: " << name << endl;
    }
};

class marks : public student {
protected:
    int marks_oop, marks_pf, marks_ds, marks_db;
public:
    void getmarks() {
        cout << "Enter marks for OOP: ";
        cin >> marks_oop;
        cout << "Enter marks for PF: ";
        cin >> marks_pf;
        cout << "Enter marks for DS: ";
        cin >> marks_ds;
        cout << "Enter marks for DB: ";
        cin >> marks_db;
    }
    void displaymarks() {
        cout << "Marks in OOP: " << marks_oop << endl;
        cout << "Marks in PF: " << marks_pf << endl;
        cout << "Marks in DS: " << marks_ds << endl;
        cout << "Marks in DB: " << marks_db << endl;
    }
};

class result : public marks {
protected:
    int total_marks;
    double avg_marks;
public:
    void calculate() {
        total_marks = marks_oop + marks_pf + marks_ds + marks_db;
        avg_marks = total_marks / 4.0;
    }
    void display() {
        displaystudentdetails();
        displaymarks();
        cout << "Total Marks: " << total_marks << endl;
        cout << "Average Marks: " << avg_marks << endl;
        cout << "-----------------------" << endl;
    }
    void addData() {
        getstudentdetails();
        getmarks();
        calculate();
    }
};

int main() {
    result r;
    char choice;
    do {
        r.addData();
        r.display();
        cout << "Do you want to enter another student's data? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    return 0;
}
