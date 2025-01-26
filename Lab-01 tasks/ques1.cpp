#include<iostream>
using namespace std;

int main() {
    int arr[20];
    int h1 = -1, h2 = -1;

    cout << "Enter 20 elements: " << endl;
    for (int i = 0; i < 20; i++) {
        cin >> arr[i];
    }

    int* ptr = arr;

    for (int i = 0; i < 20; i++) {
        if (*(ptr + i) > h1) {
            h2 = h1;
            h1 = *(ptr + i);
        }
        else if (*(ptr + i) > h2 && *(ptr + i) != h1) {
            h2 = *(ptr + i);
        }
    }

    if (h2 == -1) {
        cout << "There is no second highest number!" << endl;
    } else {
        cout << "The second highest number in the array is: " << h2 << endl;
    }

    return 0;
}
