#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Matrix {
private:
    int mat[MAX_SIZE][MAX_SIZE];
    int rows, cols;
public:
    Matrix(int r, int c) {
        rows = r;
        cols = c;
    }
    void input() {
        cout << "Enter elements of the matrix:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << "Enter element at position (" << i << "," << j << "): ";
                cin >> mat[i][j];
            }
        }
    }
    void display() {
        cout << "Matrix:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
    void add(Matrix m2) {
        if (rows != m2.rows || cols != m2.cols) {
            cout << "Matrix addition not possible. Matrices have different dimensions." << endl;
            return;
        }
        cout << "Result of matrix addition:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << mat[i][j] + m2.mat[i][j] << " ";
            }
            cout << endl;
        }
    }
    void transpose() {
        cout << "Transpose of the matrix:" << endl;
        for (int j = 0; j < cols; ++j) {
            for (int i = 0; i < rows; ++i) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns of the matrices: ";
    cin >> rows >> cols;

    Matrix m1(rows, cols), m2(rows, cols);
    cout << "For Matrix 1:" << endl;
    m1.input();
    cout << "For Matrix 2:" << endl;
    m2.input();
    cout << "Matrix 1:" << endl;
    m1.display();
    cout << endl;
    cout << "Matrix 2:" << endl;
    m2.display();
    cout << endl;
    m1.add(m2);
    cout << endl;
    m1.transpose();
    cout << endl;
    m2.transpose();
    return 0;
}

