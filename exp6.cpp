#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    int rollNo;
    string name;
public:
    void getStudentData() {
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin >> name;
    }

    void displayStudentData() {
        cout << "\nRoll No: " << rollNo << "\nName: " << name << endl;
    }
};

class StudentExam : public Student {
protected:
    float marks[3];
public:
    void getExamData() {
        cout << "Enter marks for 3 subjects: ";
        for (int i = 0; i < 3; i++)
            cin >> marks[i];
    }

    void displayExamData() {
        cout << "Marks: ";
        for (int i = 0; i < 3; i++)
            cout << marks[i] << " ";
        cout << endl;
    }
};

class Result : public StudentExam {
    float total = 0, percentage = 0;
public:
    void calculateResult() {
        for (int i = 0; i < 3; i++)
            total += marks[i];
        percentage = total / 3;
    }

    void displayResult() {
        displayStudentData();
        displayExamData();
        cout << "Total Marks: " << total << endl;
        cout << "Percentage: " << percentage << "%" << endl;
    }
};

int main() {
    Result r;
    r.getStudentData();
    r.getExamData();
    r.calculateResult();
    r.displayResult();
    return 0;
}
