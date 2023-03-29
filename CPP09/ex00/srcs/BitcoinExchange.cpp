/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:17:50 by ljohnson          #+#    #+#             */
/*   Updated: 2023/03/29 14:38:39 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange()
{
	this->data.clear();
}

/* ************************************************************************** */
/* Operator Overloads */
/* ************************************************************************** */
BitcoinExchange&	BitcoinExchange::operator=(BitcoinExchange const& rhs)
{
	this->data = rhs.data;
	return (*this);
}

float&	BitcoinExchange::operator[](std::string const& key)
{
	for (std::map<std::string, float>::iterator it = this->data.begin(); it != this->data.end(); it++)
	{
		if (key == it->first)
			return (this->data[key]);
	}
	throw KeyNotFoundException();
	return (this->data[key]);
}

/* ************************************************************************** */
/* Exceptions */
/* ************************************************************************** */
char const*	KeyNotFoundException::what()		const throw() {return ("ERROR: Key not found in database map");}
char const*	InvalidDatabaseException::what()	const throw() {return ("ERROR: Invalid database given");}
char const*	InvalidInputException::what()		const throw() {return ("ERROR: Invalid input given");}
char const*	InvalidProgramNameException::what()	const throw() {return ("ERROR: Invalid program name");}
char const*	InvalidArgumentException::what()	const throw() {return ("ERROR: Invalid argument given");}

/* ************************************************************************** */
/* Member Functions */
/* ************************************************************************** */
unsigned int	BitcoinExchange::get_size() const {return (this->data.size());}

void	BitcoinExchange::set_key_value(std::string const& key, float const& value) {this->data[key] = value;}

typename std::map<std::string, float>::iterator	BitcoinExchange::begin() {return (this->data.begin());}
typename std::map<std::string, float>::iterator	BitcoinExchange::end() {return (this->data.end());}