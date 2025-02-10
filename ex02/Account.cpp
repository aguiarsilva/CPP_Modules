/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Accoutn.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:41:09 by baguiar-          #+#    #+#             */
/*   Updated: 2025/02/10 12:41:09 by baguiar-         ###   ########.fr       */
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

//private methods

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_nbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_nbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	Account::displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";"
			  << "total:" <<  Account::getTotalAmount() << ";"
			  << "deposits:" << Account::getNbDeposits() << ";"
			  << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

	Account::Account(int initial_deposit)
	{
		this->initial_deposit = initial_deposit;
	}

	Account::~Account(void)
	{
		return;
	}

	Account::Account(void)
	{

	}

	void	Account::makeDeposit( int deposit );
	bool	Account::makeWithdrawal( int withdrawal );
	int		Account::checkAmount( void ) const;
	void	Account::displayStatus( void ) const;
	void	Account::_displayTimestamp( void );