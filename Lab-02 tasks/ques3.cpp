#include <iostream>
using namespace std;

void ResizeArray(int *&arr, int &size, int n_size)
{
    int *n_arr = new int[n_size];
    for (int i = 0; i < size; ++i)
    {
        n_arr[i] = arr[i];
    }
    delete[] arr;
    arr = n_arr;
    size = n_size;
}

int main()
{
    int size = 5;
    int *arr = new int[size];
    int count = 0;
    int val;

    while (true)
    {
        cout << "Enter a number (or 0 to stop): ";
        cin >> val;
        if (val == 0)
            break;

        if (count >= size)
        {
            ResizeArray(arr, size, size * 2);
        }
        arr[count++] = val;
    }

    ResizeArray(arr, size, count);

    cout << "Elements in the array: ";
    for (int i = 0; i < count; ++i)
    {
        cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}
