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
#include <string>
using namespace std;

const int MAX_TASKS = 100;

// Function to display all tasks
void viewTasks(string tasks[], int taskCount) {
    if (taskCount == 0) {
        cout << "\nNo tasks in the to-do list.\n";
        return;
    }

    cout << "\n----- TO-DO LIST -----\n";
    for (int i = 0; i < taskCount; i++) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

// Function to add a task
void addTask(string tasks[], int &taskCount) {
    if (taskCount >= MAX_TASKS) {
        cout << "Task list is full!\n";
        return;
    }

    cin.ignore();
    cout << "Enter a new task: ";
    getline(cin, tasks[taskCount]);

    taskCount++;
    cout << "Task added successfully.\n";
}

// Function to delete a task
void deleteTask(string tasks[], int &taskCount) {
    if (taskCount == 0) {
        cout << "No tasks to delete.\n";
        return;
    }

    int taskNumber;
    viewTasks(tasks, taskCount);

    cout << "Enter the task number to delete: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > taskCount) {
        cout << "Invalid task number.\n";
        return;
    }

    for (int i = taskNumber - 1; i < taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
    }

    taskCount--;
    cout << "Task deleted successfully.\n";
}

int main() {
    string tasks[MAX_TASKS];
    int taskCount = 0;
    int choice;

    do {
        cout << "\n====== TO-DO LIST MENU ======\n";
        cout << "1. View Tasks\n";
        cout << "2. Add Task\n";
        cout << "3. Delete Task\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                viewTasks(tasks, taskCount);
                break;

            case 2:
                addTask(tasks, taskCount);
                break;

            case 3:
                deleteTask(tasks, taskCount);
                break;

            case 4:
                cout << "Exiting program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

