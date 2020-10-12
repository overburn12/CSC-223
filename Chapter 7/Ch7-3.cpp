/*
Write an application that enables users to enter student ID and three exam scores. 
Provide a method to compute and return the overall exam average. Provide another 
method that prints all scores and the average value formatted with no digits to the 
right of the decimal. Use a single method to enter all data.
*/

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct ExamRecords{
    vector<double> scores;
    int StudentID;
};

ExamRecords createRecord(){
    ExamRecords tmpStudent;
    double tmpExam;
    cout << "Enter the students ID: ";
    cin >> tmpStudent.StudentID;

    for(int i=1; i<=3; i++){
        cout << "enter score for exam #" << i << ": ";
        cin >> tmpExam;
        tmpStudent.scores.push_back(tmpExam);
    }

    return tmpStudent;
}

double getAvgScore(ExamRecords tmpStudent){
    double total=0.0;

    for(auto p: tmpStudent.scores)
        total+=p;
    
    return total/tmpStudent.scores.size();
}

void printScores(ExamRecords tmpStudent){
    cout << fixed << setprecision(2) << "Printing exam scores for student with ID " 
         << tmpStudent.StudentID << ":" << endl;

    for(int i=0; i<tmpStudent.scores.size(); i++)
        cout << "exam #" << i+1 << ": " << tmpStudent.scores[i] << endl;

    cout << setprecision(0) << "Average score: " << getAvgScore(tmpStudent) << endl;
}

int main(){
    ExamRecords Student1;
    Student1=createRecord();
    printScores(Student1);
    return 0;
}