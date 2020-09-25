/*
4-2: Conditionals 
    You work for a store that ships products throughout the United States. Write a program 
    to input a customer’s total purchase amount. Tax on the purchase is 7.5%. If the customer’s 
    purchase is $50.00 or more, shipping is free. Otherwise, shipping is a flat $5.99. 
    The program should output the purchase amount, tax, shipping, and total.
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    double PurchaseAmount;
    double TaxPaid;
    double ShippingCost = 5.99;
    const double TAX_PERCENT = 7.5;
    int RightJustifyOffset = 25;
    string BuisnessName = "Buisness Shipping LLC";

    cout << "\n\nWelcome to " << BuisnessName << endl;
    cout << "Enter the total purchase amount: ";
    cin >> PurchaseAmount;

    TaxPaid = PurchaseAmount * (TAX_PERCENT/100.0);

    if(50.0 <= PurchaseAmount){
        ShippingCost = 0.0;
        cout << "Congratulations! orders $50.00 and over ship for free!" << endl;
    }

    cout << setprecision(2) << fixed;
    cout << setw(RightJustifyOffset) << "Purchase amount: $" << PurchaseAmount << endl;
    cout << setw(RightJustifyOffset) << "Tax: $" << TaxPaid << endl; 
    cout << setw(RightJustifyOffset) << "Shipping: $" << ShippingCost << endl;
    cout << setw(RightJustifyOffset) << "Grand Total: $" << PurchaseAmount+TaxPaid+ShippingCost << endl;
    
    cout << "Thank you for choosing " << BuisnessName << "\nHave a wonderful day!\n" << endl;
    return 0;
}
