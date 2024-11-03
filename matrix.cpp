#include <iostream>
#include <fstream> // Include for file handling
using namespace std;

const int SIZE = 4; // Global variable for matrix size

class Matrix {
private:
    int data[SIZE][SIZE]; // 2D array for matrix data (using int for simplicity)

public:
    // 1. Read values from stdin or a file into a matrix
    void readFromStdin(); // Modified to read from a file
    // 2. Display a matrix
    void display() const;
    // 3. Add two matrices (operator overloading for +)
    Matrix operator+(const Matrix& other) const;
    // 4. Multiply two matrices (operator overloading for *)
    Matrix operator*(const Matrix& other) const;
    // 5. Compute the sum of matrix diagonal elements
    int sumOfDiagonals() const;
    // 6. Swap matrix rows
    void swapRows(int row1, int row2);
};

void Matrix::readFromStdin() {
    // Read matrix data from input
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cin >> data[i][j]; // Read data for the matrix
        }
    }
}

void Matrix::display() const {
    // Display the matrix in a user-friendly format
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

Matrix Matrix::operator+(const Matrix& other) const {
    Matrix result; // Create a new matrix for the result
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j]; // Add corresponding elements
        }
    }
    return result; // Return the resulting matrix
}

Matrix Matrix::operator*(const Matrix& other) const {
    Matrix result; // Create a new matrix for the result
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result.data[i][j] = 0; // Initialize the result cell
            for (int k = 0; k < SIZE; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j]; // Multiply and sum
            }
        }
    }
    return result; // Return the resulting matrix
}

int Matrix::sumOfDiagonals() const {
    int sum = 0;
    // Sum of the main diagonal
    for (int i = 0; i < SIZE; ++i) {
        sum += data[i][i]; // Main diagonal elements
    }
    // Sum of the secondary diagonal
    for (int i = 0; i < SIZE; ++i) {
        sum += data[i][SIZE - 1 - i]; // Secondary diagonal elements
    }
    return sum; // Return total sum of diagonals
}

void Matrix::swapRows(int row1, int row2) {
    if (row1 >= 0 && row1 < SIZE && row2 >= 0 && row2 < SIZE) {
        for (int j = 0; j < SIZE; ++j) {
            swap(data[row1][j], data[row2][j]); // Swap the rows
        }
    }
}

int main() {
    // Example usage:
    Matrix mat1;
    cout << "Enter values for Matrix 1:" << endl;
    mat1.readFromStdin();
    cout << "Matrix 1:" << endl;
    mat1.display();
    
    Matrix mat2;
    cout << "Enter values for Matrix 2:" << endl;
    mat2.readFromStdin();
    cout << "Matrix 2:" << endl;
    mat2.display();
    
    Matrix sum = mat1 + mat2;
    cout << "Sum of matrices:" << endl;
    sum.display();
    
    Matrix product = mat1 * mat2;
    cout << "Product of matrices:" << endl;
    product.display();
    
    cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;
    mat1.swapRows(0, 2);
    cout << "Matrix 1 after swapping rows:" << endl;
    mat1.display();
    
    return 0;
}

