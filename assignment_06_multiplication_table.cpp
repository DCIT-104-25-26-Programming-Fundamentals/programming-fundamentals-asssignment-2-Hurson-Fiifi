// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// Write a C++ program that generates multiplication tables using loops
// and functions.
//
// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Print the multiplication table for that number from 1 to 12.
//
// Expected output (if user enters 5):
//
//   Multiplication Table for 5:
//   5  x  1  =  5
//   5  x  2  =  10
//   5  x  3  =  15
//   ...
//   5  x  12 =  60
//
// -----------------------------------------------------------------------------
// PART B — Bonus: Tables from 1 to N
// -----------------------------------------------------------------------------
// - Ask the user to enter a number N.
// - Print the full multiplication table for every number from 1 to N.
// - Add a separator line (e.g. "---") between each table.
//
// Expected output (if user enters 3):
//
//   Multiplication Table for 1:
//   1  x  1  =  1
//   ...
//   1  x  12 =  12
//   ---------------------------
//   Multiplication Table for 2:
//   2  x  1  =  2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - N must be a positive integer. If the user enters an invalid value,
//   print an error message and stop.
// - Each part must be in its own function (see scaffold below).
// - Complete Part A before attempting Part B.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

#include <iostream>

// Function Prototypes
void printSingleTable(int num);
void printTablesUpToN(int n);

int main() {
    // ==========================================
    // PART A: Single Table
    // ==========================================
    std::cout << "=== PART A: Single Multiplication Table ===\n";
    int singleNum;
    std::cout << "Enter a number: ";
    std::cin >> singleNum;

    // Requirement: Must be a positive integer
    if (singleNum <= 0) {
        std::cout << "Error: Number must be a positive integer." << std::endl;
        return 1;
    }

    printSingleTable(singleNum);
    std::cout << "\n";

    // ==========================================
    // PART B: Bonus - Tables from 1 to N
    // ==========================================
    std::cout << "=== PART B: Tables from 1 to N ===\n";
    int maxN;
    std::cout << "Enter a number N: ";
    std::cin >> maxN;

    // Requirement: Must be a positive integer
    if (maxN <= 0) {
        std::cout << "Error: N must be a positive integer." << std::endl;
        return 1;
    }

    printTablesUpToN(maxN);

    return 0;
}

/**
 * PART A: Prints the multiplication table for a single number from 1 to 12.
 */
void printSingleTable(int num) {
    std::cout << "Multiplication Table for " << num << ":\n";
    for (int i = 1; i <= 12; ++i) {
        std::cout << num << " x " << i << " = " << (num * i) << "\n";
    }
}

/**
 * PART B: Prints multiplication tables for every number from 1 to N.
 * Uses printSingleTable() to print each table with separators in between.
 */
void printTablesUpToN(int n) {
    for (int i = 1; i <= n; ++i) {
        printSingleTable(i);
        if (i < n) {
            std::cout << "-----------------------------------\n";
        }
    }
}