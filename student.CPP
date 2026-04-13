#include <iostream.h>
#include <fstream.h>

class Student {
public:
    int id;
    char name[50];
    float marks;

    void input() {
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() {
        cout << "\nID: " << id;
        cout << "\nName: " << name;
        cout << "\nMarks: " << marks << endl;
    }
};

void addStudent() {
    Student s;
    ofstream file("students.dat", ios::binary | ios::app);

    s.input();
    file.write((char*)&s, sizeof(s));

    file.close();
    cout << "Student record added successfully!\n";
}

void displayStudents() {
    Student s;
    ifstream file("students.dat", ios::binary);

    while (file.read((char*)&s, sizeof(s))) {
        s.display();
    }

    file.close();
}

void searchStudent() {
    int id;
    Student s;
    int found,true;

    ifstream file("students.dat", ios::binary);

    cout << "Enter ID to search: ";
    cin >> id;

    while (file.read((char*)&s, sizeof(s))) {
        if (s.id == id) {
            cout << "\nStudent Found:\n";
            s.display();
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Student not found!\n";

    file.close();
}

int main() {
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: cout << "Exiting..."; break;
            default: cout << "Invalid choice!";
        }

    } while (choice != 4);

    return 0;
}