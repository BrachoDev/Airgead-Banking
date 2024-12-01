#ifndef AIRGEAD_BANKING_INVESTMENT_CALCULATOR_H_
#define AIRGEAD_BANKING_INVESTMENT_CALCULATOR_H_

#include <iostream>
#include <vector>
#include <iomanip> // For formatting output

// Class for Airgead Banking Investment Calculator
class InvestmentCalculator {
private:
    
    double m_initialInvestmentAmount; // Initial investment amount
    double m_monthlyDeposit;          // Monthly deposit amount
    double m_annualInterestRate;      // Annual interest rate in percentage
    int m_numberOfYears;              // Number of years for investment

public:

    // Constructor
    InvestmentCalculator(double t_initialInvestmentAmount, double t_monthlyDeposit,
                         double t_annualInterestRate, int t_numberOfYears);

    // Method to calculate and display balances without monthly deposits
    void calculateWithoutDeposits() const;

    // Method to calculate and display balances with monthly deposits
    void calculateWithDeposits() const;

    // Method to prompt user for new values and restart calculations
    bool restartCalculator();
};

#endif
