#include "InvestmentCalculator.h"

// Constructor to initialize investment details from the user
InvestmentCalculator::InvestmentCalculator(double t_initialInvestmentAmount, double t_monthlyDeposit,double t_annualInterestRate, int t_numberOfYears): 
    m_initialInvestmentAmount(t_initialInvestmentAmount),
    m_monthlyDeposit(t_monthlyDeposit),
    m_annualInterestRate(t_annualInterestRate),
    m_numberOfYears(t_numberOfYears) {}

// Helper method to display results in a table
void InvestmentCalculator::displayResults(const std::vector<std::tuple<int, double, double>>& results, const std::string& header) const {
    
    std::cout << "\n" << header << "\n";
    std::cout << "------------------------------------------------------\n";
    std::cout << "------------------------------------------------------\n";
    std::cout << std::left << std::setw(10) << "Year" << std::setw(20) << "Year End Balance" << "Year End Earned Interest\n";
    std::cout << "------------------------------------------------------\n";

    for (const auto& [year, balance, interest] : results) {
        std::cout << std::setw(10) << year
                  << "$" << std::setw(19) << std::fixed << std::setprecision(2) << balance
                  << "$" << interest << "\n";
    }
}

// This method calculates investment growth without monthly deposits.
void InvestmentCalculator::calculateWithoutDeposits() const {
    std::vector<std::tuple<int, double, double>> results;
    double openingBalance = m_initialInvestmentAmount;

    for (int year = 1; year <= m_numberOfYears; ++year) {
        double yearlyInterest = openingBalance * (m_annualInterestRate / 100);
        double closingBalance = openingBalance + yearlyInterest;

        results.emplace_back(year, closingBalance, yearlyInterest);
        openingBalance = closingBalance;
    }

    displayResults(results, "Balance and Interest Without Additional Monthly Deposits");
}

// Calculates and displays balances with monthly deposits
void InvestmentCalculator::calculateWithDeposits() const {
    std::vector<std::tuple<int, double, double>> results;
    double openingBalance = m_initialInvestmentAmount;

    for (int year = 1; year <= m_numberOfYears; ++year) {
        double yearlyInterest = 0;

        for (int month = 1; month <= 12; ++month) {
            double monthlyInterest = (openingBalance + m_monthlyDeposit) * ((m_annualInterestRate / 100) / 12);
            openingBalance += m_monthlyDeposit + monthlyInterest;
            yearlyInterest += monthlyInterest;
        }

        results.emplace_back(year, openingBalance, yearlyInterest);
    }

    displayResults(results, "Balance and Interest With Additional Monthly Deposits");
}

// Prompts the user to decide whether to restart the program.
bool InvestmentCalculator::restartCalculator() {
    char userChoice;

    do {
        std::cout << "\nWould you like to test different values? (y/n): ";
        std::cin >> userChoice;

        if (userChoice == 'y' || userChoice == 'Y') {
            std::cout << "Restarting program...\n";
            return true;
        } else if (userChoice == 'n' || userChoice == 'N') {
            std::cout << "Thank you for using Airgead Banking Investment Calculator!\n";
            return false;
        } else {
            std::cout << "Invalid option. Please type 'y' for yes or 'n' for no.\n";
        }
    } while (true);
}
