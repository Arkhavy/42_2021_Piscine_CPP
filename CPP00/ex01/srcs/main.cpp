/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:45:00 by ljohnson          #+#    #+#             */
/*   Updated: 2022/10/07 08:09:36 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <PhoneBook.hpp>
#include <cstdio>

void	print_error(std::string message)
{
	std::cout << "\033[31m" << "\033[1m";
	std::cout << message;
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

int	main(void)
{
	PhoneBook	repertory;
	std::string	str;

	while (42)
	{
		std::cout << "Please enter one of the following : ADD, SEARCH, EXIT" << std::endl;
		ft_getline(str);
		if (str == "ADD")
			repertory.add_contact();
		else if (str == "SEARCH")
			repertory.search_contact();
		else if (str == "EXIT")
		{
			std::cout << "Goodbye !" << std::endl;
			return (0);
		}
		else
			print_error("This command does not exist, try again !");
	}
	return (0);
}