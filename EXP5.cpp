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

    // Calculate total marks
    int totalMarks = accumulate(students.begin(), students.end(), 0,
        [](int currentTotal, const Student &student)
        {
            return currentTotal + student.mark;
        });

    float average = static_cast<float>(totalMarks) / students.size();

    // Display original results
    cout << "STUDENT GRADE ANALYZER\n";
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

    // Additional Outputs
    cout << "\n========== PERFORMANCE SUMMARY ==========\n";

    cout << "Highest Mark: "
         << students.front().mark << endl;

    cout << "Lowest Mark: "
         << students.back().mark << endl;

    cout << "Topper: "
         << students.front().name << endl;

    int gradeA = count_if(students.begin(), students.end(),
        [](const Student &s) { return s.grade == 'A'; });

    int gradeB = count_if(students.begin(), students.end(),
        [](const Student &s) { return s.grade == 'B'; });

    int gradeC = count_if(students.begin(), students.end(),
        [](const Student &s) { return s.grade == 'C'; });

    int gradeF = count_if(students.begin(), students.end(),
        [](const Student &s) { return s.grade == 'F'; });

    cout << "\nGrade Distribution:\n";
    cout << "Grade A: " << gradeA << endl;
    cout << "Grade B: " << gradeB << endl;
    cout << "Grade C: " << gradeC << endl;
    cout << "Grade F: " << gradeF << endl;

    cout << "\nAnalysis Completed Successfully!" << endl;

    return 0;
}