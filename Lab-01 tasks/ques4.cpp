#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float w_kg;
    float w_p;
    cout << "Enter your weight in kilograms: " << endl;
    cin >> w_kg;
    w_p = w_kg * 2.2;
    cout << fixed << setprecision(2);
    cout << "Your weight in kilograms: " << w_kg << endl;
    cout << "Your weight in pounds: " << w_p << endl;
    return 0;
}