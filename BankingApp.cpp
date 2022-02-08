// BankingApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BankingApp.h"
#include <vector>
#include <iomanip>
using namespace std;

void Bank::dataInput() {
    cout << "Initial Investment Amount: " << endl;
    cin >> investment;
    cout << "Monthly Deposit: " << endl;
    cin >> deposit;
    cout << "Annual Interest: " << endl;
    cin >> interest;
    cout << "Number of years: " << endl;
    cin >> years;
    system("pause");       // Windows-specific command that tells platform to pause program
    cout << endl;
    if (cin.get()) {        // If any key is entered, displayInput function is called
        displayInput();     
    }

}

void Bank::displayInput() {
    cout << "Initial Investment Amount: " << "$" << investment << endl;
    cout << "Monthly Deposit: " << "$" << deposit << endl;
    cout << "Annual Interest: " << interest << "%" << endl;
    cout << "Number of years: " << years << endl;
    system("pause");
    cout << endl;
    reportWithoutMonthlyPay();
}

void Bank::reportWithoutMonthlyPay() {
    year_numbers.resize(years);     // Sets the size of vector year_numbers based on user input of years
    month_numbers.resize(12);       // Sets the size of vector month_numbers to 12
    interest = interest / 100;
    year_end_interest = 0;
    year_end_balance = investment;
    cout << "   Balance and Interest Without Additional Monthly Deposit   " << endl;
    cout << "=============================================================" << endl;
    cout << "Year    Year End Balance    Year End Earned Interest" << endl;
    cout << "-------------------------------------------------------------" << endl;
    // Iterates through years 
    for (int i = 0; i < year_numbers.size(); i++) {
        year_numbers[i] = i + 1;
        year_end_interest = 0;
        year_end_balance += year_end_interest;
        // Iterates through months
        for (int j = 0; j < month_numbers.size(); j++) {
            monthly_interest = year_end_balance * (interest / (double)12);
            year_end_interest += monthly_interest; 
            year_end_balance += monthly_interest;
            month_numbers[j]++;
        }
        cout << year_numbers[i] << "        $" << fixed << setprecision(2) << year_end_balance << "               $" << year_end_interest << endl;
        year_numbers[i]++;
    }
    cout << endl;
    system("pause");
    reportWithMonthlyPay();
}

void Bank::reportWithMonthlyPay() {
    year_numbers.resize(years);     // Sets the size of vector year_numbers based on user input of years
    month_numbers.resize(12);       // Sets the size of vector month_numbers to 12
    year_end_interest = 0;
    year_end_balance = investment;
    cout << "   Balance and Interest With Additional Monthly Deposit   " << endl;
    cout << "==========================================================" << endl;
    cout << "Year     Year End Balance   Year End Earned Interest" << endl;
    cout << "----------------------------------------------------------" << endl;
    for (int i = 0; i < year_numbers.size(); i++) {
        year_numbers[i] = i + 1;
        year_end_interest = 0;
        for (int j = 0; j < month_numbers.size(); j++) {
            year_end_balance += deposit;
            monthly_interest = year_end_balance * (interest / (double)12);
            year_end_balance += monthly_interest;
            year_end_interest += monthly_interest;
            month_numbers[j]++;
        }
        cout << year_numbers[i] << "        $" << fixed << setprecision(2) << year_end_balance << "               $" << year_end_interest << endl;
        year_numbers[i]++;
    }
}

int main()
{
    Bank userInput;

    userInput.dataInput();
}
