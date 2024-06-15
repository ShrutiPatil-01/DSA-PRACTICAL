#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Matrix {
private:
    int rows, cols;
    int mat[MAX_SIZE][MAX_SIZE];

public:
    Matrix(int m, int n) {
        rows = m;
        cols = n;
    }

    void input() {
        cout << "Enter elements of the matrix:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> mat[i][j];
            }
        }
    }

    void display() {
        cout << "Matrix:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix add(const Matrix& other) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.mat[i][j] = mat[i][j] + other.mat[i][j];
            }
        }
        return result;
    }

    Matrix subtract(const Matrix& other) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.mat[i][j] = mat[i][j] - other.mat[i][j];
            }
        }
        return result;
    }
};

int main() {
    int m, n;
    cout << "Enter the number of rows and columns of the matrices: ";
    cin >> m >> n;

    Matrix A(m, n);
    cout << "Enter matrix A:" << endl;
    A.input();

    Matrix B(m, n);
    cout << "Enter matrix B:" << endl;
    B.input();

    cout << "Matrix A:" << endl;
    A.display();
    cout << "Matrix B:" << endl;
    B.display();

    Matrix sum = A.add(B);
    cout << "Sum of matrices A and B:" << endl;
    sum.display();

    Matrix difference = A.subtract(B);
    cout << "Difference of matrices A and B:" << endl;
    difference.display();

    return 0;
}

