/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:04:35 by jholl             #+#    #+#             */
/*   Updated: 2022/03/23 12:32:09 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

Account::Account(int initial_deposit):
_accountIndex(Account::_nbAccounts), _amount(initial_deposit), _nbDeposits(0),
_nbWithdrawals(0)
{
	Account::_nbAccounts++;
	Account::_totalAmount += _amount;
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created";
	std::cout << std::endl;
}

Account::Account(void):
_accountIndex(Account::_nbAccounts), _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{

	Account::_nbAccounts++;
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created";
	std::cout << std::endl;
}

Account::~Account(void)
{
	Account::_nbAccounts--;
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed";
	std::cout << std::endl;
}

int Account::_totalAmount = 0;
int Account::_nbAccounts = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << " accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount;
	std::cout << ";deposits:" << Account::_totalNbDeposits << ":withdrawals:";
	std::cout << Account::_totalNbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
	char buf[80];
	std::time_t time(std::time(NULL));
	strftime(buf, 80, "%Y%m%d_%H%M%S", std::localtime(&time));
	std::cout << "[" << buf << "]";	
}

void	Account::makeDeposit(int	deposit)
{
	_nbDeposits++;
	Account::_totalNbDeposits++;
	_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount - deposit 
	<< ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" 
	<< _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (_amount < withdrawal)
	{
		Account::_displayTimestamp();
		std::cout << " index:" << _accountIndex << ";p_amount:" << _amount 
		<< ";withdrawal:refused" << std::endl;
		return (false);
	}
	_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount + withdrawal
	<< ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" 
	<< _nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount(void) const
{
	return(_amount);
}

void	Account::displayStatus(void) const 
{
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:"
	<< _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}
