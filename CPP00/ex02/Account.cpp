/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:51:09 by ljohnson          #+#    #+#             */
/*   Updated: 2022/11/09 14:08:22 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Account.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>

static std::string	ft_to_string(int nb)
{
	std::ostringstream	oss;

	oss << nb;
	return (oss.str());
}

static std::string	ft_add_value(int nb)
{
	std::string	str;

	str = ft_to_string(nb);
	if (str.length() < 2)
	{
		str = "0";
		str += ft_to_string(nb);
	}
	return (str);
}

/* ************************************************************************** */
/* Private Static member variables & functions */
/* ************************************************************************** */
int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;


void	Account::_displayTimestamp(void)
{
	std::time_t	raw_time;
	std::tm*	current_time;
	std::string	display;
	
	raw_time = std::time(0);
	current_time = std::localtime(&raw_time);
	display = ft_to_string(current_time->tm_year + 1900);
	display += ft_add_value(current_time->tm_mon + 1);
	display += ft_add_value(current_time->tm_mday);
	display += "_";
	display += ft_add_value(current_time->tm_hour);
	display += ft_add_value(current_time->tm_min);
	display += ft_add_value(current_time->tm_sec);
	std::cout << "[" << display << "] ";
	// std::cout << "[19920104_091532]" << " ";
	return ;
}

/* ************************************************************************** */
/* Public Static member variables & functions */
/* ************************************************************************** */
int	Account::getNbAccounts(void) {return (Account::_nbAccounts);}

int	Account::getTotalAmount(void) {return (Account::_totalAmount);}

int	Account::getNbDeposits(void) {return (Account::_totalNbDeposits);}

int	Account::getNbWithdrawals(void) {return (Account::_totalNbWithdrawals);}

void	Account::displayAccountsInfos(void)
{
	std::cout << std::endl;
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";";
	std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" << Account::_totalNbDeposits << ";";
	std::cout << "withdrawals:" << Account::_totalNbWithdrawals;
}

/* ************************************************************************** */
/* Public member functions */
/* ************************************************************************** */
Account::Account(int initial_deposit)
{
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += initial_deposit;
	
	if (this->_accountIndex > 0)
		std::cout << std::endl;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created";
	return ;
}

Account::~Account(void)
{
	std::cout << std::endl;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed";
	return ;
}

void	Account::makeDeposit(int deposit)
{
	std::cout << std::endl;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	std::cout << "amount:" << this->_amount << ";";
	this->_nbDeposits++;
	std::cout << "nb_deposits:" << this->_nbDeposits;

	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	std::cout << std::endl;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (withdrawal < this->checkAmount())
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << this->_amount << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals;
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		return (true);
	}
	else
	{
		std::cout << "withdrawal:refused";
		return (false);
	}

}

int		Account::checkAmount(void) const {return (this->_amount);}

void	Account::displayStatus(void) const
{
	std::cout << std::endl;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals;
}

/* ************************************************************************** */
/* Private member functions */
/* ************************************************************************** */
Account::Account(void) {return ;}

