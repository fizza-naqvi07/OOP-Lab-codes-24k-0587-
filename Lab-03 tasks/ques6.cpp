#include <iostream>
#include <cstdlib>
using namespace std;

class Matrix
{
private:
    int rows, cols;
    int elements[10][10];

public:
    Matrix(int r, int c) : rows(r), cols(c) {}

    int getRows()
    {
        return rows;
    }

    int getCols()
    {
        return cols;
    }

    void setElement(int i, int j, int value)
    {
        if (i >= 0 && i < rows && j >= 0 && j < cols)
        {
            elements[i][j] = value;
        }
    }

    Matrix add(Matrix &other)
    {
        if (rows != other.rows || cols != other.cols)
        {
            cout << "Matrices cannot be added" << endl;
            return Matrix(0, 0);
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.elements[i][j] = elements[i][j] + other.elements[i][j];
            }
        }
        return result;
    }

    Matrix multiply(Matrix &other)
    {
        if (cols != other.rows)
        {
            cout << "Matrices cannot be multiplied" << endl;
            return Matrix(0, 0);
        }
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < other.cols; j++)
            {
                result.elements[i][j] = 0;
                for (int k = 0; k < cols; k++)
                {
                    result.elements[i][j] += elements[i][k] * other.elements[k][j];
                }
            }
        }
        return result;
    }

    void display() const
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << elements[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main(int argc, char *argv[])
{
    if (argc < 5)
    {
        cout << "Usage: " << argv[0] << " <rows1> <cols1> <rows2> <cols2> <elements>" << endl;
        return 1;
    }

    int rows1 = atoi(argv[1]);
    int cols1 = atoi(argv[2]);
    int rows2 = atoi(argv[3]);
    int cols2 = atoi(argv[4]);

    int totalElements1 = rows1 * cols1;
    int totalElements2 = rows2 * cols2;
    if ((argc - 5) != (totalElements1 + totalElements2))
    {
        cout << "Invalid number of elements provided" << endl;
        return 1;
    }

    Matrix m1(rows1, cols1);
    Matrix m2(rows2, cols2);

    int index = 5;
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {
            m1.setElement(i, j, atoi(argv[index++]));
        }
    }

    for (int i = 0; i < rows2; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            m2.setElement(i, j, atoi(argv[index++]));
        }
    }

    cout << "Matrix 1:" << endl;
    m1.display();
    cout << "Matrix 2:" << endl;
    m2.display();

    Matrix sum = m1.add(m2);
    if (sum.getRows() != 0 && sum.getCols() != 0)
    {
        cout << "Sum of the matrices:" << endl;
        sum.display();
    }

    Matrix product = m1.multiply(m2);
    if (product.getRows() != 0 && product.getCols() != 0)
    {
        cout << "Product of the matrices:" << endl;
        product.display();
    }

    return 0;
}
