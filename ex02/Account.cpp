/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:35:29 by baguiar-          #+#    #+#             */
/*   Updated: 2025/02/10 13:35:29 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//public methods

int	Account::getNbAccounts( void )
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits( void )
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << 
			"accounts:" << Account::getNbAccounts() << ";" <<
			"total:" <<  Account::getTotalAmount() << ";" <<
			"deposits:" << Account::getNbDeposits() << ";" <<
			"withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit)
{
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = _nbAccounts;
	this->_nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount += _amount;
	_displayTimestamp();

	std::cout <<
			"index:" << _accountIndex << ";" <<
			"amount:" << _amount << ";" <<
			"created" << std::endl;
}

Account::~Account(void)
{
	this->_displayTimestamp();
	std::cout << 
			"index:" << this->_accountIndex << ";" <<
			"amount:" << checkAmount() << ";" <<
			"closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	int p_amount = this->_amount;

	this->_displayTimestamp();

	if (deposit > 0)
	{
		this->_amount += deposit;
		this->_nbDeposits++;
		_totalAmount += deposit;
		_totalNbDeposits++;

		std::cout <<
				"index:" << this->_accountIndex << ";" <<
				"p_amount:" << p_amount << ";" <<
				"deposit:" << deposit << ";" <<
				"amount:" << this->_amount << ";" <<
				"nb_deposits:" << this->_nbDeposits << std::endl;
	}
	else
	{
		std::cout << 
				"index:" << _accountIndex << ";" <<
				"p_amount" << p_amount << ";" <<
				"deposit:refused" << std::endl;
	}	
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int p_amount = this->_amount;

	_displayTimestamp();

	if (withdrawal > 0 && withdrawal <= p_amount)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;

		std::cout << 
				"index:" << _accountIndex << ";" <<
				"p_amount:" << p_amount << ";" <<
				"withdrawal:" << withdrawal << ";" <<
				"amount:" << this->_amount << ";" <<
				"nb_withdrawals:" << this->_nbWithdrawals << std::endl;

		return true;
	}
	else
	{
		std::cout << 
				"index:" << _accountIndex << ";" <<
				"p_amount:" << p_amount << ";" <<
				"withdrawal:refused" << std::endl;

		return false;
	}
}

int		Account::checkAmount( void ) const
{
	return this->_amount;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout <<
			"index:" << this->_accountIndex << ";" <<
			"amount:" << this->_totalAmount << ";" <<
			"deposits:" << this->_totalNbDeposits << ";" <<
			"withdrawals:" << this->_totalNbWithdrawals << std::endl;

}

//private methods

Account::Account(void){}

void	Account::_displayTimestamp( void )
{
	std::time_t time_now = std::time(0);

	char timestamp[16];
	std::strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", std::localtime(&time_now));

	std::cout << "[" << timestamp << "] ";

}

