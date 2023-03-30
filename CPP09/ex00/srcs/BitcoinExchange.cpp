/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:17:50 by ljohnson          #+#    #+#             */
/*   Updated: 2023/03/30 17:48:11 by ljohnson         ###   ########lyon.fr   */
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
char const*	NegativeValueException::what()		const throw() {return ("ERROR: Not a positive number");}
char const*	OverflowValueException::what()		const throw() {return ("ERROR: Too large a number");}

char const*	InvalidContentException::what()		const throw() {return ("ERROR: Invalid content given");}
char const*	InvalidDateException::what()		const throw() {return ("ERROR: Invalid date given");}
char const*	InvalidValueException::what()		const throw() {return ("ERROR: Invalid value given");}
char const*	InvalidLineException::what()		const throw() {return ("ERROR: Invalid line given");}

/* ************************************************************************** */
/* Member Functions */
/* ************************************************************************** */
unsigned int	BitcoinExchange::get_size() const 							{return (this->data.size());}
float&			BitcoinExchange::get_value_from_date(std::string const& date)
{
	std::map<std::string, float>::iterator	it = this->data.begin();
	std::string	last_date = it->first;

	if (date.compare(it->first) < 0)
		throw InvalidDateException();
	while (it != this->data.end())
	{
		if (date.compare(it->first) >= 0)
			last_date = it->first;
		else
			break ;
		it++;
	}
	return (this->data[last_date]);
}

void	BitcoinExchange::set_key_value(std::string const& key, float const& value) {this->data[key] = value;}