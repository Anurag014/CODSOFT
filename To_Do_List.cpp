#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void displayMenu();
void addTask(ofstream &fileStream);
void viewTasks(ifstream &fileStream);
void markTaskAsCompleted(fstream &fileStream);
void removeTask(fstream &fileStream);

int main() {
    string fileName = "todo_list.txt";

    while (true) {
        displayMenu();

        int choice;
        cin >> choice;

        ofstream outFile;
        outFile.open(fileName, ios::app);

        ifstream inFile;
        inFile.open(fileName);

        fstream inOutFile;
        inOutFile.open(fileName, ios::in | ios::out);

        switch (choice) {
            case 1:
                addTask(outFile);
                break;
            case 2:
                viewTasks(inFile);
                break;
            case 3:
                markTaskAsCompleted(inOutFile);
                break;
            case 4:
                removeTask(inOutFile);
                break;
            case 5:
                outFile.close();
                inFile.close();
                inOutFile.close();
                return 0;
            default:
                cout << "\nInvalid choice. Please try again." << endl;
        }
    }

    return 0;
}

void displayMenu() {
    cout << "\n==================== Todo List Menu ====================" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
    cout << "========================================================" << endl;
    cout << "Enter your choice: ";
}

void addTask(ofstream &fileStream) {
    string task;
    cout << "Enter the task: ";
    cin.ignore();
    getline(cin, task);
    fileStream << "PENDING: " << task << endl;
    cout << "\nTask added successfully." << endl;
}

void viewTasks(ifstream &fileStream) {
    string line;
    int taskNumber = 1;

    cout << "\n======================= Tasks =======================" << endl;
    while (getline(fileStream, line)) {
        cout << taskNumber << ". " << line << endl;
        taskNumber++;
    }
    cout << "=====================================================" << endl;
}

void markTaskAsCompleted(fstream &fileStream) {
    int taskNumber;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;

    string line;
    vector<string> tasks;

    fileStream.seekg(0, ios::beg);

    while (getline(fileStream, line)) {
        tasks.push_back(line);
    }

    if (taskNumber > 0 && taskNumber <= static_cast<int>(tasks.size())) {
        size_t found = tasks[taskNumber - 1].find("PENDING");
        if (found != string::npos) {
            tasks[taskNumber - 1].replace(found, 7, "COMPLETED");
            fileStream.close();
            fileStream.open("todo_list.txt", ios::out | ios::trunc);

            for (const auto &task : tasks) {
                fileStream << task << endl;
            }

            cout << "\nTask marked as completed." << endl;
        } else {
            cout << "\nTask is already completed." << endl;
        }
    } else {
        cout << "\nInvalid task number." << endl;
    }
}

void removeTask(fstream &fileStream) {
    int taskNumber;
    cout << "Enter the task number to remove: ";
    cin >> taskNumber;

    string line;
    vector<string> tasks;

    fileStream.seekg(0, ios::beg);

    while (getline(fileStream, line)) {
        tasks.push_back(line);
    }

    if (taskNumber > 0 && taskNumber <= static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        fileStream.close();
        fileStream.open("todo_list.txt", ios::out | ios::trunc);

        for (const auto &task : tasks) {
            fileStream << task << endl;
        }

        cout << "\nTask removed successfully." << endl;
    } else {
        cout << "\nInvalid task number." << endl;
    }
}
