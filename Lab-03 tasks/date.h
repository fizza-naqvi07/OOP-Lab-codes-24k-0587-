#ifndef DATE_H
#define DATE_H

#include<iostream>
using namespace std;

class Date
{
public:
    int d;
    int m;
    int y;

    Date(int dd, int mm, int yy) {
        d = dd;
        m = mm;
        y = yy;
    }

    void display() {
        cout << "Date: " << d << "/" << m << "/" << y << endl;
    }

};

#endif
