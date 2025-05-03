#include <iostream>
using namespace std;

class StackEx {};

template<typename T>
class Stack {
    T* data;
    int topIdx, cap;
public:
    Stack(int s) : cap(s), topIdx(-1) {
        data = new T[cap];
    }
    ~Stack() {
        delete[] data;
    }

    void push(T val) {
        if (topIdx + 1 == cap) return;
        data[++topIdx] = val;
    }

    void pop() {
        if (topIdx == -1) throw StackEx();
        topIdx--;
    }

    T top() {
        if (topIdx == -1) throw StackEx();
        return data[topIdx];
    }

    bool empty() {
        return topIdx == -1;
    }
};

int main() {
    Stack<int> s(5);
    try {
        s.push(10);
        s.push(20);
        cout << "Top: " << s.top() << endl;
        s.pop();
        cout << "Top after pop: " << s.top() << endl;
        s.pop();
        s.pop(); // will throw
    } catch (...) {
        cout << "StackEx\n";
    }
    return 0;
}
