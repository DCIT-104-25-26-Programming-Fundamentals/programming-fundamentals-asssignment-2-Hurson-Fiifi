// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>

// Function Prototypes
void displayMenu();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b, bool& error);
int modulus(int a, int b, bool& error);
double power(double base, double exp);

int main() {
    int choice = 0;

    do {
        displayMenu();
        std::cout << "Select an operation (1-7): ";

        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number between 1 and 7.\n\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 7) {
            std::cout << "Goodbye!\n";
            break;
        }

        if (choice < 1 || choice > 7) {
            std::cout << "Invalid choice. Please select an operation between 1 and 7.\n\n";
            continue;
        }

        double num1, num2;
        std::cout << "Enter first number : ";
        while (!(std::cin >> num1)) {
            std::cout << "Invalid entry. Enter a valid first number: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

        std::cout << "Enter second number: ";
        while (!(std::cin >> num2)) {
            std::cout << "Invalid entry. Enter a valid second number: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

        bool hasError = false;

        switch (choice) {
            case 1:
                std::cout << "Result: " << num1 << " + " << num2 << " = " 
                          << std::fixed << std::setprecision(2) << add(num1, num2) << "\n";
                break;
            case 2:
                std::cout << "Result: " << num1 << " - " << num2 << " = " 
                          << std::fixed << std::setprecision(2) << subtract(num1, num2) << "\n";
                break;
            case 3:
                std::cout << "Result: " << num1 << " * " << num2 << " = " 
                          << std::fixed << std::setprecision(2) << multiply(num1, num2) << "\n";
                break;
            case 4: {
                double result = divide(num1, num2, hasError);
                if (!hasError) {
                    std::cout << "Result: " << num1 << " / " << num2 << " = " 
                              << std::fixed << std::setprecision(2) << result << "\n";
                }
                break;
            }
            case 5: {
                int modResult = modulus(static_cast<int>(num1), static_cast<int>(num2), hasError);
                if (!hasError) {
                    std::cout << "Result: " << static_cast<int>(num1) << " % " << static_cast<int>(num2) << " = " 
                              << modResult << "\n";
                }
                break;
            }
            case 6:
                std::cout << "Result: " << num1 << " ^ " << num2 << " = " 
                          << std::fixed << std::setprecision(2) << power(num1, num2) << "\n";
                break;
        }

        std::cout << "\n";

    } while (choice != 7);

    return 0;
}

/**
 * Displays the main menu options.
 */
void displayMenu() {
    std::cout << "=================================\n";
    std::cout << "        SIMPLE CALCULATOR        \n";
    std::cout << "=================================\n";
    std::cout << "1. Addition\n";
    std::cout << "2. Subtraction\n";
    std::cout << "3. Multiplication\n";
    std::cout << "4. Division\n";
    std::cout << "5. Modulus\n";
    std::cout << "6. Exponentiation\n";
    std::cout << "7. Quit\n";
}

// 1. Addition
double add(double a, double b) {
    return a + b;
}

// 2. Subtraction
double subtract(double a, double b) {
    return a - b;
}

// 3. Multiplication
double multiply(double a, double b) {
    return a * b;
}

// 4. Division with zero check
double divide(double a, double b, bool& error) {
    if (b == 0) {
        std::cout << "Error: Cannot divide by zero.\n";
        error = true;
        return 0.0;
    }
    return a / b;
}

// 5. Modulus with zero check
int modulus(int a, int b, bool& error) {
    if (b == 0) {
        std::cout << "Error: Cannot perform modulus by zero.\n";
        error = true;
        return 0;
    }
    return a % b;
}

// 6. Exponentiation using std::pow
double power(double base, double exp) {
    return std::pow(base, exp);
}

