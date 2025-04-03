#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BigInteger {
private:
    vector<int> digits;
    bool isNegative;

    void removeLeadingZeros() {
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
        if (digits.size() == 1 && digits[0] == 0) {
            isNegative = false;
        }
    }
public:
    BigInteger() : isNegative(false) {}
    BigInteger(const string &num) {
        isNegative = (num[0] == '-');
        for (int i = num.size() - 1; i >= (isNegative ? 1 : 0); i--) {
            digits.push_back(num[i] - '0');
        }
        removeLeadingZeros();
    }
    BigInteger operator+(const BigInteger &other) const {
        if (isNegative == other.isNegative) {
            BigInteger result;
            result.isNegative = isNegative;
            int carry = 0, sum;
            size_t maxSize = (digits.size() > other.digits.size()) ? digits.size() : other.digits.size();
            for (size_t i = 0; i < maxSize || carry; i++) {
                sum = carry;
                if (i < digits.size()) sum += digits[i];
                if (i < other.digits.size()) sum += other.digits[i];
                result.digits.push_back(sum % 10);
                carry = sum / 10;
            }
            return result;
        }
        return *this - (-other);
    }
    BigInteger operator-() const {
        BigInteger temp = *this;
        temp.isNegative = !temp.isNegative;
        return temp;
    }
    BigInteger operator-(const BigInteger &other) const {
        if (isNegative != other.isNegative) return *this + (-other);
        if (*this < other) return -(other - *this);
        BigInteger result;
        result.isNegative = isNegative;
        int borrow = 0, diff;
        for (size_t i = 0; i < digits.size(); i++) {
            diff = digits[i] - borrow - (i < other.digits.size() ? other.digits[i] : 0);
            borrow = (diff < 0);
            result.digits.push_back((diff + 10) % 10);
        }
        result.removeLeadingZeros();
        return result;
    }
    bool operator<(const BigInteger &other) const {
        if (isNegative != other.isNegative) return isNegative;
        if (digits.size() != other.digits.size()) {
            return (digits.size() < other.digits.size()) ^ isNegative;
        }
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] != other.digits[i]) return (digits[i] < other.digits[i]) ^ isNegative;
        }
        return false;
    }
    bool operator==(const BigInteger &other) const {
        return digits == other.digits && isNegative == other.isNegative;
    }
    bool operator!=(const BigInteger &other) const { return !(*this == other); }
    bool operator>(const BigInteger &other) const { return other < *this; }
    bool operator<=(const BigInteger &other) const { return !(other < *this); }
    bool operator>=(const BigInteger &other) const { return !(*this < other); }
    friend ostream& operator<<(ostream &os, const BigInteger &num) {
        if (num.isNegative) os << "-";
        for (int i = num.digits.size() - 1; i >= 0; i--) {
            os << num.digits[i];
        }
        return os;
    }
    friend istream& operator>>(istream &is, BigInteger &num) {
        string input;
        is >> input;
        num = BigInteger(input);
        return is;
    }
};

int main() {
    BigInteger a, b;
    cin >> a >> b;
    cout << "Sum: " << (a + b) << endl;
    cout << "Difference: " << (a - b) << endl;
    cout << "Comparison (a < b): " << (a < b) << endl;
    return 0;
}
