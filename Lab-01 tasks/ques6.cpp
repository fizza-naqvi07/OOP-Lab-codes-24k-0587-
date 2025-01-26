#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    string name;
    float t1, t2, t3, t4, t5, avg;

    cout << "Enter your name and your five test scores: " << endl;
    cin >> name >> t1 >> t2 >> t3 >> t4 >> t5;

    avg = (t1 + t2 + t3 + t4 + t5) / 5;

    cout << fixed << setprecision(2);
    cout << "Student name: " << name << endl;
    cout << "Test scores: " << t1 << ", " << t2 << ", " << t3 << ", " << t4 << ", " << t5 << endl;
    cout << "Average test score: " << avg << endl;

    return 0;
}