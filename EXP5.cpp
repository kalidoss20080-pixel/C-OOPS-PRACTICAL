#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Student
{
public:
    string name;
    int mark;
    char grade;

    Student(string studentName, int studentMark)
    {
        name = studentName;
        mark = studentMark;
        grade = ' ';
    }
};

int main()
{
    // Different test case
    vector<Student> students;

    students.push_back(Student("Deepak", 88));
    students.push_back(Student("Sanjay", 76));
    students.push_back(Student("Vignesh", 94));
    students.push_back(Student("Mano", 68));

    // Sort students based on marks
    sort(students.begin(), students.end(),
        [](const Student &first, const Student &second)
        {
            return first.mark > second.mark;
        });

    // Assign grades using transform
    transform(students.begin(), students.end(), students.begin(),
        [](Student student)
        {
            if (student.mark >= 90)
                student.grade = 'A';
            else if (student.mark >= 75)
                student.grade = 'B';
            else if (student.mark >= 50)
                student.grade = 'C';
            else
                student.grade = 'F';

            return student;
        });

    // Find first student scoring above 80
    auto result = find_if(students.begin(), students.end(),
        [](const Student &student)
        {
            return student.mark > 80;
        });

    // Calculate total marks using accumulate
    int totalMarks = accumulate(students.begin(), students.end(), 0,
        [](int currentTotal, const Student &student)
        {
            return currentTotal + student.mark;
        });

    float average = static_cast<float>(totalMarks) / students.size();

    // Display results
    cout << "Student Grade Analyzer\n";
    cout << "---------------------\n";
    cout << "Name\tMark\tGrade\n";

    for (const auto &student : students)
    {
        cout << student.name << "\t"
             << student.mark << "\t"
             << student.grade << endl;
    }

    if (result != students.end())
    {
        cout << "\nFirst student scoring above 80: "
             << result->name << endl;
    }

    cout << "Total Marks: " << totalMarks << endl;
    cout << "Average Mark: " << average << endl;

    return 0;
}