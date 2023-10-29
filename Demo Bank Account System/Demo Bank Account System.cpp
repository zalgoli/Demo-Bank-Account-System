#include <iostream>
#include "SavingsAccount.h"

int main()
{

    // BASE ACCOUNT TESTS
    Account account1{ "Yaba","Loboo" };
    std::cout << account1;
    int deposit_amount = 500;
    account1.Deposit(deposit_amount);
    account1.setPIN(1, "Yaba", "Loboo", 1234);
    account1.Deposit(deposit_amount, 1234);
    std::cout << "Current balance: " << account1.getBalance() << "\n\n";


    // SAVINGS ACCOUNT TESTS
    SavingsAccount savingsaccount1{ "Flen", "Trindy", IInvestmentStrategy::Risky, 6, 1000};
    std::cout << savingsaccount1;
    savingsaccount1.setPIN(1, "Flen", "Trindy", 1234);
    savingsaccount1.Deposit(800, 1234);
    savingsaccount1.Withdraw(450, 1234);
    std::cout << "Total yield on account: " << savingsaccount1.getYield() << "\n";
    std::cout << "Of which interest is: " << savingsaccount1.getInterest() << "\n";
    std::cout << "Investment strategy: " << savingsaccount1.getStrategy();

}

