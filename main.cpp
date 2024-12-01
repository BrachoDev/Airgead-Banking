#include "InvestmentCalculator.h"

int main() {
    bool restart = false;

    do {
        try {
            // Display welcome message
            std::cout << "Welcome to Airgead Banking Investment Calculator!\n";

            // Gather user input
            double initialInvestment, monthlyDeposit, annualInterest;
            int numberOfYears;

            std::cout << "Enter Initial Investment Amount: $";
            std::cin >> initialInvestment;

            std::cout << "Enter Monthly Deposit: $";
            std::cin >> monthlyDeposit;

            std::cout << "Enter Annual Interest Rate (%): ";
            std::cin >> annualInterest;

            std::cout << "Enter Number of Years: ";
            std::cin >> numberOfYears;

            // Create InvestmentCalculator object
            InvestmentCalculator calculator(initialInvestment, monthlyDeposit, annualInterest, numberOfYears);

            // Display results
            calculator.calculateWithoutDeposits();
            calculator.calculateWithDeposits();

            // Ask if the user wants to restart
            restart = calculator.restartCalculator();
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    } while (restart);

    return 0;
}
