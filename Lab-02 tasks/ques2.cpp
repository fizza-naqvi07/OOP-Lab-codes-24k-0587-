#include <iostream>
using namespace std;

void *AddElements(void *arr, int size, int v_add)
{
    int *intArr = static_cast<int *>(arr);
    for (int i = 0; i < size; ++i)
    {
        intArr[i] += v_add;
    }
    return nullptr;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int value = 5;
    AddElements(static_cast<void *>(arr), size, value);

    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
