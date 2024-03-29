/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 13:01:26 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/19 13:25:49 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Harl.hpp>

int	print_error(std::string message)
{
	std::cout << "\033[31m" << "\033[1m";
	std::cout << message;
	std::cout << "\033[0m" << std::endl;
	return (1);
}

int	main(int ac, char **av)
{
	Harl	harl;
	if (ac != 2)
		return (print_error("Usage: ./HarlFilter <level>"));
	harl.complain(av[1]);
	return (0);
}