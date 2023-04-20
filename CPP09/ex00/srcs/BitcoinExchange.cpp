/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:17:50 by ljohnson          #+#    #+#             */
/*   Updated: 2023/04/20 15:28:27 by ljohnson         ###   ########lyon.fr   */
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
static bool	compare_dates(std::string const& in_date, std::string const& db_date)
{
	char const*	in_str = in_date.c_str();
	char const*	db_str = db_date.c_str();
	int	in_pos = 0;
	int	db_pos = 0;
	int	in_nb = 0;
	int	db_nb = 0;

	for (int i = 0; i < 3; i++)
	{
		in_nb = std::strtol(&in_str[in_pos], NULL, 10);
		db_nb = std::strtol(&db_str[db_pos], NULL, 10);
		if (in_nb > db_nb)
			return (true);
		in_pos = in_date.find('-', in_pos) + 1;
		db_pos = db_date.find('-', db_pos) + 1;
	}
	return (false);
}

float&			BitcoinExchange::get_value_from_date(std::string const& date)
{
	std::map<std::string, float>::iterator	it = this->data.begin();
	std::string	last_date = it->first;

	if (!compare_dates(date, it->first))
	{
		throw InvalidDateException();
	}
	while (it != this->data.end())
	{
		if (compare_dates(date, it->first))
			last_date = it->first;
		else
			break ;
		it++;
	}
	return (this->data[last_date]);
}

void	BitcoinExchange::set_key_value(std::string const& key, float const& value) {this->data[key] = value;}