#include <iostream>
#include<math.h>
using namespace std;

class Polynomial {
private:
    int deg;
    double* coeff;

public:
    Polynomial() {
        deg = 0;
        coeff = new double[1]{0};
    }

    Polynomial(int d, double* c) {
        deg = d;
        coeff = new double[d + 1];
        for (int i = 0; i <= deg; ++i) {
            coeff[i] = c[i];
        }
    }

    Polynomial(const Polynomial& p) {
        deg = p.deg;
        coeff = new double[deg + 1];
        for (int i = 0; i <= deg; ++i) {
            coeff[i] = p.coeff[i];
        }
    }

    Polynomial(Polynomial&& p) noexcept {
        deg = p.deg;
        coeff = p.coeff;
        p.coeff = nullptr;
    }

    ~Polynomial() {
        delete[] coeff;
    }

    int getDeg() const {
        return deg;
    }

    double evaluate(double x) const {
        double res = 0;
        for (int i = 0; i <= deg; ++i) {
            res += coeff[i] * pow(x, i);
        }
        return res;
    }

    Polynomial add(const Polynomial& p) const {
        int newDeg = (deg > p.deg) ? deg : p.deg;
        double* newCoeff = new double[newDeg + 1]{0};

        for (int i = 0; i <= deg; ++i) {
            newCoeff[i] = coeff[i];
        }

        for (int i = 0; i <= p.deg; ++i) {
            newCoeff[i] += p.coeff[i];
        }

        return Polynomial(newDeg, newCoeff);
    }

    Polynomial multiply(const Polynomial& p) const {
        int newDeg = deg + p.deg;
        double* newCoeff = new double[newDeg + 1]{0};

        for (int i = 0; i <= deg; ++i) {
            for (int j = 0; j <= p.deg; ++j) {
                newCoeff[i + j] += coeff[i] * p.coeff[j];
            }
        }

        return Polynomial(newDeg, newCoeff);
    }

    void print() const {
        for (int i = deg; i >= 0; --i) {
            if (i != deg && coeff[i] >= 0) {
                cout << "+";
            }
            cout << coeff[i];
            if (i > 0) {
                cout << "x^" << i << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    int deg;
    cout << "Enter degree of first polynomial: ";
    cin >> deg;

    double* c1 = new double[deg + 1];
    cout << "Enter coefficients for first polynomial: ";
    for (int i = 0; i <= deg; i++) {
        cin >> c1[i];
    }

    Polynomial p1(deg, c1);

    cout << "Enter degree of second polynomial: ";
    cin >> deg;

    double* c2 = new double[deg + 1];
    cout << "Enter coefficients for second polynomial: ";
    for (int i = 0; i <= deg; i++) {
        cin >> c2[i];
    }

    Polynomial p2(deg, c2);

    cout << "\nFirst Polynomial: ";
    p1.print();

    cout << "\nSecond Polynomial: ";
    p2.print();

    Polynomial p3 = p1.add(p2);
    cout << "\nSum of Polynomials: ";
    p3.print();

    Polynomial p4 = p1.multiply(p2);
    cout << "\nProduct of Polynomials: ";
    p4.print();

    double x;
    cout << "\nEnter x value to evaluate the first polynomial: ";
    cin >> x;
    cout << "Evaluation result: " << p1.evaluate(x) << endl;

    return 0;
}
