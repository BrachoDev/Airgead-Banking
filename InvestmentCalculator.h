#ifndef AIRGEAD_BANKING_INVESTMENT_CALCULATOR_H_
#define AIRGEAD_BANKING_INVESTMENT_CALCULATOR_H_

#include <iostream>
#include <vector>    // Includes the vector container library for holding results
#include <iomanip>   // Includes library for output formatting, e.g., setting decimal precision

// Class for Airgead Banking Investment Calculator to calculate investment growth.
class InvestmentCalculator {

private:
    
    double m_initialInvestmentAmount;  // User's initial investment amount
    double m_monthlyDeposit;           // User's monthly deposit
    double m_annualInterestRate;       // Annual interest rate as a percentage
    int m_numberOfYears;               // Number of years for the investment

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

#endif  // End of the header