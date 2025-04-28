#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Emp {
public:
    int id;
    string name, desig;
    int yrs;

    void write(fstream &f) {
        f << id << "," << name << "," << desig << "," << yrs << endl;
    }
};

int main() {
    fstream f("emp.txt", ios::out);
    Emp e1 = {1, "Naheel", "Manager", 3};
    Emp e2 = {2, "Laiba", "Developer", 1};
    Emp e3 = {3, "Raza", "Manager", 2};
    e1.write(f);
    e2.write(f);
    e3.write(f);
    f.close();

    fstream fin("emp.txt", ios::in);
    fstream fout("temp.txt", ios::out);
    string line;
    while (getline(fin, line)) {
        stringstream ss(line);
        string id, name, desig, yrs;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, desig, ',');
        getline(ss, yrs, ',');
        if (desig == "Manager" && stoi(yrs) >= 2) {
            fout << id << "," << name << "," << desig << "," << yrs << endl;
        }
    }
    fin.close();
    fout.close();

    remove("emp.txt");
    rename("temp.txt", "emp.txt");

    fstream upd("emp.txt", ios::in);
    fstream newf("new_emp.txt", ios::out);
    int nid = 1;
    while (getline(upd, line)) {
        stringstream ss(line);
        string id, name, desig, yrs;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, desig, ',');
        getline(ss, yrs, ',');
        newf << nid++ << "," << name << "," << desig << "," << (stoi(yrs) + 1) << endl;
    }
    upd.close();
    newf.close();

    return 0;
}
