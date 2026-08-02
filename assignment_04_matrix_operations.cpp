// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void readMatrix(int matrix[10][10], int rows, int cols)
{
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            cout << "Enter element [" << r << "][" << c << "]: ";
            cin >> matrix[r][c];
        }
    }
}

void displayMatrix(const int matrix[10][10], int rows, int cols)
{
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            cout << setw(4) << matrix[r][c];
        }
        cout << endl;
    }
}

void transposeMatrix(const int source[10][10], int target[10][10], int rows, int cols)
{
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            target[c][r] = source[r][c];
        }
    }
}

void addMatrices(const int a[10][10], const int b[10][10], int result[10][10], int rows, int cols)
{
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            result[r][c] = a[r][c] + b[r][c];
        }
    }
}

void multiplyMatrices(const int a[10][10], const int b[10][10], int result[10][10], int rowsA, int colsA, int colsB)
{
    for (int r = 0; r < rowsA; ++r)
    {
        for (int c = 0; c < colsB; ++c)
        {
            result[r][c] = 0;
            for (int k = 0; k < colsA; ++k)
            {
                result[r][c] += a[r][k] * b[k][c];
            }
        }
    }
}

int main()
{
    int matrixA[10][10];
    int matrixB[10][10];
    int matrixC[10][10];
    int transpose[10][10];
    int rowsA, colsA, rowsB, colsB;

    cout << "PART A - Transpose" << endl;
    cout << "Enter number of rows: ";
    cin >> rowsA;
    cout << "Enter number of columns: ";
    cin >> colsA;
    readMatrix(matrixA, rowsA, colsA);

    transposeMatrix(matrixA, transpose, rowsA, colsA);

    cout << "\nOriginal Matrix:" << endl;
    displayMatrix(matrixA, rowsA, colsA);
    cout << "\nTransposed Matrix:" << endl;
    displayMatrix(transpose, colsA, rowsA);

    cout << "\nPART B - Matrix Addition" << endl;
    cout << "Enter number of rows: ";
    cin >> rowsA;
    cout << "Enter number of columns: ";
    cin >> colsA;
    readMatrix(matrixA, rowsA, colsA);
    readMatrix(matrixB, rowsA, colsA);

    addMatrices(matrixA, matrixB, matrixC, rowsA, colsA);

    cout << "\nSum Matrix:" << endl;
    displayMatrix(matrixC, rowsA, colsA);

    cout << "\nPART C - Matrix Multiplication" << endl;
    cout << "Enter number of rows for matrix A: ";
    cin >> rowsA;
    cout << "Enter number of columns for matrix A: ";
    cin >> colsA;
    cout << "Enter number of rows for matrix B: ";
    cin >> rowsB;
    cout << "Enter number of columns for matrix B: ";
    cin >> colsB;

    if (colsA != rowsB)
    {
        cout << "Error: Columns of A must equal rows of B for multiplication." << endl;
        return 0;
    }

    readMatrix(matrixA, rowsA, colsA);
    readMatrix(matrixB, rowsB, colsB);

    multiplyMatrices(matrixA, matrixB, matrixC, rowsA, colsA, colsB);

    cout << "\nProduct Matrix:" << endl;
    displayMatrix(matrixC, rowsA, colsB);

    return 0;
}

