/*
3-1: Text Input: Write a program that prompts the user to enter the date 
in mm/dd/yyyy format. The program should use a single input statement to 
accept the date, storing each piece of the date into an appropriate variable. 
Demonstrate that the input was obtained correctly by outputting the 
month, day, and year to the screen. 
Sample output: Enter (date (mm/dd/yyyy): 02/08/2011 
Month entered: 2 
Day entered: 8 
Year entered: 2011 
Challenge: Although the user entered 02, C++ drops the 0 as insignificant when 
the program outputs the value. Revise your program to always output two-digit 
months and days. For example, 02 should output as 02 and 10 should output as 10 (not 010).
*/

#include <iostream>
#include <string>

using namespace std; 

string pad(int num, int width=2){
    string str=to_string(num);

    while(str.length() < width)
        str="0"+str;

    return str;
}

int main(){
    string strInput;
    int intPart[3]={0,0,0};

    cout << "Enter a date (mm/dd/yyy): ";
    getline(cin,strInput);

    int pt=0; 
    for(int i=0; i<strInput.length() && pt<3; i++)
        if('0' <= strInput[i] && strInput[i] <= '9') 
            intPart[pt]= intPart[pt]*10 + (strInput[i]-'0'); 
        else
            pt++; 

    cout << "Month entered: " << pad(intPart[0]) << endl;
    cout << "Day entered: " << pad(intPart[1]) << endl;
    cout << "Year entered: " << pad(intPart[2],4) << endl;

    return 0;
}