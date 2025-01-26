#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    string m_name;
    float adult_tp, child_tp, gross_p, gross_A, don_A, net;
    int num_a, num_c, tot_t;

    cout << "Enter movie's name: " << endl;
    cin >> m_name;
    cout << "Enter the price for the ticket (adult): " << endl;
    cin >> adult_tp;
    cout << "Enter the price for the ticket (child): " << endl;
    cin >> child_tp;
    cout << "Enter the number of tickets sold (adult): " << endl;
    cin >> num_a;
    cout << "Enter the number of tickets sold (child): " << endl;
    cin >> num_c;
    cout << "Enter the percentage of the gross amount to be donated: " << endl;
    cin >> gross_p;

    tot_t = num_a + num_c;
    gross_A = num_a * adult_tp + num_c * child_tp;
    don_A = (gross_p / 100) * gross_A;
    net = gross_A - don_A;

    cout << fixed << setprecision(2);
    cout << left << setw(40) << "Movie name:" << setw(10) << m_name << endl;
    cout << left << setw(40) << "Number of tickets sold:" << setw(10) << tot_t << endl;
    cout << left << setw(40) << "Gross amount:" << setw(10) << gross_A << endl;
    cout << left << setw(40) << "Percentage of gross amount donated:" << setw(1) << gross_p << "%" << endl;
    cout << left << setw(40) << "Amount donated:" << setw(10) << don_A << endl;
    cout << left << setw(40) << "Net sale:" << setw(10) << net << endl;

    return 0;
}