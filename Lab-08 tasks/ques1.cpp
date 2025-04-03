#include<iostream>
using namespace std;

class Number {
    int num;
public:
    Number(int n) : num(n) {}

    Number& operator--() { 
        num *= 4;
        return *this;
    }

    Number operator--(int) { 
        Number temp = *this;
        num /= 4;
        return temp;
    }

    void display() { 
        cout << num << endl; 
    }
};

int main() {
    Number n(8);
    --n;
    n.display();
    n--;
    n.display();
    return 0;
}
