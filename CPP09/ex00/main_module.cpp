/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_module.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:47:29 by ljohnson          #+#    #+#             */
/*   Updated: 2023/03/29 16:57:01 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <climits>
#include <cfloat>
#include <cerrno>
#include <cstdlib>
#include <cctype>
#include <exception>

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

class	InvalidDateException : public std::exception
{
	public:
		virtual char const*	what() const throw() {return ("ERROR: Invalid date in file");};
};

void	check_date_numbers(int const month, int const day)
{
	if (month < 1 || month > 12)
		throw InvalidDateException();
	if (day > 0)
	{
		if (month == APR || month == JUN || month == SEP || month == NOV)
		{
			if (day > 30)
				throw InvalidDateException();
		}
		else if (month == FEB)
		{
			if (day > 28)
				throw InvalidDateException();
		}
		else
		{
			if (day > 31)
				throw InvalidDateException();
		}
	}
	else
		throw InvalidDateException();
}

int	check_date(std::string const& date)
{
	int	year = 0;
	int	month = 0;
	int	day = 0;

	size_t		pos = 0;
	size_t		old_pos = 0;
	char const*	date_str = date.c_str();

	std::cout << "date given: " << date << std::endl;
	std::cout << "date.size(): " << date.size() << std::endl;

	pos = date.find('-', 0);
	std::cout << "first pos: " << pos << std::endl;
	if (pos == std::string::npos)
		throw InvalidDateException();
	year = std::strtol(&date_str[0], &date_str[pos], 10);
	std::cout << "year: " << year << std::endl;
	if (errno == ERANGE)
		throw InvalidDateException();
	old_pos = pos;

	pos = date.find('-', (old_pos + 1));
	std::cout << "second pos: " << pos << std::endl;
	if (pos == std::string::npos)
		throw InvalidDateException();
	month = std::strtol(&date_str[old_pos + 1], &date_str[pos], 10);
	std::cout << "month: " << month << std::endl;
	if (errno == ERANGE)
		throw InvalidDateException();
	day = std::strtol(&date_str[pos + 1], NULL, 10);
	std::cout << "day: " << day << std::endl;
	if (errno == ERANGE)
		throw InvalidDateException();
	check_date_numbers(month, day);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	std::string	str = av[1];
	try
	{
		check_date(str);
		std::cout << str << std::endl;
	}
	catch (std::exception& e) {std::cout << e.what() << std::endl;}
	return (0);
}