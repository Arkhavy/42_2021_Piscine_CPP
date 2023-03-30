/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:54:18 by ljohnson          #+#    #+#             */
/*   Updated: 2023/03/30 11:06:29 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

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

/* ************************************************************************** */
/* MODULE : CHECK DATE */
/* ************************************************************************** */
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

void	check_date(std::string const& date)
{
	int	year = 0;
	int	month = 0;
	int	day = 0;

	int	pos = 0;
	int	old_pos = 0;
	char const*	date_str = date.c_str();

	for (size_t i = 0; i < date.size(); i++)
	{
		if (!isdigit(date[i]) && date[i] != '-')
			throw InvalidDateException();
	}
	pos = date.find('-', 0);
	if (static_cast<size_t>(pos) == std::string::npos)
		throw InvalidDateException();
	year = std::strtol(&date_str[0], NULL, 10);
	if (errno == ERANGE || year > INT_MAX || year < (-INT_MAX - 1))
		throw InvalidDateException();
	old_pos = pos;

	pos = date.find('-', (old_pos + 1));
	if (static_cast<size_t>(pos) == std::string::npos)
		throw InvalidDateException();
	month = std::strtol(&date_str[old_pos + 1], NULL, 10);
	if (errno == ERANGE || month > INT_MAX || month < (-INT_MAX - 1))
		throw InvalidDateException();
	day = std::strtol(&date_str[pos + 1], NULL, 10);
	if (errno == ERANGE || day > INT_MAX || day < (-INT_MAX - 1))
		throw InvalidDateException();
	check_date_numbers(month, day);
}

/* ************************************************************************** */
/* MODULE : CHECK VALUE */
/* ************************************************************************** */
//Works for database, need to limit to 1000 for input
void	check_value(std::string const& value)
{
	bool	point = false;

	for (size_t i = 0; i < value.size(); i++)
	{
		if (value[i] == '.')
			(point == true) ? throw InvalidValueException() : point = true;
		if (!isdigit(value[i]) && value[i] != '.')
			throw InvalidValueException();
	}
	if (point == true)
	{
		float	tmp = std::strtod(value.c_str(), NULL);
		if (tmp < 0 || tmp > FLT_MAX || tmp < (-FLT_MAX - 1) || errno == ERANGE)
			throw InvalidValueException();
	}
	else
	{
		int	tmp = std::strtol(value.c_str(), NULL, 10);
		if (tmp < 0 || tmp > INT_MAX || tmp < (-INT_MAX - 1) || errno == ERANGE)
			throw InvalidValueException();
	}
}

/* ************************************************************************** */
/* MODULE : GET DATABASE */
/* ************************************************************************** */
int	ft_check_line(std::string const& line, std::string& date, std::string& value)
{
	size_t	pos = 0;

	pos = line.find(',', 0);
	if (pos == std::string::npos)
		throw InvalidLineException();
	date = line.substr(0, pos);
	check_date(date);
	value = line.substr(pos + 1, line.size() - pos);
	check_value(value);
	return (0);
}

void	get_database(BitcoinExchange& database)
{
	std::ifstream	ifs("data.csv", std::ifstream::in);
	std::string		line;

	for (int i = 0; i >= 0; i++)
	{
		std::getline(ifs, line);
		if (i == 0 && line != "date,exchange_rate")
			throw InvalidDatabaseException();
		else
		{
			try
			{
				std::string	date;
				std::string	value;

				ft_check_line(line, date, value);
				database.set_key_value(date, std::strtod(value.c_str(), NULL));
			}
			catch (std::exception& e)
			{
				// ft_print_msg<int>(FAINT, e.what(), 1);
				//skip line
			}
		}
		if (ifs.eof())
			break ;
	}
	ifs.close();
}

/* ************************************************************************** */
/* MODULE : CHECK USER INPUT */
/* ************************************************************************** */
int	is_file(char const* name)
{
	struct stat	s;

	if (lstat(name, &s) == 0)
		if (!S_ISREG(s.st_mode))
			return (0);
	return (1);
}

int	check_file(char const* filename)
{
	std::ifstream	ifs(filename, std::ifstream::in);
	int				ret = 0;

	if (!ifs.good())
		ret = 1;
	if (!is_file(filename))
		ret = 1;
	ifs.close();
	return (ret);
}

int	check_user_input(std::string program_name, std::string input)
{
	if (program_name != "./btc")
		throw InvalidProgramNameException();
	if (input.empty() || input.length() == 0)
		throw InvalidArgumentException();
	if (check_file(input.c_str()))
		throw InvalidInputException();
	if (check_file("data.csv"))
		throw InvalidDatabaseException();
	return (0);
}

/* ************************************************************************** */
/* MAIN */
/* ************************************************************************** */
int	main(int ac, char** av)
{
	BitcoinExchange	database;

	if (ac != 2)
		return (ft_print_msg<int>(RED, "ERROR: Usage: ./btc <input>", 1));
	try {check_user_input(av[0], av[1]);}
	catch (std::exception& e) {return (ft_print_msg<int>(RED, e.what(), 1));}
	try {get_database(database);}
	catch (std::exception& e) {ft_print_msg<int>(RED, e.what(), 1);}

	ft_print_msg<int>(GREEN, "Everything worked correctly wooooo !", 0);
	// database.display_data();
	return (0);
}