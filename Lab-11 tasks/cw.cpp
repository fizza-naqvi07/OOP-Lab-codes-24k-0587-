#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

// Task 1
class BadTypeEx {};

class Base {
public:
    virtual ~Base() {}
    virtual const std::type_info& type() const = 0;
};

template<typename T>
class Holder : public Base {
    T val;
public:
    Holder(const T& v) : val(v) {}
    T get() const { return val; }
    const std::type_info& type() const override { return typeid(T); }
};

class C {
    Base* d = nullptr;
public:
    ~C() { delete d; }

    template<typename T>
    void put(const T& v) {
        delete d;
        d = new Holder<T>(v);
    }

    template<typename T>
    T get() {
        if (!d || d->type() != typeid(T)) throw BadTypeEx();
        return static_cast<Holder<T>*>(d)->get();
    }
};

// Task 2
class DimEx {};

template<typename T>
class M {
    int r, c;
    vector<vector<T>> m;
public:
    M(int r, int c) : r(r), c(c), m(r, vector<T>(c)) {}

    T& at(int i, int j) {
        if (i < 0 || i >= r || j < 0 || j >= c) throw out_of_range("Idx");
        return m[i][j];
    }

    M operator+(const M& b) {
        if (r != b.r || c != b.c) throw DimEx();
        M res(r, c);
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                res.m[i][j] = m[i][j] + b.m[i][j];
        return res;
    }

    M operator*(const M& b) {
        if (c != b.r) throw DimEx();
        M res(r, b.c);
        for (int i = 0; i < r; i++)
            for (int j = 0; j < b.c; j++)
                for (int k = 0; k < c; k++)
                    res.m[i][j] += m[i][k] * b.m[k][j];
        return res;
    }

    void print() {
        for (auto& row : m) {
            for (auto& val : row) cout << val << " ";
            cout << endl;
        }
    }
};

// Task 3
class ArrEx {};

template<typename T>
class A {
    T* a;
    int s;
public:
    A(int s) : s(s) { a = new T[s]; }
    ~A() { delete[] a; }
    T& operator[](int i) {
        if (i < 0 || i >= s) throw ArrEx();
        return a[i];
    }
};

int main() {
    // Task 1
    C x;
    x.put<int>(42);
    try {
        cout << x.get<int>() << endl;
        cout << x.get<string>() << endl;
    } catch (...) {
        cout << "BadTypeEx\n";
    }

    // Task 2
    M<int> m1(2, 2), m2(2, 2);
    m1.at(0, 0) = 1; m1.at(0, 1) = 2;
    m1.at(1, 0) = 3; m1.at(1, 1) = 4;
    m2.at(0, 0) = 5; m2.at(0, 1) = 6;
    m2.at(1, 0) = 7; m2.at(1, 1) = 8;

    try {
        M<int> m3 = m1 + m2;
        m3.print();
        M<int> m4 = m1 * m2;
        m4.print();
    } catch (...) {
        cout << "DimEx\n";
    }

    // Task 3
    A<int> arr(3);
    arr[0] = 11; arr[1] = 22; arr[2] = 33;
    try {
        cout << arr[1] << endl;
        cout << arr[3] << endl;
    } catch (...) {
        cout << "ArrEx\n";
    }

    return 0;
}
