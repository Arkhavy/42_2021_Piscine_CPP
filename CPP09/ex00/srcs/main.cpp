/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:54:18 by ljohnson          #+#    #+#             */
/*   Updated: 2023/03/29 12:01:35 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

int	ft_check_line(std::string const& line)
{
	size_t	pos = 0;
	std::string	date;
	std::string	value;

	pos = line.find('-');
	if (pos == std::string::npos)
		return (0);
	pos = line.find('-', (pos + 1));
	if (pos == std::string::npos)
		return (0);
	pos = line.find(',', (pos + 1));
	if (pos == std::string::npos)
		return (0);
	date = line.substr(0, line.find(','));
}

void	get_csv_content(BitcoinExchange& database)
{
	std::ifstream	ifs("data.csv", std::ifstream::in);
	std::string		line;

	if (!ifs.good())
	{
		ifs.close();
		throw InvalidDatabaseException();
	}
	for (int i = 0; i > 0; i++)
	{
		std::getline(ifs, line);
		if (i == 0 && line != "date,exchange_rate")
			throw InvalidDatabaseException();
		else
		{
			if (ft_check_line(line))
				
		}
		if (ifs.eof())
			break ;
	}
	ifs.close();
}

int	check_user_input(std::string program_name, std::string input)
{
	std::ifstream	ifs;

	if (program_name != "./btc")
		return (ft_print_msg<int>(RED, "ERROR: Invalid program name", 1));
	if (input.empty() || input.length() == 0)
		return (ft_print_msg<int>(RED, "ERROR: Invalid argument", 1));

	ifs.open(input.c_str(), std::ifstream::in);
	if (!ifs.good())
		return (ft_print_msg<int>(RED, "ERROR: Invalid input given", 1));
	ifs.close();
	ifs.open("data.csv", std::ifstream::in);
	if (!ifs.good())
		return (ft_print_msg<int>(RED, "ERROR: Invalid database given", 1));
	ifs.close();
	return (0);
}

int	main(int ac, char** av)
{
	BitcoinExchange	database;
	if (ac != 2)
		return (ft_print_msg<int>(RED, "ERROR: Usage: ./btc <input>", 1));
	if (check_user_input(av[0], av[1]))
		return (1);
	try {get_csv_content(database);}
	catch (std::exception& e) {ft_print_msg<int>(RED, e.what(), 1);}
	// BitcoinExchange	ouaf;

	// ouaf.set_key_value("ouef ouef", 42);
	// for (std::map<std::string, float>::iterator it = ouaf.begin(); it != ouaf.end(); it++)
	// 	std::cout << it->first << " | " << it->second << std::endl;
	ft_print_msg<int>(GREEN, "Everything worked correctly wooooo !", 0);
	return (0);
}