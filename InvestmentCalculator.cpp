#include "InvestmentCalculator.h"  // Includes the header file that defines the InvestmentCalculator class

// Constructor to initialize investment details from the user
InvestmentCalculator::InvestmentCalculator(double t_initialInvestmentAmount, double t_monthlyDeposit, double t_annualInterestRate, int t_numberOfYears) : 
    m_initialInvestmentAmount(t_initialInvestmentAmount),  // Initialize the initial investment amount
    m_monthlyDeposit(t_monthlyDeposit),                    // Initialize the monthly deposit
    m_annualInterestRate(t_annualInterestRate),            // Initialize the annual interest rate
    m_numberOfYears(t_numberOfYears) {                      // Initialize the number of years for the investment
}

// Helper method to display results in a table
void InvestmentCalculator::displayResults(const std::vector<std::tuple<int, double, double>>& results, const std::string& header) const {
    
    std::cout << "\n" << header << "\n";  // Prints the header of the table
    // Printing two separator line
    std::cout << "------------------------------------------------------\n";
    std::cout << "------------------------------------------------------\n";
    std::cout << std::left << std::setw(10) << "Year" << std::setw(20) << "Year End Balance" << "Year End Earned Interest\n";  // Column headers
    std::cout << "------------------------------------------------------\n";  // Prints a separator line between header and data rows

    // Iterates over the results vector, which contains tuples of year, balance, and interest
    for (const auto& [year, balance, interest] : results) {
        std::cout << std::setw(10) << year  // Print the year with width of 10
                  << "$" << std::setw(19) << std::fixed << std::setprecision(2) << balance  // Print balance rounded up
                  << "$" << interest << "\n";  // Print interest
    }
}

// This method calculates investment growth without monthly deposits.
void InvestmentCalculator::calculateWithoutDeposits() const {
    std::vector<std::tuple<int, double, double>> results;  // Vector to store results of each year
    double openingBalance = m_initialInvestmentAmount;     // Set initial balance to the user's investment amount

    // Loop over each year of the investment period
    for (int year = 1; year <= m_numberOfYears; ++year) {
        double yearlyInterest = openingBalance * (m_annualInterestRate / 100);  // Calculate interest for the year
        double closingBalance = openingBalance + yearlyInterest;  // Calculate the balance at the end of the year

        results.emplace_back(year, closingBalance, yearlyInterest);  // Add the results for this year to the results vector
        openingBalance = closingBalance;  // Set opening balance for the next year to the closing balance
    }

    // Call displayResults to show the results in a table format
    displayResults(results, "Balance and Interest Without Additional Monthly Deposits");
}

// Calculates and displays balances with monthly deposits
void InvestmentCalculator::calculateWithDeposits() const {
    std::vector<std::tuple<int, double, double>> results;  // Vector to store results of each year
    double openingBalance = m_initialInvestmentAmount;     // Set initial balance to the user's investment amount

    // Loop over each year of the investment period
    for (int year = 1; year <= m_numberOfYears; ++year) {
        double yearlyInterest = 0;  // Variable to accumulate total interest for the year

        // Loop over each month of the year
        for (int month = 1; month <= 12; ++month) {
            // Calculate the monthly interest based on the current balance and monthly deposit
            double monthlyInterest = (openingBalance + m_monthlyDeposit) * ((m_annualInterestRate / 100) / 12);
            openingBalance += m_monthlyDeposit + monthlyInterest;  // Update balance after adding monthly deposit and interest
            yearlyInterest += monthlyInterest;  // Accumulate the monthly interest into yearly interest
        }

        results.emplace_back(year, openingBalance, yearlyInterest);  // Add the results for this year to the results vector
    }

    // Call displayResults to show the results in a table format
    displayResults(results, "Balance and Interest With Additional Monthly Deposits");
}

// Prompts the user to decide whether to restart the program.
bool InvestmentCalculator::restartCalculator() {
    char userChoice;  // Variable to store the user's choice

    do {
        std::cout << "\nWould you like to test different values? (y/n): ";  // Prompt the user
        std::cin >> userChoice;  // Read the user's input

        // If the user enters 'y' or 'Y', restart the calculator
        if (userChoice == 'y' || userChoice == 'Y') {
            std::cout << "Restarting program...\n";  // Inform the user the program is restarting
            return true;  // Return true to restart
        } 
        // If the user enters 'n' or 'N', exit the program
        else if (userChoice == 'n' || userChoice == 'N') {
            std::cout << "Thank you for using Airgead Banking Investment Calculator!\n";  // Thank the user
            return false;  // Return false to end the program
        } 
        // If the user enters an invalid option, prompt them again
        else {
            std::cout << "Invalid option. Please type 'y' for yes or 'n' for no.\n";  // Error message for invalid input
        }
    } while (true);  // Repeat until a valid choice is entered
}
