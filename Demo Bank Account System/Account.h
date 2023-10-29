#pragma once

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <string_view>
#include <iostream>

class Account
{
protected:
	int m_account_balance = 0;
	int m_account_number{};
	int m_account_pin{};

	std::string m_name_first{};
	std::string m_name_last{};
	friend std::ostream& operator<<(std::ostream& out, Account& a);

public:
	Account(const std::string& first_name = "", const std::string& last_name = "");
	int getBalance();
	const std::string& getNameFirst();
	const std::string& getNameLast();
	int getAccountNumber();
	void Deposit(int deposit_amount, int pin = 1);
	void Withdraw(int withdrawal_amount, int pin = 1);
	Account* getAccount();
	void setPIN(int account_number, const std::string& first, const std::string& last, int pin);

};

#endif