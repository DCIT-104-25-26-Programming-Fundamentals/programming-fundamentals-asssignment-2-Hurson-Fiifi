// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 2
// =============================================================================
//
// TASK: Student Grade System
//
// Write a C++ program that reads a student's score and outputs the
// corresponding letter grade based on the scale below.
//
// Grading Scale:
//   Score 80 – 100  →  Grade A
//   Score 70 – 79   →  Grade B
//   Score 60 – 69   →  Grade C
//   Score 50 – 59   →  Grade D
//   Score below 50  →  Grade F
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLES
// -----------------------------------------------------------------------------
//
//   Enter student score (0-100): 85
//   Grade: A
//
//   Enter student score (0-100): 73
//   Grade: B
//
//   Enter student score (0-100): 45
//   Grade: F
//
//   Enter student score (0-100): 110
//   Error: Score must be between 0 and 100.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST use functions (see scaffold below).
// - Validate the score inside getGrade(). If it is out of range, return '\0'
//   (null character) and let main() print the error message.
// - Use if / else if / else to determine the grade.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;
#include <iostream>

// Function prototype
char getGrade(int score);

int main() {
    int score;

    // Prompt user for input
    std::cout << "Enter student score (0-100): ";
    std::cin >> score;

    // Get letter grade
    char grade = getGrade(score);

    // Check if score was invalid
    if (grade == '\0') {
        std::cout << "Error: Score must be between 0 and 100." << std::endl;
    } else {
        std::cout << "Grade: " << grade << std::endl;
    }

    return 0;
}

/**
 * Validates score and returns the corresponding letter grade.
 * 
 * @param score The student's numerical score.
 * @return Letter grade ('A'-'D', 'F'), or '\0' if out of range.
 */
char getGrade(int score) {
    // Validate range [0, 100]
    if (score < 0 || score > 100) {
        return '\0';
    }

    // Determine letter grade based on scale
    if (score >= 80) {
        return 'A';
    } else if (score >= 70) {
        return 'B';
    } else if (score >= 60) {
        return 'C';
    } else if (score >= 50) {
        return 'D';
    } else {
        return 'F';
    }
}
