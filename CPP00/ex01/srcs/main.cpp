/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:45:00 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/13 15:19:37 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Contact.Class.hpp>
#include <PhoneBook.Class.hpp>

void	print_error(std::string message)
{
	std::cout << "\033[31m";
	std::cout << message;
	std::cout << "\033[0m" << std::endl;
}

int	main(void)
{
	PhoneBook	Phonebook;
	std::string	str;

	return (0);
}