#include <iostream>
using namespace std;

class Matrix {
private:
    int r;
    int c;
    double** mat;

public:
    Matrix() {
        r = 0;
        c = 0;
        mat = nullptr;
    }

    Matrix(int rows, int cols) {
        r = rows;
        c = cols;

        mat = new double*[r];
        for (int i = 0; i < r; i++) {
            mat[i] = new double[c](); 
        }
    }

    Matrix(const Matrix& obj) {
        r = obj.r;
        c = obj.c;

        mat = new double*[r];
        for (int i = 0; i < r; i++) {
            mat[i] = new double[c];
            for (int j = 0; j < c; j++) {
                mat[i][j] = obj.mat[i][j];
            }
        }
    }

    Matrix(Matrix&& obj) noexcept : r(obj.r), c(obj.c), mat(obj.mat) {
        obj.r = 0;
        obj.c = 0;
        obj.mat = nullptr;
    }

    ~Matrix() {
        for (int i = 0; i < r; i++) {
            delete[] mat[i];
        }
        delete[] mat;
    }

    int getRows() const {
        return r;
    }

    int getCols() const {
        return c;
    }

    double& at(int row, int col) {
        return mat[row][col];
    }

    void fill(double val) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                mat[i][j] = val;
            }
        }
    }

    Matrix transpose() const {
        Matrix transposed(c, r);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                transposed.mat[j][i] = mat[i][j];
            }
        }
        return transposed;
    }

    void print() const {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int r, c;

    cout << "Enter the number of rows: " << endl;
    cin >> r;
    cout << "Enter the number of columns: " << endl;
    cin >> c;

    Matrix m(r, c);

    cout << "Enter the elements of the matrix: " << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << "Enter the element at mat[" << i << "][" << j << "]: " << endl;
            cin >> m.at(i, j);
        }
    }

    cout << "\nOriginal Matrix:\n" << endl;
    m.print();

    Matrix transposed = m.transpose();
    cout << "\nTransposed Matrix:\n" << endl;
    transposed.print();

    return 0;
}
