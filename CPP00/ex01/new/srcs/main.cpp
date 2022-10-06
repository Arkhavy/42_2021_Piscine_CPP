/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:43:47 by ljohnson          #+#    #+#             */
/*   Updated: 2022/10/06 10:45:34 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Contact.hpp>
#include <PhoneBook.hpp>
#include <cstdio>

void	print_error(std::string msg)
{
	std::cout << "\033[31m" << "\033[1m";
	std::cout << msg;
	std::cout << "\033[0m" << std::endl;
}

void	ft_getline(std::string& str)
{
	std::getline(std::cin, str);
	if (std::cin.eofbit != 0)
	{
		std::cin.clear();
		clearerr(stdin);
	}
}