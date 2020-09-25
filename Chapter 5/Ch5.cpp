/*
Sales people at a local car dealership are paid by commission.  For every car sale, a sales person
 earns 30% of the base price or $100, whichever is higher.   
 
Write a program that uses of a loop to read through and process records in a file.  
Whenever the program encounters a new employee id, it should pause processing long enough
 to display the total of the previous employee’s commissions before processing the record 
 just read.  After all records have been processed, the program should display a count of 
 the records processed, the total sales, and the total commissions paid out.
  A sample output follows: 
 
 	 	WEEKLY SALES REPORT 
Employee Retail 	Base    Commission 
101  	24125.00 	1201.00 	360.30 
101  	7650.00 	350.00	    105.00 
101 	38460.00 	1517.00 	455.10 
***Total Commission for 101:  920.40 
 
	
102 	10500.00 	500.00 	    150.00 
102	    7500.00	    250.00 	    100.00 
102	    17551.00	1120.00 	336.00 
102	    12400.00 	400.00 	    120.00 
***Total Commission for 102:  706.00 
 
103	    41500.00	550.00  	165.00 
103	    18670.00 	1250.00 	375.00 
103 	6700.00 	250.00 	    100.00 
103 	17067.00 	1018.00 	305.40 
***Total Commission for 103:  945.40 
 
Records:   11 
Total Sales:  202123.00 
Total Commissions:  2571.80 
 
A sample input file, carsales.dat, to generate the report is shown below. 
 The first value in a line is the employee id.  The second value is the 
 retail sale amount of the car (without tax.)  The third item is the base 
 price on which the sales person’s commission is determined.  
 Note:  It is important that our data set is sorted by sales person 
 id number.  If the data set is not sorted, the control-break process won't work. 

*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main(){
    ifstream InFile ("carsales.dat");

    if(InFile.fail()) 
        return 1;

    int Records = 0, Employee, LastEmployee =-1;
    double Retail, Base, Commission, Sales = 0.0, TotalCommission = 0.0, EmployeeCommission = 0.0;
    bool loopOnceMore = false;
    cout << "\nEmployee\tRetail\tBase\tCommission" << endl;

    do{
        InFile >> Employee >> Retail >> Base;
        if(LastEmployee==-1) 
            LastEmployee=Employee; //set the first employee
        if(LastEmployee!=Employee || loopOnceMore){
            //output the totals for last employee
            cout << "***Total Commission for " << LastEmployee << ": " << endl << endl;
            TotalCommission+=EmployeeCommission;
            EmployeeCommission=0.0;
        }
        if(loopOnceMore)
            loopOnceMore=false;
        else{
            Commission = (Base*0.3 <= 100) ? 100.0 : Base*0.3; // or max(100.0, Base*0.3);
            cout << Employee << "\t" << Retail << "\t" << Base << "\t" << Commission << endl;
            if(InFile.eof())
                loopOnceMore=true;
        }
    }while(!InFile.eof() || loopOnceMore);



    cout << "Records: " << Records << endl;
    cout << "Total Sales: " << Sales << endl;
    cout << "Total Commissions: " << TotalCommission << endl;

    InFile.close();
    return 0;
}