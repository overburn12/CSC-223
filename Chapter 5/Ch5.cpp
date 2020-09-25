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

    cout << "\nEmployee\tRetail\tBase\tCommission" << endl;

    do{

    }while(!InFile.eof());

    cout << "Records: " << Records << endl;
    cout << "Total Sales: " << Sales << endl;
    cout << "Total Commissions: " << TotalCommission << endl;

    InFile.close();
    return 0;
}