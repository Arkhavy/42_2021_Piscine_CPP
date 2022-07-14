/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:51:09 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/14 13:36:07 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Account.hpp>


/* ************************************************************************** */
/* Public member functions */
/* ************************************************************************** */
Account::Account(int initial_deposit)
{
	this->_nbAccounts = 0;
	this->_totalAmount = 0;
	this->_totalNbDeposits = 0;
	this->_totalNbWithdrawals = 0;

	this->_accountIndex = 0;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	return ;
}

Account::~Account() {return ;}

/* ************************************************************************** */
/* Getters functions */
/* ************************************************************************** */
static int	Account::getNbAccounts() {return (this->_nbAccounts);}

static int	Account::getTotalAmount() {return (this->_totalAmount);}

static int	Account::getNbDeposits() {return (this->_nbDeposits);}

static int	Account::getNbWithdrawals() {return (this->_nbWithdrawals);}
/* ************************************************************************** */

static void	Account::displayAccountsInfos() {}

void	Account::makeDeposit(int deposit) {}

bool	Account::makeWithdrawal(int withdrawal) {}

int		Account::checkAmount() const {}

void	Account::displayStatus() const {}

/* ************************************************************************** */
/* Private member functions */
/* ************************************************************************** */
Account::Account()
{
	this->_nbAccounts = 0;
	this->_totalAmount = 0;
	this->_totalNbDeposits = 0;
	this->_totalNbWithdrawals = 0;

	this->_accountIndex = 0;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	return ;
}

static void	Account::_displayTimestamp() {}
