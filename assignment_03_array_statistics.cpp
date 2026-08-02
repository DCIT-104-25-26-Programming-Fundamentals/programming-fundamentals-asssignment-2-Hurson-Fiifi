// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;
#include <iostream>
#include <vector>

// Function prototypes
double calculateSum(const std::vector<double>& numbers);
double calculateAverage(const std::vector<double>& numbers);
double findMaximum(const std::vector<double>& numbers);
double findMinimum(const std::vector<double>& numbers);

int main() {
    int count;

    // Prompt for the total count of numbers
    std::cout << "How many numbers? ";
    std::cin >> count;

    // Requirement: N must be a positive integer
    if (count <= 0) {
        std::cout << "Error: Number of elements must be greater than 0." << std::endl;
        return 1;
    }

    std::vector<double> numbers(count);

    // Read user inputs
    for (int i = 0; i < count; ++i) {
        std::cout << "Enter number " << (i + 1) << ": ";
        std::cin >> numbers[i];
    }

    std::cout << std::endl;
    std::cout << "Results:" << std::endl;
    std::cout << "Sum:     " << calculateSum(numbers) << std::endl;
    std::cout << "Average: " << calculateAverage(numbers) << std::endl;
    std::cout << "Maximum: " << findMaximum(numbers) << std::endl;
    std::cout << "Minimum: " << findMinimum(numbers) << std::endl;

    return 0;
}

// Function to calculate the sum using a custom loop
double calculateSum(const std::vector<double>& numbers) {
    double sum = 0.0;
    for (size_t i = 0; i < numbers.size(); ++i) {
        sum += numbers[i];
    }
    return sum;
}

// Function to calculate average using custom sum logic
double calculateAverage(const std::vector<double>& numbers) {
    return calculateSum(numbers) / numbers.size();
}

// Function to find the maximum value using a custom loop
double findMaximum(const std::vector<double>& numbers) {
    double maxVal = numbers[0];
    for (size_t i = 1; i < numbers.size(); ++i) {
        if (numbers[i] > maxVal) {
            maxVal = numbers[i];
        }
    }
    return maxVal;
}

// Function to find the minimum value using a custom loop
double findMinimum(const std::vector<double>& numbers) {
    double minVal = numbers[0];
    for (size_t i = 1; i < numbers.size(); ++i) {
        if (numbers[i] < minVal) {
            minVal = numbers[i];
        }
    }
    return minVal;
}

