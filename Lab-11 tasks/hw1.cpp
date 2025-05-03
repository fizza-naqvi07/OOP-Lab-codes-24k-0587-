#include <iostream>
using namespace std;

template<typename T>
class B {
protected:
    T a, b;
public:
    B(T x, T y) : a(x), b(y) {}
    T mul() {
        return a * b;
    }
};

template<typename T>
class D : public B<T> {
    T c, d;
public:
    D(T x, T y, T z, T w) : B<T>(x, y), c(z), d(w) {}
    T mul2() {
        return c * d;
    }
};

int main() {
    D<int> obj(2, 3, 4, 5);
    cout << "Base mul: " << obj.mul() << endl;
    cout << "Derived mul: " << obj.mul2() << endl;
    return 0;
}
