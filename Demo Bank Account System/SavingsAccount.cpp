#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(const std::string& first, const std::string& last, IInvestmentStrategy Strategy, int period_years, int monthly_deposit)
{
	m_saving_strategy = Strategy;

	static int current_account_number{};
	++current_account_number;
	m_account_number = current_account_number;

	m_name_first = first;
	m_name_last = last;

	switch (Strategy)
	{
	case IInvestmentStrategy::Safe:
		m_interest_rate = 1.01;
		m_monthly_fee = 100;
		break;
	case IInvestmentStrategy::Balanced:
		m_interest_rate = 1.03;
		m_monthly_fee = 125;
		break;
	case IInvestmentStrategy::Risky:
		m_interest_rate = 1.065;
		m_monthly_fee = 150;
		break;
	}

	m_saving_period_years = period_years;
	m_monthly_deposit = monthly_deposit;
}

std::ostream& operator<<(std::ostream& out, SavingsAccount& s)
{
	out << "Savings Account nr. " << s.getAccountNumber() << " under the name of " << s.getNameFirst()
		<< " " << s.getNameLast() << ".\n";
	return out;
}

int SavingsAccount::getYield()
{
	int amount = m_account_balance;

	for (int i = m_saving_period_years; i > 0; --i)
	{
		amount += 12 * (m_monthly_deposit - m_monthly_fee);
		amount *= m_interest_rate;
	}
	return amount;
}

int SavingsAccount::getInterest()
{
	int saving_months = m_saving_period_years * 12;
	int monthly_increment = m_monthly_deposit - m_monthly_fee;

	if (monthly_increment > 0)
	{
		return getYield() - saving_months * monthly_increment;
	}

}

const std::string& SavingsAccount::getStrategy()
{
	static const std::string safe = "Safe";
	static const std::string balanced = "Balanced";
	static const std::string risky = "Risky";


	switch (m_saving_strategy)
	{
	case IInvestmentStrategy::Safe:
		return safe;
	case IInvestmentStrategy::Balanced:
		return balanced;
	case IInvestmentStrategy::Risky:
		return risky;
	}
}