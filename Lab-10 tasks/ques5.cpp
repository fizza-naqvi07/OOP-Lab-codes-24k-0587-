#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void add() {
    string t;
    cout << "Task: ";
    getline(cin, t);
    ofstream f("todo.txt", ios::app);
    f << t << ",Not Done" << endl;
    f.close();
}

void view() {
    ifstream f("todo.txt");
    string l;
    int i = 1;
    cout << "Tasks:" << endl;
    while (getline(f, l)) {
        cout << i++ << ". " << l << endl;
    }
    f.close();
}

void done() {
    ifstream f("todo.txt");
    ofstream tmp("temp.txt");
    string l;
    int n, c = 1;
    cout << "Task no: ";
    cin >> n;
    cin.ignore();

    while (getline(f, l)) {
        if (c == n) {
            size_t p = l.find(",Not Done");
            if (p != string::npos) {
                l.replace(p, 9, ",Done");
            }
        }
        tmp << l << endl;
        c++;
    }
    f.close();
    tmp.close();
    remove("todo.txt");
    rename("temp.txt", "todo.txt");
}

int main() {
    int ch;
    while (true) {
        cout << "-------- To-Do Task List--------" << endl;
        cout << "1. Add\n2. View\n3. Done\n4. Exit\nChoice: ";
        cin >> ch;
        cin.ignore();
        if (ch == 1) add();
        else if (ch == 2) view();
        else if (ch == 3) done();
        else if (ch == 4) break;
        else cout << "Invalid\n";
    }
    return 0;
}
