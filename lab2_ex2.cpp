// lab2_e2.cpp
 
//Create a computer program in C++ with the following elements:

// 1.Create a class named Course, with a string variable name and a double array named scores.
// 2.Create a class named Student, with a string variable name, and with an array of Course objects of length 4.
// 3.Create a class named Program, with a string variable name, and with an array of Student objects of length 10.
// 4. Add a method to the Program class that will print the name and the average of the scores of each course.

#include <iostream>
#include <string>
using namespace std;

class Course {
public:
    string name;
    double scores[5];

    Course(string courseName, double courseScores[5]) {
        name = courseName;
        for (int i = 0; i < 5; i++) {
            scores[i] = courseScores[i];
        }
    }

    double getAverageScore() {
        double sum = 0;
        for (double score : scores) {
            sum += score;
        }
        return sum / 5;
    }
};

class Student {
public:
    string name;
    Course courses[4];

    Student(string studentName, Course courseList[4]) : name(studentName), courses{courseList[0], courseList[1], courseList[2], courseList[3]} {}
};

class Program {
public:
    string name;
    Student students[10];

    Program(string programName, Student studentList[10]) : name(programName), students{studentList[0], studentList[1], studentList[2], studentList[3], studentList[4], studentList[5], studentList[6], studentList[7], studentList[8], studentList[9]} {}

    void printCourseAverages() {
        cout << "Program: " << name << endl;
        for (int i = 0; i < 4; i++) {
            double totalAverage = 0;
            for (int j = 0; j < 10; j++) {
                totalAverage += students[j].courses[i].getAverageScore();
            }
            cout << "Course: " << students[0].courses[i].name << " - Average Score: " << (totalAverage / 10) << endl;
        }
    }
};

int main() {
    double sampleScores1[5] = {85, 90, 78, 92, 88};
    double sampleScores2[5] = {80, 85, 79, 91, 87};
    double sampleScores3[5] = {75, 80, 85, 90, 95};
    double sampleScores4[5] = {88, 92, 94, 89, 90};

    Course courses[] = {
        Course("Python", sampleScores1),
        Course("C++", sampleScores2),
        Course("Java", sampleScores3),
        Course("Pascal", sampleScores4)
    };

    Student students[10];
    for (int i = 0; i < 10; i++) {
        students[i] = Student("Student " + to_string(i + 1), courses);
    }

    Program program("Computer Science", students);
    program.printCourseAverages();

    return 0;
}
