// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

#include <iostream>

// Function Prototypes
void printFibonacciTerms(int n);
bool isFibonacciNumber(long long num);

int main() {
    // ==========================================
    // PART A: Print First N Terms
    // ==========================================
    std::cout << "=== PART A: First N Fibonacci Terms ===\n";
    int n;
    std::cout << "How many terms? ";
    std::cin >> n;

    // Requirement: N must be a positive integer
    if (n <= 0) {
        std::cout << "Error: Number of terms must be a positive integer." << std::endl;
    } else {
        printFibonacciTerms(n);
    }

    std::cout << "\n";

    // ==========================================
    // PART B: Check if Number Belongs to Sequence
    // ==========================================
    std::cout << "=== PART B: Fibonacci Number Check ===\n";
    long long num;
    std::cout << "Enter a number to check: ";
    std::cin >> num;

    if (num < 0) {
        std::cout << num << " is NOT a Fibonacci number." << std::endl;
    } else if (isFibonacciNumber(num)) {
        std::cout << num << " is a Fibonacci number." << std::endl;
    } else {
        std::cout << num << " is NOT a Fibonacci number." << std::endl;
    }

    return 0;
}

/**
 * PART A: Prints the first N terms of the Fibonacci sequence using a loop.
 */
void printFibonacciTerms(int n) {
    long long first = 0, second = 1;

    std::cout << "Fibonacci sequence: ";

    for (int i = 1; i <= n; ++i) {
        if (i == 1) {
            std::cout << first;
        } else if (i == 2) {
            std::cout << " " << second;
        } else {
            long long next = first + second;
            std::cout << " " << next;
            first = second;
            second = next;
        }
    }
    std::cout << std::endl;
}

/**
 * PART B: Checks whether a given number is part of the Fibonacci sequence using a loop.
 */
bool isFibonacciNumber(long long num) {
    if (num == 0 || num == 1) {
        return true;
    }

    long long first = 0, second = 1;
    long long next = first + second;

    // Generate sequence terms iteratively until we reach or exceed the target number
    while (next < num) {
        first = second;
        second = next;
        next = first + second;
    }

    return (next == num);
}