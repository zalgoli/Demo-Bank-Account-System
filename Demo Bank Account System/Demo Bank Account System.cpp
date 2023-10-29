#include <iostream>
#include "Account.h"

int main()
{

    // BASE ACCOUNT TESTS
    Account account1{ "Zoltan","Gal" };
    int deposit_amount = 500;
    account1.Deposit(deposit_amount);
    account1.setPIN(1, "Zoltan", "Gal", 1234);
    account1.Deposit(deposit_amount, 1234);
    std::cout << "Current balance: " << account1.getBalance() << "\n";

}

