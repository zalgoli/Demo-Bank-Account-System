#include "Account.h"


Account::Account(const std::string& first_name, const std::string& last_name)
{
	static int current_account_number{};
	++current_account_number;

	m_account_balance = 0;
	m_account_number = current_account_number;

	m_name_first = first_name;
	m_name_last = last_name;

}

int Account::getBalance() 
{ 
	return m_account_balance;
}

const std::string& Account::getNameFirst() 
{ 
	return m_name_first; 
}

const std::string& Account::getNameLast()
{
	return m_name_last;
}

int Account::getAccountNumber()
{
	return m_account_number;
}

void Account::Deposit(int deposit_amount, int pin)
{
	std::cout << "Attempting to deposit " << deposit_amount << "...\n";
	if (pin == m_account_pin)
	{
		if (deposit_amount >= 0)
		{
			m_account_balance += deposit_amount;
			std::cout << "Deposited " << deposit_amount << ".\n";
		}
		else
		{
			std::cout << "Invalid deposit amount.\n";
		}
	}
	else { std::cout << "Invalid PIN.\n"; }
}

void Account::Withdraw(int withdrawal_amount, int pin)
{
	std::cout << "Attempting to withdraw " << withdrawal_amount << "...\n";
	if (pin == m_account_pin)
	{
		if (m_account_balance >= withdrawal_amount && withdrawal_amount > 0)
		{
			m_account_balance -= withdrawal_amount;
		}
		else
		{
			std::cout << "Invalid balance.\n";
		}
	}
	else { std::cout << "Invalid PIN.\n"; }
}

Account* Account::getAccount()
{
	return this;
}


std::ostream& operator<<(std::ostream& out, Account& a)
{
	out << "Account nr. " << a.getAccountNumber() << ". under the name of "
		<< a.getNameFirst() << " " << a.getNameLast() << ".\n";

	return out;
}

void Account::setPIN(int account_number, const std::string& first, const std::string& last, int pin)
{
	std::cout << "Attempting to modify PIN code.\n";
	bool match = account_number == m_account_number && first == m_name_first && last == m_name_last;
	if (match)
	{
		m_account_pin = pin;
		std::cout << "PIN code successfully modified.\n";
	}
	else
	{
		std::cout << "Invalid credentials.\n";
	}
}