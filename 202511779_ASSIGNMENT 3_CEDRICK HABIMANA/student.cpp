#include "student.h"

Student students[100];
int totalStudents = 0;

// Function to add a student
void addStudent()
{
    cout << "\nEnter Student ID: ";
    cin >> students[totalStudents].id;

    cin.ignore();

    cout << "Enter Student Name: ";
    getline(cin, students[totalStudents].name);

    cout << "Enter Age: ";
    cin >> students[totalStudents].age;

    cin.ignore();

    cout << "Enter Course: ";
    getline(cin, students[totalStudents].course);

    totalStudents++;

    cout << "\033[33m";
    cout << "Student added successfully!\n";
    cout << "\033[0m";
}

// Function to display all students
void displayStudents()
{
    if (totalStudents == 0)
    {
        cout << "\033[31m";
        cout << "\nNo students available.\n";
        cout << "\033[0m";
        return;
    }

    cout << "\n===== STUDENT LIST =====\n";

    for (int i = 0; i < totalStudents; i++)
    {
        cout << "\nStudent " << i + 1 << endl;
        cout << "ID: " << students[i].id << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;
        cout << "Course: " << students[i].course << endl;
    }
}

// Function to search a student by ID
void searchStudent()
{
    int searchId;
    bool found = false;

    cout << "\nEnter Student ID to search: ";
    cin >> searchId;

    for (int i = 0; i < totalStudents; i++)
    {
        if (students[i].id == searchId)
        {
            cout << "\nStudent Found!\n";
            cout << "ID: " << students[i].id << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Age: " << students[i].age << endl;
            cout << "Course: " << students[i].course << endl;

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Student not found.\n";
    }
}

// Function to update student information
void updateStudent()
{
    int updateId;
    bool found = false;

    cout << "\nEnter Student ID to update: ";
    cin >> updateId;

    for (int i = 0; i < totalStudents; i++)
    {
        if (students[i].id == updateId)
        {
            cin.ignore();

            cout << "Enter new name: ";
            getline(cin, students[i].name);

            cout << "Enter new age: ";
            cin >> students[i].age;

            cin.ignore();

            cout << "Enter new course: ";
            getline(cin, students[i].course);

            cout << "Student information updated successfully!\n";

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Student not found.\n";
    }
}

// Function to delete a student
void deleteStudent()
{
    int deleteId;
    bool found = false;

    cout << "\nEnter Student ID to delete: ";
    cin >> deleteId;

    for (int i = 0; i < totalStudents; i++)
    {
        if (students[i].id == deleteId)
        {
            for (int j = i; j < totalStudents - 1; j++)
            {
                students[j] = students[j + 1];
            }

            totalStudents--;

            cout << "Student deleted successfully!\n";

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Student not found.\n";
    }
}