#include <iostream>
using namespace std;

int main()
{
    int n, sum = 0;
    int arr[100];

    cout << "Enter the number if elements you want to add in the array: " << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << " : " << endl;
        cin >> arr[i];
    }

    int *ptr = arr;
    for (int i = 0; i < n; i++)
    {
        sum += *(ptr + i);
    }
    cout << "Sum of the elements in the array is: " << sum << endl;

    return 0;
}