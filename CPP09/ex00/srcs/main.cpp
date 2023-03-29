/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:54:18 by ljohnson          #+#    #+#             */
/*   Updated: 2023/03/29 16:46:43 by ljohnson         ###   ########lyon.fr   */
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

int	check_date(std::string const& date)
{
	int	year = 0;
	int	month = 0;
	int	day = 0;

	size_t	pos = 0;
	size_t	old_pos = 0;
	char*	date_str = date.c_str();

	pos = date.find('-', 0);
	if (pos == std::string::npos)
		throw InvalidDateException();
	year = std::strtol(&date_str[0], &date_str[pos], 10);
	if (errno == ERANGE)
		throw InvalidDateException();
	old_pos = pos;

	pos = date.find('-', (old_pos + 1));
	if (pos == std::string::npos)
		throw InvalidDateException();
	month = std::strtol(&date_str[old_pos + 1], &date_str[pos], 10);
	if (errno == ERANGE)
		throw InvalidDateException();
	day = std::strtol(&date_str[pos + 1], NULL, 10);
	if (errno == ERANGE)
		throw InvalidDateException();
	check_date_numbers(month, day);
}

/* ************************************************************************** */
/* MODULE : GET DATABASE */
/* ************************************************************************** */
int	ft_check_line(std::string const& line)
{
	size_t	pos = 0;
	std::string	date;
	std::string	value;

	pos = line.find(',', 0);
	if (pos == std::string::npos)
		return (0);
	date = line.substr(0, pos);
	if (date.size() != 10)
		return (0);
	if (date[4] != '-' || date[7] != '-')
		return (0);
	for (size_t i = 0; i < date.size(); i++)
	{
		if (i != 4 && i != 7 && !isdigit(date[i]))
			return (0);
	}
	value = line.substr(pos, line.size());
}

void	get_database(BitcoinExchange& database)
{
	std::ifstream	ifs("data.csv", std::ifstream::in);
	std::string		line;

	for (int i = 0; i > 0; i++)
	{
		std::getline(ifs, line);
		if (i == 0 && line != "date,exchange_rate")
			throw InvalidDatabaseException();
		else
		{
			if (ft_check_line(line))
				//add line to map
			else
				//skip line
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
	// BitcoinExchange	ouaf;

	// ouaf.set_key_value("ouef ouef", 42);
	// for (std::map<std::string, float>::iterator it = ouaf.begin(); it != ouaf.end(); it++)
	// 	std::cout << it->first << " | " << it->second << std::endl;
	ft_print_msg<int>(GREEN, "Everything worked correctly wooooo !", 0);
	return (0);
}