// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// =============================================================================
//
// TASK: Console-Based To-Do List Application
//
// Build a simple to-do list program that runs entirely in the console and
// allows the user to manage their tasks interactively using a menu.
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Task
//      - Prompt the user to type a task description.
//      - Add it to the list and confirm it was added.
//
//   2. View All Tasks
//      - Display all tasks currently in the list, numbered from 1.
//      - If the list is empty, print a friendly message saying so.
//
//   3. Delete a Task
//      - Show the list of tasks with their numbers.
//      - Ask the user which task number they want to remove.
//      - Remove the task and confirm the deletion.
//      - If the task number is invalid, print an error message.
//
//   4. Quit
//      - End the program with a farewell message.
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        TO-DO LIST MENU
//   ============================
//   1. Add task
//   2. View tasks
//   3. Delete task
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Enter task: Buy groceries
//   Task added: "Buy groceries"
//
//   Enter your choice (1-4): 2
//   Your Tasks:
//   1. Buy groceries
//   2. Study for exams
//
//   Enter your choice (1-4): 3
//   Enter task number to delete: 1
//   Task "Buy groceries" has been removed.
//
//   Enter your choice (1-4): 4
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Store tasks in a vector<string> (a dynamic list of text).
// - Use a loop to keep the menu running until the user chooses to quit.
// - Each feature MUST be implemented in its own function (see scaffold below).
// - Handle invalid menu choices gracefully (print an error, do not crash).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include <iostream>
#include <vector>
#include <string>

// Function Prototypes
void displayMenu();
void addTask(std::vector<std::string>& tasks);
void viewTasks(const std::vector<std::string>& tasks);
void deleteTask(std::vector<std::string>& tasks);

int main() {
    std::vector<std::string> tasks;
    int choice = 0;

    do {
        displayMenu();
        std::cout << "Enter your choice (1-4): ";
        
        // Handle non-integer input gracefully
        if (!(std::cin >> choice)) {
            std::cout << "Invalid choice. Please enter a number between 1 and 4.\n\n";
            std::cin.clear(); // Clear error flags
            std::cin.ignore(10000, '\n'); // Discard invalid input
            continue;
        }

        std::cout << "\n";

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
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
 * Displays the main user menu header and options.
 */
void displayMenu() {
    std::cout << "=================================\n";
    std::cout << "        TO-DO LIST MENU          \n";
    std::cout << "=================================\n";
    std::cout << "1. Add task\n";
    std::cout << "2. View tasks\n";
    std::cout << "3. Delete task\n";
    std::cout << "4. Quit\n";
}

/**
 * Requirement 1: Prompts for a task description, adds it to vector, and confirms.
 */
void addTask(std::vector<std::string>& tasks) {
    std::cout << "Enter task: ";
    std::cin.ignore(); // Clear remaining newline character from previous input
    
    std::string task;
    std::getline(std::cin, task);

    if (!task.empty()) {
        tasks.push_back(task);
        std::cout << "Task added: \"" << task << "\"\n";
    } else {
        std::cout << "Task description cannot be empty.\n";
    }
}

/**
 * Requirement 2: Displays all tasks numbered from 1.
 */
void viewTasks(const std::vector<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "Your to-do list is currently empty!\n";
        return;
    }

    std::cout << "Your Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << (i + 1) << ". " << tasks[i] << "\n";
    }
}

/**
 * Requirement 3: Deletes a task by 1-based index and handles invalid numbers.
 */
void deleteTask(std::vector<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks available to delete.\n";
        return;
    }

    viewTasks(tasks);
    std::cout << "\nEnter task number to delete: ";
    
    int taskNumber;
    if (!(std::cin >> taskNumber) || taskNumber < 1 || taskNumber > static_cast<int>(tasks.size())) {
        std::cout << "Error: Invalid task number.\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return;
    }

    // Convert 1-based user choice to 0-based vector index
    int indexToDelete = taskNumber - 1;
    std::string removedTask = tasks[indexToDelete];
    
    tasks.erase(tasks.begin() + indexToDelete);
    std::cout << "Task \"" << removedTask << "\" has been removed.\n";
}
