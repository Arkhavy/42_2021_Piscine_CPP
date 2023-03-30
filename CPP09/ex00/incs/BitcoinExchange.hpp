/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:02:49 by ljohnson          #+#    #+#             */
/*   Updated: 2023/03/30 10:47:49 by ljohnson         ###   ########lyon.fr   */
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
		float&				operator[](std::string const& key);

	//Getter & Setters
		unsigned int	get_size() const;
		void			set_key_value(std::string const& key, float const& value);

	//Iterators
	typedef typename	std::map<std::string, float>::iterator	iterator;

	iterator	begin();
	iterator	end();

	//Member functions
		void	display_data();
};

/* ************************************************************************** */
/* Exceptions */
/* ************************************************************************** */
class	KeyNotFoundException : public std::exception
{
	public:
		virtual char const*	what() const throw();
};

class	InvalidDatabaseException : public std::exception
{
	public:
		virtual char const*	what() const throw();
};

class	InvalidInputException : public std::exception
{
	public:
		virtual char const*	what() const throw();
};

class	InvalidProgramNameException : public std::exception
{
	public:
		virtual char const*	what() const throw();
};

class	InvalidArgumentException : public std::exception
{
	public:
		virtual char const*	what() const throw();
};

class	InvalidDateException : public std::exception
{
	public:
		virtual char const*	what() const throw();
};

class	InvalidValueException : public std::exception
{
	public:
		virtual char const*	what() const throw();
};

class	InvalidLineException : public std::exception
{
	public:
		virtual char const*	what() const throw();
};

/* ************************************************************************** */
/* Templates */
/* ************************************************************************** */
template<typename T>
T	ft_print_msg(std::string const& message, T const val);

#include <BitcoinExchange.tpp>