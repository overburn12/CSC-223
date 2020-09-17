/*
3-4: Output Formatting: Write a program that reads four triathlon race time records 
from a file. The name of the file is racedat.txt. Each line of the file represents 
one record and contains an athlete identifier (a single character) and three numeric 
values. The three values are the completion times (in minutes) for the running, 
swimming, and biking stages of a triathlon. You will produce a nicely formatted 
report that displays these values, as well as the total time for each athlete. 
Finally, your report should calculate the average total time for the race. Hint: 
You may create your own racedat.txt file using Windows Notepad or other text editor. 
Your input file should have the format: A 31 27 52 B 29 31 58 C 35 36 51 D 34 36 62
*/

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

string makeTime(int intMinutes){
    //0:00 format, has to be less than 10 hours
    string strReturn="0:00";
    strReturn[0]+=intMinutes/60;
    intMinutes %= 60;       
    strReturn[2]+=intMinutes/10;
    strReturn[3]+=intMinutes%10; 
    return strReturn;
}

string center(string strIn, int width){
    string strOut(width, ' '); 
    int offset = width/2 - strIn.size()/2; 
    for(int i=0; i<strIn.size(); i++)
        strOut[offset+i] = strIn[i];
    return strOut;
}

string center(char ch, int width){
    string strReturn = " ";
    strReturn[0]=ch;
    return(center(strReturn,width));
}

int main(){
    ifstream inFile("racedat.txt");
    char name;
    int run, swim, bike;
    int sumTime = 0;
    int count = 0;
    
    int colWidth = 10; 
    char border = '*'; 
    char divider = '-';
    string hbar; 
    int tableWidth = colWidth*5 + 6; 
    hbar.append(tableWidth,border);

    string strOut = "Triathalon Race Results";
    cout << endl << center(strOut, tableWidth) << endl;
    cout << hbar << endl << border;
    cout << center("Name",colWidth)  << divider;
    cout << center("Run", colWidth)  << divider;
    cout << center("Swim", colWidth) << divider;
    cout << center("Bike", colWidth) << divider;
    cout << center("Total", colWidth) << border;
    cout << endl << hbar << endl;

    while(!inFile.eof()){
        inFile >> name >> run >> swim >> bike;
        cout << border << center(name,colWidth) << divider;
        cout << center(makeTime(run),colWidth)  << divider;
        cout << center(makeTime(swim),colWidth) << divider;
        cout << center(makeTime(bike),colWidth) << divider;
        cout << center(makeTime(bike+run+swim),colWidth) << border << endl;
        sumTime+=bike+run+swim;
        count++;
    }
    
    cout << hbar << endl;
    strOut = "Average Race Time ";
    strOut+= makeTime(sumTime/count);
    cout << center(strOut,tableWidth) << endl << endl;

    inFile.close();
}