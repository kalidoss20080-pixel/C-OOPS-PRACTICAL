#include <iostream>
#include <cassert>
using namespace std;

class Matrix
{
private:
    int data[2][2];

public:

    // Parameterized Constructor
    Matrix(int x = 0, int y = 0, int z = 0, int w = 0)
    {
        data[0][0] = x;
        data[0][1] = y;
        data[1][0] = z;
        data[1][1] = w;
    }

    // Overloading + operator
    Matrix operator+(const Matrix &obj) const
    {
        Matrix temp;

        for (int row = 0; row < 2; row++)
        {
            for (int col = 0; col < 2; col++)
            {
                temp.data[row][col] = data[row][col] + obj.data[row][col];
            }
        }

        return temp;
    }

    // Overloading * operator
    Matrix operator*(const Matrix &obj) const
    {
        Matrix temp;

        for (int row = 0; row < 2; row++)
        {
            for (int col = 0; col < 2; col++)
            {
                temp.data[row][col] = 0;

                for (int n = 0; n < 2; n++)
                {
                    temp.data[row][col] += data[row][n] * obj.data[n][col];
                }
            }
        }

        return temp;
    }

    // Overloading [] operator
    int* operator[](int pos)
    {
        return data[pos];
    }

    // Overloading << operator
    friend ostream& operator<<(ostream &output, const Matrix &obj)
    {
        for (int row = 0; row < 2; row++)
        {
            for (int col = 0; col < 2; col++)
            {
                output << obj.data[row][col] << " ";
            }

            output << endl;
        }

        return output;
    }
};

int main()
{
    Matrix A(2, 3, 4, 5);
    Matrix B(1, 2, 3, 4);

    Matrix addition = A + B;
    Matrix multiplication = A * B;

    // Unit Testing for addition
    assert(addition[0][0] == 3);
    assert(addition[0][1] == 5);
    assert(addition[1][0] == 7);
    assert(addition[1][1] == 9);

    // Unit Testing for multiplication
    assert(multiplication[0][0] == 11);
    assert(multiplication[0][1] == 16);
    assert(multiplication[1][0] == 19);
    assert(multiplication[1][1] == 28);

    cout << "========== MATRIX DETAILS ==========" << endl;

    cout << "\nFirst Matrix (A):" << endl;
    cout << A;

    cout << "\nSecond Matrix (B):" << endl;
    cout << B;

    cout << "\n========== MATRIX OPERATIONS ==========" << endl;

    cout << "\nResult of Matrix Addition (A + B):" << endl;
    cout << addition;

    cout << "\nResult of Matrix Multiplication (A * B):" << endl;
    cout << multiplication;

    cout << "\n========== UNIT TEST RESULTS ==========" << endl;
    cout << "Addition Test: Passed" << endl;
    cout << "Multiplication Test: Passed" << endl;

    // Matrix Multiplication Verification
    bool valid = true;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int expected = 0;

            for (int k = 0; k < 2; k++)
            {
                expected += A[i][k] * B[k][j];
            }

            if (multiplication[i][j] != expected)
            {
                valid = false;
            }
        }
    }

    cout << "Independent Multiplication Verification: "
         << (valid ? "Successful" : "Failed") << endl;

    cout << "\nAll Matrix Operations Completed Successfully!" << endl;

    return 0;
}