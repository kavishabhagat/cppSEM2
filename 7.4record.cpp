/* THIS PROGRAM IS PREPARED BY 24CE007_KAVISHA
   Date of Modification- 1 May 2025
   7.4 FILE- STUDENT PERFORMANCE RECORD USING CLASS */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

// User-defined manipulator for column formatting
ostream& tab(ostream& out) {
    out << setw(20) << left;
    return out;
}

class Student {
public:
    char name[50];
    float marks;
    char grade;

    Student() {
        name[0] = '\0';
        marks = 0.0;
        grade = 'F';
    }

    void display() const {
        cout << tab << name
             << tab << fixed << setprecision(2) << marks
             << tab << grade << endl;
    }
};

class StudentManager {
private:
    Student* students;
    int count;
    int capacity;

public:
    StudentManager() : students(nullptr), count(0), capacity(0) {}

    ~StudentManager() {
        delete[] students;
    }

    bool loadFromFile(const char* filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Error: Could not open '" << filename << "' for reading.\n";
            return false;
        }

        count = 0;
        capacity = 10;
        students = new Student[capacity];

        while (!file.eof()) {
            Student s;
            file.getline(s.name, 50, ',');
            file >> s.marks;
            file.ignore();
            file >> s.grade;
            file.ignore();

            if (file.fail()) break;

            if (count == capacity) {
                resize();
            }

            students[count++] = s;
        }

        file.close();
        return count > 0;
    }

    void resize() {
        int newCapacity = capacity * 2;
        Student* temp = new Student[newCapacity];
        for (int i = 0; i < count; ++i)
            temp[i] = students[i];
        delete[] students;
        students = temp;
        capacity = newCapacity;
    }

    void displayReport() const {
        cout << "\n=== Student Performance Report ===\n\n";
        cout << tab << "Name" << tab << "Marks" << tab << "Grade" << endl;
        cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;
        for (int i = 0; i < count; ++i) {
            students[i].display();
        }
    }
};

int main() {
    StudentManager manager;
    if (manager.loadFromFile("student.txt")) {
        manager.displayReport();
    }

    cout << endl << "Kavisha Bhagat 24CE007" << endl;
    return 0;
}
