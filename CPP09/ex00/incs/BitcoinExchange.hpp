/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:02:49 by ljohnson          #+#    #+#             */
/*   Updated: 2023/04/07 14:08:14 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include <cctype>
#include <sys/stat.h>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cerrno>
#include <map>

# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define PURPLE		"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

# define ERASE		"\033[2K\r"
# define RESET		"\033[0m"
# define BOLD		"\033[1m"
# define FAINT		"\033[2m"
# define ITALIC		"\033[3m"
# define UNDERLINE	"\033[4m"

#define	JAN	1
#define	FEB	2
#define	MAR	3
#define	APR	4
#define	MAY	5
#define	JUN	6
#define	JUL	7
#define	AUG	8
#define	SEP	9
#define	OCT	10
#define	NOV	11
#define	DEC	12

class	BitcoinExchange
{
	private:
		std::map<std::string, float>	data;

	public:
	//Constructors & Destructors
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const& src);
		virtual	~BitcoinExchange();

	//Operator overloads
		BitcoinExchange&	operator=(BitcoinExchange const& rhs);

	//Getter & Setters
		float&			get_value_from_date(std::string const& date);
		void			set_key_value(std::string const& key, float const& value);
};

/* ************************************************************************** */
/* Exceptions */
/* ************************************************************************** */
class	KeyNotFoundException		: public std::exception {public: virtual char const*	what() const throw();};
class	InvalidDatabaseException	: public std::exception {public: virtual char const*	what() const throw();};
class	InvalidInputException		: public std::exception {public: virtual char const*	what() const throw();};
class	InvalidProgramNameException	: public std::exception {public: virtual char const*	what() const throw();};
class	InvalidArgumentException	: public std::exception {public: virtual char const*	what() const throw();};
class	NegativeValueException		: public std::exception {public: virtual char const*	what() const throw();};
class	OverflowValueException		: public std::exception {public: virtual char const*	what() const throw();};

class	InvalidContentException		: public std::exception {public: virtual char const*	what() const throw();};
class	InvalidDateException		: public InvalidContentException {public: virtual char const*	what() const throw();};
class	InvalidValueException		: public InvalidContentException {public: virtual char const*	what() const throw();};
class	InvalidLineException		: public InvalidContentException {public: virtual char const*	what() const throw();};

/* ************************************************************************** */
/* Templates */
/* ************************************************************************** */
template<typename T>
T	ft_print_msg(std::string const& message, T const val);

#include <BitcoinExchange.tpp>