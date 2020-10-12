/*
Write a program that computes the amount of money the computer club will recieve 
from proceeds of their granola bar sales project. Allow the user to enter the 
number of cases sold and the sale price per bar. Each case contains 12 bars; 
each case is purchased at $5.00 per case from a local vendor. The club is required 
to give the student government association 10% of their earnings. Display their 
proceeds formatted with currency. Wite appropriate methods for your solution.
*/

#include <iostream>
#include <iomanip>
using namespace std;

const int BARS_PER_CASE = 12;
const double BAR_WHOLESALE_COST = 5.00;

int main(){
    int casesSold;
    double barRetail, purchaseCost, grossSales, netSales, studentGovComission;

    cout << "How many cases have been sold: ";
    cin >> casesSold;

    cout << "Retail price of 1 bar: ";
    cin >> barRetail;

    purchaseCost = casesSold * BARS_PER_CASE * BAR_WHOLESALE_COST;
    grossSales = casesSold * BARS_PER_CASE * barRetail;
    studentGovComission = (grossSales - purchaseCost) * 0.1;
    netSales = grossSales - purchaseCost - studentGovComission;

    cout << fixed << setprecision(2);
    cout << "Total bars sold in " << casesSold << " cases: " << casesSold * BARS_PER_CASE << endl;
    cout << "Cost for purchasing cases from local vendor: $" << purchaseCost << endl;
    cout << "Total revenue collected: $" << grossSales << endl;
    cout << "Net sales: $" << (grossSales - purchaseCost) << endl;
    cout << "Comission for student government: $" << studentGovComission << endl;
    cout << "Money earned: $" << netSales << endl;

    return 0;
}