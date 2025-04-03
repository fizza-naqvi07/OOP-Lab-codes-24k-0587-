#include <iostream>
#include <vector>
using namespace std;

class Polynomial;

class PolynomialUtils {
public:
    static int evaluate(const Polynomial &p, int x);
    static Polynomial derivative(const Polynomial &p);
};

class Polynomial {
private:
    vector<int> coefficients;
    void trim() {
        while (!coefficients.empty() && coefficients.back() == 0) {
            coefficients.pop_back();
        }
    }
public:
    Polynomial() {}
    Polynomial(const vector<int>& coeffs) : coefficients(coeffs) {
        trim();
    }
    Polynomial operator+(const Polynomial &other) const {
        vector<int> result_coeffs(max(coefficients.size(), other.coefficients.size()), 0);
        for (size_t i = 0; i < coefficients.size(); i++) result_coeffs[i] += coefficients[i];
        for (size_t i = 0; i < other.coefficients.size(); i++) result_coeffs[i] += other.coefficients[i];
        return Polynomial(result_coeffs);
    }
    Polynomial operator-(const Polynomial &other) const {
        vector<int> result_coeffs(max(coefficients.size(), other.coefficients.size()), 0);
        for (size_t i = 0; i < coefficients.size(); i++) result_coeffs[i] += coefficients[i];
        for (size_t i = 0; i < other.coefficients.size(); i++) result_coeffs[i] -= other.coefficients[i];
        return Polynomial(result_coeffs);
    }
    Polynomial operator*(const Polynomial &other) const {
        vector<int> result_coeffs(coefficients.size() + other.coefficients.size() - 1, 0);
        for (size_t i = 0; i < coefficients.size(); i++) {
            for (size_t j = 0; j < other.coefficients.size(); j++) {
                result_coeffs[i + j] += coefficients[i] * other.coefficients[j];
            }
        }
        return Polynomial(result_coeffs);
    }
    friend ostream& operator<<(ostream &os, const Polynomial &p) {
        bool first = true;
        for (int i = p.coefficients.size() - 1; i >= 0; i--) {
            if (p.coefficients[i] != 0) {
                if (!first && p.coefficients[i] > 0) os << " + ";
                if (p.coefficients[i] < 0) os << " - ";
                if (abs(p.coefficients[i]) != 1 || i == 0) os << abs(p.coefficients[i]);
                if (i > 0) os << "x";
                if (i > 1) os << "^" << i;
                first = false;
            }
        }
        if (first) os << "0";
        return os;
    }
    friend class PolynomialUtils;
};

int PolynomialUtils::evaluate(const Polynomial &p, int x) {
    int result = 0, power = 1;
    for (size_t i = 0; i < p.coefficients.size(); i++) {
        result += p.coefficients[i] * power;
        power *= x;
    }
    return result;
}

Polynomial PolynomialUtils::derivative(const Polynomial &p) {
    if (p.coefficients.size() <= 1) return Polynomial();
    vector<int> result_coeffs(p.coefficients.size() - 1);
    for (size_t i = 1; i < p.coefficients.size(); i++) {
        result_coeffs[i - 1] = i * p.coefficients[i];
    }
    return Polynomial(result_coeffs);
}

int main() {
    Polynomial p1({3, 2, 1});
    Polynomial p2({1, 0, -1});
    cout << p1 + p2 << endl;
    cout << p1 - p2 << endl;
    cout << p1 * p2 << endl;
    cout << PolynomialUtils::evaluate(p1, 2) << endl;
    cout << PolynomialUtils::derivative(p1) << endl;
    return 0;
}
