// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

// Struct definition
struct Student {
    std::string name;
    int id;
    std::vector<double> scores;
};

// Function Prototypes
void displayMenu();
void addStudent(std::vector<Student>& students);
void displayAllStudents(const std::vector<Student>& students);
void calculateStudentAverage(const std::vector<Student>& students);
double getAverage(const std::vector<double>& scores);

int main() {
    std::vector<Student> students;
    int choice = 0;

    do {
        displayMenu();
        std::cout << "Enter your choice (1-4): ";

        if (!(std::cin >> choice)) {
            std::cout << "Invalid choice. Please enter a number between 1 and 4.\n\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        std::cout << "\n";

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                calculateStudentAverage(students);
                break;
            case 4:
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
                break;
        }

        std::cout << "\n";

    } while (choice != 4);

    return 0;
}

/**
 * Displays the system menu options.
 */
void displayMenu() {
    std::cout << "=================================\n";
    std::cout << "   STUDENT RECORD SYSTEM MENU    \n";
    std::cout << "=================================\n";
    std::cout << "1. Add student\n";
    std::cout << "2. Display all students\n";
    std::cout << "3. Calculate average score\n";
    std::cout << "4. Quit\n";
}

/**
 * Helper function to calculate the average of a list of scores.
 */
double getAverage(const std::vector<double>& scores) {
    if (scores.empty()) return 0.0;
    
    double sum = 0.0;
    for (double score : scores) {
        sum += score;
    }
    return sum / scores.size();
}

/**
 * Feature 1: Prompts for student details and scores, then saves the record.
 */
void addStudent(std::vector<Student>& students) {
    Student newStudent;

    std::cout << "Student name: ";
    std::cin.ignore(); // Clear remaining newline character
    std::getline(std::cin, newStudent.name);

    std::cout << "Student ID: ";
    while (!(std::cin >> newStudent.id)) {
        std::cout << "Invalid ID. Enter a numeric Student ID: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    int numScores = 0;
    std::cout << "How many scores? ";
    while (!(std::cin >> numScores) || numScores < 0) {
        std::cout << "Please enter a valid number of scores: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    for (int i = 0; i < numScores; ++i) {
        double score;
        std::cout << "Enter score " << (i + 1) << ": ";
        while (!(std::cin >> score) || score < 0) {
            std::cout << "Invalid score. Re-enter score " << (i + 1) << ": ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        newStudent.scores.push_back(score);
    }

    students.push_back(newStudent);
    std::cout << "Student \"" << newStudent.name << "\" added successfully.\n";
}

/**
 * Feature 2: Displays a formatted table of all students, their scores, and averages.
 */
void displayAllStudents(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "No student records found.\n";
        return;
    }

    std::cout << std::left << std::setw(12) << "ID"
              << std::setw(20) << "Name"
              << std::setw(25) << "Scores"
              << std::setw(10) << "Average" << "\n";
    std::cout << std::string(67, '-') << "\n";

    for (const auto& student : students) {
        std::cout << std::left << std::setw(12) << student.id
                  << std::setw(20) << student.name;

        // Build scores display string
        std::string scoresStr = "";
        for (size_t i = 0; i < student.scores.size(); ++i) {
            scoresStr += std::to_string(static_cast<int>(student.scores[i]));
            if (i < student.scores.size() - 1) {
                scoresStr += ", ";
            }
        }
        
        if (scoresStr.empty()) {
            scoresStr = "N/A";
        }

        std::cout << std::setw(25) << scoresStr;
        std::cout << std::fixed << std::setprecision(2) << getAverage(student.scores) << "\n";
    }
}

/**
 * Feature 3: Finds a student by ID and displays their average score.
 */
void calculateStudentAverage(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "No student records available.\n";
        return;
    }

    int searchId;
    std::cout << "Enter student ID: ";
    if (!(std::cin >> searchId)) {
        std::cout << "Error: Invalid ID format.\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return;
    }

    for (const auto& student : students) {
        if (student.id == searchId) {
            double avg = getAverage(student.scores);
            std::cout << student.name << "'s average score: "
                      << std::fixed << std::setprecision(2) << avg << "\n";
            return;
        }
    }

    std::cout << "Error: Student with ID " << searchId << " not found.\n";
}

