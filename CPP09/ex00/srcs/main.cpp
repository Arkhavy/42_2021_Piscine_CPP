/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:54:18 by ljohnson          #+#    #+#             */
/*   Updated: 2023/04/20 15:13:59 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

/* ************************************************************************** */
/* MODULE : CHECK DATE */
/* ************************************************************************** */
void	check_date_numbers(int const year, int const month, int const day)
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
			if ((year % 4) == 0)
			{
				if (day > 29)
					throw InvalidDateException();
			}
			else
				if (day > 28)
					throw InvalidDateException();
		}
		else
			if (day > 31)
				throw InvalidDateException();
	}
	else
		throw InvalidDateException();
}

static int	get_pos(std::string const& date, int pos)
{
	pos = date.find('-', pos);
	if (static_cast<size_t>(pos) == std::string::npos)
		throw InvalidDateException();
	return (pos);
}

void	check_date(std::string const& date)
{
	char const*	date_str = date.c_str();
	int	year = 0;
	int	month = 0;
	int	day = 0;
	int	pos = 0;

	for (size_t i = 0; i < date.size(); i++)
	{
		if (!isdigit(date[i]) && date[i] != '-')
			throw InvalidDateException();
	}
	year = std::strtol(&date_str[0], NULL, 10);
	if (errno == ERANGE || year > INT_MAX || year < (-INT_MAX - 1))
		throw InvalidDateException();

	pos = get_pos(date, 0);
	month = std::strtol(&date_str[pos + 1], NULL, 10);
	if (errno == ERANGE || month > INT_MAX || month < (-INT_MAX - 1))
		throw InvalidDateException();

	pos = get_pos(date, (pos + 1));
	day = std::strtol(&date_str[pos + 1], NULL, 10);
	if (errno == ERANGE || day > INT_MAX || day < (-INT_MAX - 1))
		throw InvalidDateException();
	check_date_numbers(year, month, day);
}

/* ************************************************************************** */
/* MODULE : CHECK VALUE */
/* ************************************************************************** */
void	check_value(std::string const& value, bool is_db)
{
	bool	point = false;

	for (size_t i = 0; i < value.size(); i++)
	{
		if (value[i] == '.')
			(point == true) ? throw InvalidValueException() : point = true;
		if (!isdigit(value[i]) && value[i] != '.')
		{
			if (value[i] == '-')
				throw NegativeValueException();
			throw InvalidValueException();
		}
	}
	if (point == true)
	{
		float	tmp = std::strtod(value.c_str(), NULL);
		if (tmp < 0 || tmp > FLT_MAX || tmp < (-FLT_MAX - 1) || errno == ERANGE)
			throw OverflowValueException();
		if (!is_db && tmp > 1000)
			throw OverflowValueException();
	}
	else
	{
		int	tmp = std::strtol(value.c_str(), NULL, 10);
		if (tmp < 0 || tmp > INT_MAX || tmp < (-INT_MAX - 1) || errno == ERANGE)
			throw OverflowValueException();
		if (!is_db && tmp > 1000)
			throw OverflowValueException();
	}
}

/* ************************************************************************** */
/* MODULE : GET DATABASE */
/* ************************************************************************** */
void	check_db_lines(std::string const& line, std::string& date, std::string& value)
{
	size_t	pos = 0;

	pos = line.find(',', 0);
	if (pos == std::string::npos)
		throw InvalidLineException();
	date = line.substr(0, pos);
	check_date(date);
	value = line.substr(pos + 1, line.size() - pos);
	check_value(value, true);
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

				check_db_lines(line, date, value);
				database.set_key_value(date, std::strtod(value.c_str(), NULL));
			}
			catch (std::exception& e) {}
			if (ifs.eof())
				break ;
		}
	}
	ifs.close();
}

/* ************************************************************************** */
/* MODULE : DISPLAY EXCHANGE */
/* ************************************************************************** */
void	display_line(BitcoinExchange& database, std::string const& date, std::string const& value)
{
	float	f_value = std::strtod(value.c_str(), NULL);
	float	db_value = database.get_value_from_date(date);

	std::cout << date << " => " << value << " = " << (f_value * db_value) << std::endl;
}

void	check_infile_line(std::string const& line, std::string& date, std::string& value)
{
	size_t	pos = 0;

	pos = line.find(" | ", 0);
	if (pos == std::string::npos)
		throw InvalidLineException();
	date = line.substr(0, pos);
	check_date(date);
	value = line.substr(pos + 3, line.size() - (pos + 2));
	check_value(value, false);
}

void	display_bitcoin_exchange(BitcoinExchange& database, char const* infile)
{
	std::ifstream	ifs(infile, std::ifstream::in);
	std::string		line;

	for (int i = 0; i >= 0; i++)
	{
		std::getline(ifs, line);
		if (i == 0 && line != "date | value")
			throw InvalidInputException();
		else
		{
			if (i == 0)
				continue ;
			try
			{
				std::string	date;
				std::string	value;

				check_infile_line(line, date, value);
				display_line(database, date, value);
			}
			catch (InvalidContentException& e) {ft_print_msg<int>(RED, static_cast<std::string>("ERROR: bad input => ") += line, 1);}
			catch (std::exception& e) {ft_print_msg<int>(RED, static_cast<std::string>(e.what()), 1);}
			if (ifs.eof())
				break ;
		}
	}
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
	try
	{
		check_user_input(av[0], av[1]);
		get_database(database);
		display_bitcoin_exchange(database, av[1]);
	}
	catch (std::exception& e) {return (ft_print_msg<int>(RED, e.what(), 1));}
	return (0);
}