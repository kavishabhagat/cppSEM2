/* THIS PROGRAM IS PREPARED BY 24CE007_KAVISHA
   Date of Modification- 1 May 2025
   7.4 FILE- STUDENT PERFORMANCE RECORD*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

struct Student {
    char name[50];
    float marks;
    char grade;
};

// User-defined manipulator for column formatting
ostream& tab(ostream& out) {
    out << setw(20) << left;
    return out;
}

// Function to load student data from file into dynamically allocated array
int loadStudents(Student*& students) {
    ifstream file("student.txt");
    if (!file) {
        cerr << "Error: Could not open 'students.txt' for reading.\n";
        return 0;
    }

    int count = 0;
    int capacity = 10;
    students = new Student[capacity];

    while (!file.eof()) {
        Student s;
        file.getline(s.name, 50, ',');      // Name ends with comma
        file >> s.marks;
        file.ignore();                      // Ignore comma
        file >> s.grade;
        file.ignore();                      // Ignore newline

        if (file.fail()) break;

        if (count == capacity) {
            // Resize array
            int newCapacity = capacity * 2;
            Student* temp = new Student[newCapacity];
            for (int i = 0; i < count; ++i)
                temp[i] = students[i];
            delete[] students;
            students = temp;
            capacity = newCapacity;
        }

        students[count++] = s;
    }

    file.close();
    return count;
}

// Function to display student report in a formatted table
void displayReport(Student* students, int count) {
    cout << "\n=== Student Performance Report ===\n\n";
    cout << tab << "Name" << tab << "Marks" << tab << "Grade" << endl;
    cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;

    for (int i = 0; i < count; ++i) {
        cout << tab << students[i].name
             << tab << fixed << setprecision(2) << students[i].marks
             << tab << students[i].grade << endl;
    }
}

int main() {
    Student* students = nullptr;
    int studentCount = loadStudents(students);

    if (studentCount > 0) {
        displayReport(students, studentCount);
        delete[] students;  // Free allocated memory
    }

    cout << endl << "Kavisha Bhagat 24CE007" << endl;
}
