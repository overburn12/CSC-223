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

double getAvgScore(vector<double>);
void printScores(vector<double>,int);
vector<double> loadScores();

int main(){
    int studentID;
    vector<double> scores;
    cout << fixed << "Enter a student ID: ";
    cin >> studentID;
    scores=loadScores();
    printScores(scores, studentID);

    return 0;
}

vector<double> loadScores(){
    vector<double> scores;
    double tmp;
    for(int i=1; i<=3; i++){
        cout << "enter score for exam #" << i << ": ";
        cin >> tmp;
        scores.push_back(tmp);
    }
    return scores;
}

double getAvgScore(vector<double> scores){
    double total=0.0;

    for(auto p: scores)
        total+=p;
    
    return total/scores.size();
}

void printScores(vector<double> scores, int studentID){
    cout << setprecision(2) << "Printing exam scores for student with ID " << studentID << ":" << endl;

    for(int i=0; i<scores.size(); i++)
        cout << "exam #" << i+1 << ": " << scores[i] << endl;

    cout << setprecision(0) << "Average score: " << getAvgScore(scores) << endl;
}