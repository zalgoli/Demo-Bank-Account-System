#pragma once

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

enum class IInvestmentStrategy
{
	Safe,
	Balanced,
	Risky
};

class SavingsAccount : public Account
{
private:
	double m_interest_rate{};
	int m_monthly_fee{};
	int m_saving_period_years{};
	int m_monthly_deposit{};
	IInvestmentStrategy m_saving_strategy;

protected:
	friend std::ostream& operator<<(std::ostream& out, SavingsAccount& s);

public:
	SavingsAccount(const std::string& first = "", const std::string& last = "",
		IInvestmentStrategy Strategy = IInvestmentStrategy::Balanced, int period_years = 5, int monthly_deposit = 1000);
	int getYield();
	int getInterest();
	const std::string& getStrategy();

};


#endif