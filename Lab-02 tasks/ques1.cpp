#include <iostream>
#include <cstdlib>
using namespace std;

int CalculateSum(int* arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += *(arr + i);
    }
    return sum;
}

int main(int argc, char* argv[]) {

    int n = argc - 1;  
    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = atoi(argv[i + 1]);
    }

    int sum = CalculateSum(arr, n);
    cout << "Sum of the elements in the array is " << sum << endl;

    return 0;
}
