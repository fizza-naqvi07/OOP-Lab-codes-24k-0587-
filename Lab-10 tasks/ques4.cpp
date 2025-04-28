#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void rotate(int n) {
    string oldn = "log.txt";
    string newn = "log" + to_string(n) + ".txt";
    rename(oldn.c_str(), newn.c_str());
}

long fsize(string fname) {
    ifstream f(fname, ios::binary | ios::ate);
    if (!f) return -1;
    return f.tellg();
}

int main() {
    int c = 1;
    const long mx = 1 * 1024 * 1024;
    string msg;

    while (true) {
        cout << "Log msg (exit to quit): ";
        getline(cin, msg);
        if (msg == "exit") break;

        ofstream fout("log.txt", ios::app);
        fout << msg << endl;
        fout.close();

        if (fsize("log.txt") >= mx) {
            rotate(c);
            c++;
        }
    }

    return 0;
}
