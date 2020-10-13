/*
Write a program that calculates and prints the take-home pay for a commissioned sales employee.
Allow the user to enter values for the name of the employee and the sales amount for the week. 
Employees recieve 7% of the total sales. Federal tax rate is 18%. Retirement contribution is 10%. 
Social Security tax rate is 6%. Use appropriate constants.
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const double FEDERAL_TAX_RATE = 18.0/100.0;
const double SOCIAL_SECURITY_TAX_RATE = 6.0/100.0;
const double RETIREMENT_CONTRIBUTION_RATE = 10.0/100.0;
const double EMPLOYEE_COMISSION_RATE = 7.0/100.0;

struct PayCheck{
    double GrossPay;
    double FederalTax;
    double SocialSecurityTax;
    double RetirmentContribution;
    double NetPay;
};

struct SalesEmployee{
    string Name;
    double WeeklySales;
    PayCheck WeeklyPaycheck;
};

void CalculatePaycheck(SalesEmployee &tmpEmployee){
    PayCheck tmpCheck;

    tmpCheck.GrossPay = tmpEmployee.WeeklySales * EMPLOYEE_COMISSION_RATE;
    tmpCheck.FederalTax = tmpCheck.GrossPay * FEDERAL_TAX_RATE;
    tmpCheck.SocialSecurityTax = tmpCheck.GrossPay * SOCIAL_SECURITY_TAX_RATE;
    tmpCheck.RetirmentContribution = tmpCheck.GrossPay * RETIREMENT_CONTRIBUTION_RATE;

    tmpCheck.NetPay = tmpCheck.GrossPay 
                    - tmpCheck.FederalTax 
                    - tmpCheck.SocialSecurityTax
                    - tmpCheck.RetirmentContribution;

    tmpEmployee.WeeklyPaycheck = tmpCheck;
}

void PrintPaycheck(SalesEmployee tmpEmployee){
    int w = 40; 
    int p = to_string(tmpEmployee.WeeklySales).length();

    cout << fixed << setprecision(2) << endl;
    cout << setw(w) << "Employee name: " << tmpEmployee.Name << endl;

    cout << setw(w) << "Total sales generated for the week: " 
         << setw(p) << tmpEmployee.WeeklySales << endl;

    cout << setw(w) << "Gross pay for the week: " 
         << setw(p) << tmpEmployee.WeeklyPaycheck.GrossPay << endl;

    cout << setw(w) << "Federal tax with-held: "
         << setw(p) << tmpEmployee.WeeklyPaycheck.FederalTax << endl;

    cout << setw(w) << "Social security tax with-held: "
         << setw(p) << tmpEmployee.WeeklyPaycheck.SocialSecurityTax << endl;

    cout << setw(w) << "Retirement fund contribution: "
         << setw(p) << tmpEmployee.WeeklyPaycheck.RetirmentContribution << endl;

    cout << setw(w) << "Take-home pay for the week: "
         << setw(p) << tmpEmployee.WeeklyPaycheck.NetPay << endl;
}

int main(){
    SalesEmployee Employee1;

    cout << "Enter a name for the sales employee: ";
    getline(cin,Employee1.Name);

    cout << "Enter the total sales for the week from " << Employee1.Name << ": ";
    cin >> Employee1.WeeklySales;

    CalculatePaycheck(Employee1);
    PrintPaycheck(Employee1);

    return 0;
}