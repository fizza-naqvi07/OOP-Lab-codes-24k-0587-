#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class User {
public:
    string uid, fname, lname, addr, mail;
    void write(ofstream &f) {
        f << uid << "," << fname << "," << lname << "," << addr << "," << mail << endl;
    }
};

class Prod {
public:
    string pid, pname, desc;
    int price;
    void write(ofstream &f) {
        f << pid << "," << pname << "," << desc << "," << price << endl;
    }
};

class Ord {
public:
    string oid, uid, pid;
    int paid;
    void write(ofstream &f) {
        f << oid << "," << uid << "," << pid << "," << paid << endl;
    }
};

int main() {
    ofstream u("users.txt");
    User u1 = {"U1", "Naheel", "Rizvi", "Europe", "rizvinaheel@gmail.com"};
    User u2 = {"U2", "Linus", "T", "USA", "linus@gmail.com"};
    u1.write(u);
    u2.write(u);
    u.close();

    ofstream p("products.txt");
    Prod p1 = {"P1", "Monitor", "HD Display", 200};
    Prod p2 = {"P2", "Keyboard", "Mechanical", 100};
    p1.write(p);
    p2.write(p);
    p.close();

    ofstream o("orders.txt");
    Ord o1 = {"O1", "U2", "P1", 200};
    Ord o2 = {"O2", "U2", "P2", 100};
    o1.write(o);
    o2.write(o);
    o.close();

    ifstream fin("users.txt");
    string line, find_uid;
    while (getline(fin, line)) {
        stringstream ss(line);
        string uid, fname, lname, addr, mail;
        getline(ss, uid, ',');
        getline(ss, fname, ',');
        getline(ss, lname, ',');
        getline(ss, addr, ',');
        getline(ss, mail, ',');
        if (fname == "Linus") {
            find_uid = uid;
            break;
        }
    }
    fin.close();

    string pids[10];
    int cnt = 0;
    ifstream ordr("orders.txt");
    while (getline(ordr, line)) {
        stringstream ss(line);
        string oid, uid, pid, paid;
        getline(ss, oid, ',');
        getline(ss, uid, ',');
        getline(ss, pid, ',');
        getline(ss, paid, ',');
        if (uid == find_uid) {
            pids[cnt++] = pid;
        }
    }
    ordr.close();

    for (int i = 0; i < cnt; i++) {
        ifstream prod("products.txt");
        while (getline(prod, line)) {
            stringstream ss(line);
            string pid, pname, desc, price;
            getline(ss, pid, ',');
            getline(ss, pname, ',');
            getline(ss, desc, ',');
            getline(ss, price, ',');
            if (pid == pids[i]) {
                cout << pname << endl;
            }
        }
        prod.close();
    }

    return 0;
}
