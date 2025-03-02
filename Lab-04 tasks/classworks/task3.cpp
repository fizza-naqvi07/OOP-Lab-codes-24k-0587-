#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int sz;

public:
    DynamicArray() : arr(nullptr), sz(0) {}

    DynamicArray(int n) : sz(n) {
        arr = new int[sz]();
    }

    DynamicArray(const DynamicArray& other) : sz(other.sz) {
        arr = new int[sz];
        for (int i = 0; i < sz; ++i) {
            arr[i] = other.arr[i];
        }
    }

    DynamicArray(DynamicArray&& other) noexcept : arr(other.arr), sz(other.sz) {
        other.arr = nullptr;
        other.sz = 0;
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] arr;
            sz = other.sz;
            arr = new int[sz];
            for (int i = 0; i < sz; ++i) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this != &other) {
            delete[] arr;
            arr = other.arr;
            sz = other.sz;
            other.arr = nullptr;
            other.sz = 0;
        }
        return *this;
    }

    ~DynamicArray() {
        delete[] arr;
    }

    int size() const {
        return sz;
    }

    int& at(int index) {
        return arr[index];
    }

    const int& at(int index) const {
        return arr[index];
    }

    void resize(int newSize) {
        int* newArr = new int[newSize]();
        for (int i = 0; i < (newSize < sz ? newSize : sz); ++i) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        sz = newSize;
    }
};

int main() {
    int n;
    cout << "Enter the size of the dynamic array: ";
    cin >> n;

    DynamicArray arr(n);
    for (int i = 0; i < n; ++i) {
        cout << "Enter element " << i << ": ";
        cin >> arr.at(i);
    }

    cout << "Array elements: ";
    for (int i = 0; i < n; ++i) {
        cout << arr.at(i) << " ";
    }
    cout << endl;

    cout << "Enter new size to resize the array: ";
    cin >> n;
    arr.resize(n);

    cout << "Resized array elements: ";
    for (int i = 0; i < n; ++i) {
        cout << arr.at(i) << " ";
    }
    cout << endl;

    return 0;
}
