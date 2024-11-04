#include <vector>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Gradebook {

    private:
    struct Student {
       string firstName;
       string lastName;
       string studentID;
       vector<double> grades;
    };
    
    struct Assignment {
        string name;
        double totalPoints;
    };

    vector<Student> students;       
    vector<Assignment> assignments; 

    public:
    void addStudent(const string& firstName, const string& lastName, const string& studentID);
    void addAssignment(const string& assignmentName, double totalPoints);
    void addGrade(const string& studentID, const string& assignmentName, double grade);
    void printReport(); 

};


void Gradebook :: addStudent(const string& firstName, const string& lastName, const string& studentID)
{
    Student newStudent;
    newStudent.firstName = firstName;
    newStudent.lastName = lastName;
    newStudent.studentID = studentID;
    newStudent.grades = vector<double>(assignments.size(), 0);
    students.push_back(newStudent);
    cout << "Student " << firstName << " " << lastName << " added." << endl;
}


void Gradebook :: addAssignment(const string& assignmentName, double totalPoints)
{
    Assignment newAssignment;
    newAssignment.name = assignmentName;
    newAssignment.totalPoints = totalPoints;
    assignments.push_back(newAssignment);

    for (auto& student : students) {
        student.grades.push_back(0);
    }
    cout << "'" << assignmentName << "'" << " added with " << totalPoints << " points possible.\n";
}


void Gradebook :: addGrade(const string& studentID, const string& assignmentName, double grade)
{
    int assignmentIndex = -1;

    for (int i = 0; i < assignments.size(); ++i) {
        if (assignments[i].name == assignmentName) {
            assignmentIndex = i;
            break;
        }
    }

    if (assignmentIndex == -1) {
        cout << "Assignment not found... please try again" << endl;
    }

    for (auto& student : students) {
        if (student.studentID == studentID) {
            student.grades[assignmentIndex] = grade;
            cout << "Grade " << grade << " added for " << student.firstName << " " << student.lastName << " on " << assignmentName << ".\n";
        }
    } 
}

void Gradebook :: printReport()
{
    cout << left << setw(20) << "Student ID" << setw(20) << "Name";

    for (const auto& assignment : assignments) {
        cout << setw(20) << assignment.name;
    }
    cout << endl;

    for (const auto& student : students) {
        cout << left << setw(20) << student.studentID
             << setw(20) << student.firstName + " " + student.lastName;

        for (const auto& grade : student.grades) {
            cout << setw(20) << grade;
        }
        cout << endl;
    }
}
