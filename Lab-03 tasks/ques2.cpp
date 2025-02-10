#include<iostream>
#include<cstdlib>
#include "date.h"
using namespace std;

int main(int argc, char* argv[]) {

    int d = atoi(argv[1]);
    int m = atoi(argv[2]);
    int y = atoi(argv[3]);

    Date date(d, m, y);

    date.display();

    return 0;
}
