#include "InvestmentCalculator.h"

int main() {
    bool restart = false;  // Variable to control whether the program should restart

    do {
        try {
            // Display welcome message to the user
            std::cout << "Welcome to Airgead Banking Investment Calculator!\n";

            // Declare variables to store user input
            double initialInvestment, monthlyDeposit, annualInterest;
            int numberOfYears;

            // Prompt the user for the initial investment amount
            std::cout << "Enter Initial Investment Amount: $";
            std::cin >> initialInvestment;

            // Prompt the user for the monthly deposit amount
            std::cout << "Enter Monthly Deposit: $";
            std::cin >> monthlyDeposit;

            // Prompt the user for the annual interest rate
            std::cout << "Enter Annual Interest Rate (%): ";
            std::cin >> annualInterest;

            // Prompt the user for the number of years for the investment
            std::cout << "Enter Number of Years: ";
            std::cin >> numberOfYears;

            // Create an instance of the InvestmentCalculator class with user input
            InvestmentCalculator calculator(initialInvestment, monthlyDeposit, annualInterest, numberOfYears);

            // Call methods to calculate and display the results without monthly deposits
            calculator.calculateWithoutDeposits();

            // Call methods to calculate and display the results with monthly deposits
            calculator.calculateWithDeposits();

            // Ask the user if they want to restart the program
            restart = calculator.restartCalculator();
        } catch (const std::exception& e) {  // Catch any exceptions thrown during the execution
            std::cerr << "Error: " << e.what() << "\n";  // Print error message to the user
        }
    } while (restart);  // Repeat the program if the user chooses to restart

    return 0;
}
