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
	std::cout << "accounts:" << Account::getNbAccounts() << ";"
			  << "total:" <<  Account::getTotalAmount() << ";"
			  << "deposits:" << Account::getNbDeposits() << ";"
			  << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit)
{
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount += _amount;
	_displayTimestamp();
}

Account::~Account(void)
{
	return;
}

void	Account::makeDeposit( int deposit );
bool	Account::makeWithdrawal( int withdrawal );

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
	 "withdrawals:" << this->_totalNbWithdrawals << ";" << std::endl;

}

//private methods

Account::Account(void)
{

}

void	Account::_displayTimestamp( void )
{
	std::time_t time_now = std::time(0);

	char timestamp[100];
	std::strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", std::localtime(&time_now));

	std::cout << "[" << timestamp << "]" << std::endl;

}

