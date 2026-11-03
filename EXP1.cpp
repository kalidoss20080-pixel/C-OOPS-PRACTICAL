#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int rollNo;
    string name;

public:
    Student(int r, string n) : rollNo(r), name(n) {
        cout << "Student object created" << endl;
    }

    void display() const {
        cout << "Roll Number: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Status: Successfully Registered" << endl;
        cout << "Record Type: Regular Student" << endl;
        cout << "---------------------------" << endl;
    }

    ~Student() {
        cout << "Student object destroyed" << endl;
    }
};

int main() {
    cout << "     STUDENT MANAGEMENT SYSTEM" << endl;
    cout << "================================" << endl;

    Student *ptr = new Student(301, "Kamalesh");

    cout << "================================" << endl;
    cout << "\n----- Student Details -----" << endl;

    ptr->display();

    delete ptr;

    cout << "Memory released successfully." << endl;
    cout << "================================" << endl;
    cout << "\nProgram completed successfully." << endl;

    return 0;
}