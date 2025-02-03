#include <iostream>
using namespace std;

struct Subject
{
    string sub;
};

struct OuterStructure
{
    int id;
    Subject subArr[3];
};

int main()
{
    int n;
    cout << "Enter the number of outer structures: ";
    cin >> n;

    OuterStructure *arr = new OuterStructure[n];

    for (int i = 0; i < n; ++i)
    {
        cout << "Enter ID for outer structure " << i + 1 << ": ";
        cin >> arr[i].id;

        for (int j = 0; j < 3; ++j)
        {
            cout << "Enter subject " << j + 1 << " for outer structure " << i + 1 << ": ";
            cin >> arr[i].subArr[j].sub;
        }
    }

    cout << "\nOuter Structures:\n"
         << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << "ID: " << arr[i].id << "\n";
        for (int j = 0; j < 3; ++j)
        {
            cout << arr[i].subArr[j].sub << "\n";
        }
        cout << endl;
    }

    delete[] arr;

    return 0;
}
