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
#include <iostream>
#include <iomanip>

const int MAX_SIZE = 10;

// Function Prototypes
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, const std::string& name);
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void transposeMatrix(const int input[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int M, int N, int P);

int main() {
    // ==========================================
    // PART A: Transpose
    // ==========================================
    std::cout << "=== PART A: Transpose Matrix ===\n";
    int m1, n1;
    std::cout << "Enter number of rows: ";
    std::cin >> m1;
    std::cout << "Enter number of columns: ";
    std::cin >> n1;

    int A[MAX_SIZE][MAX_SIZE];
    inputMatrix(A, m1, n1, "Matrix A");

    int transposeRes[MAX_SIZE][MAX_SIZE];
    transposeMatrix(A, transposeRes, m1, n1);

    std::cout << "\nOriginal Matrix:\n";
    printMatrix(A, m1, n1);

    std::cout << "\nTransposed Matrix:\n";
    printMatrix(transposeRes, n1, m1);

    // ==========================================
    // PART B: Addition
    // ==========================================
    std::cout << "\n=== PART B: Matrix Addition ===\n";
    int m2, n2;
    std::cout << "Enter number of rows (M): ";
    std::cin >> m2;
    std::cout << "Enter number of columns (N): ";
    std::cin >> n2;

    int B1[MAX_SIZE][MAX_SIZE];
    int B2[MAX_SIZE][MAX_SIZE];
    int sumRes[MAX_SIZE][MAX_SIZE];

    inputMatrix(B1, m2, n2, "First Matrix");
    inputMatrix(B2, m2, n2, "Second Matrix");

    addMatrices(B1, B2, sumRes, m2, n2);

    std::cout << "\nSum Result:\n";
    printMatrix(sumRes, m2, n2);

    // ==========================================
    // PART C: Multiplication
    // ==========================================
    std::cout << "\n=== PART C: Matrix Multiplication ===\n";
    int M, N, P;
    std::cout << "Enter rows for Matrix A (M): ";
    std::cin >> M;
    std::cout << "Enter cols for A / rows for B (N): ";
    std::cin >> N;
    std::cout << "Enter cols for Matrix B (P): ";
    std::cin >> P;

    int C1[MAX_SIZE][MAX_SIZE];
    int C2[MAX_SIZE][MAX_SIZE];
    int prodRes[MAX_SIZE][MAX_SIZE];

    inputMatrix(C1, M, N, "Matrix A (M x N)");
    inputMatrix(C2, N, P, "Matrix B (N x P)");

    multiplyMatrices(C1, C2, prodRes, M, N, P);

    std::cout << "\nProduct Result (M x P):\n";
    printMatrix(prodRes, M, P);

    return 0;
}

// Reads elements for a matrix with element-by-element prompt syntax
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, const std::string& name) {
    std::cout << "\nEntering elements for " << name << ":\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "Enter element [" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }
}

// Displays matrix formatted in a grid using std::setw
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << std::setw(5) << matrix[i][j];
        }
        std::cout << "\n";
    }
}

// PART A Implementation: Transpose (M x N becomes N x M)
void transposeMatrix(const int input[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[j][i] = input[i][i] ? input[i][j] : input[i][j]; // mapped position: result[j][i] = input[i][j]
        }
    }
}

// PART B Implementation: Element-wise addition
void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// PART C Implementation: Matrix Multiplication (M x N) * (N x P) = (M x P)
void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int M, int N, int P) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < P; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < N; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

