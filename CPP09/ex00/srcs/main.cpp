/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:54:18 by ljohnson          #+#    #+#             */
/*   Updated: 2023/03/17 14:44:46 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

int	check_user_input(std::string program_name, std::string input)
{
	if (program_name != "./btc")
		return (ft_print_err<int>("ERROR: Invalid program name", 1));
	if (input.empty() || input.length() == 0)
		return (ft_print_err<int>("ERROR: Invalid argument", 1));
	return (0);
}

int	main(int ac, char** av)
{
	if (ac != 2)
		return (ft_print_err<int>("ERROR: Usage: ./btc <input>", 1));
	if (check_user_input(av[0], av[1]))
		return (1);
	return (0);
}