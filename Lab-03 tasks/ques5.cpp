#include <iostream>
#include <cstdlib>
#include "Book.h"
using namespace std;

int main(int argc, char *argv[])
{
    Book books[5] = {
        Book(argv[1], argv[2], argv[3], argv[4]),
        Book(argv[5], argv[6], argv[7], argv[8]),
        Book(argv[9], argv[10], argv[11], argv[12]),
        Book(argv[13], argv[14], argv[15], argv[16]),
        Book(argv[17], argv[18], argv[19], argv[20])};

    for (int i = 0; i < 5; ++i)
    {
        cout << books[i].getBookInfo() << endl
             << endl;
    }

    return 0;
}
