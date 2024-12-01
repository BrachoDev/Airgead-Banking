#ifndef AIRGEAD_BANKING_INVESTMENT_CALCULATOR_H_
#define AIRGEAD_BANKING_INVESTMENT_CALCULATOR_H_

#include <iostream>
#include <vector>
#include <iomanip> // For formatting output

// Class for Airgead Banking Investment Calculator to calculate investment growth.
class InvestmentCalculator {
private:
    
    // User's initial investment amount
    double m_initialInvestmentAmount; 
    // User's monthly deposit
    double m_monthlyDeposit;
    // Annual interest rate (percentage)
    double m_annualInterestRate;
    // Number of years for the investment
    int m_numberOfYears;

    // Helper function to display the results of the investment calculations
    // in a tabular format.
    void displayResults(const std::vector<std::tuple<int, double, double>>& results, const std::string& header) const;

public:

    // Constructor to initialize the calculator with the provided values.
    InvestmentCalculator(double t_initialInvestmentAmount, double t_monthlyDeposit, double t_annualInterestRate, int t_numberOfYears);

    // Method to calculate and display balances without monthly deposits
    void calculateWithoutDeposits() const;

    // Method to calculate and display balances with monthly deposits
    void calculateWithDeposits() const;

    // Method to prompt user for new values and restart calculations
    bool restartCalculator();
};

#endif