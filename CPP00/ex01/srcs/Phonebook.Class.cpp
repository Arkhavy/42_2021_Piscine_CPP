/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.Class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:44:49 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/13 16:03:26 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <PhoneBook.Class.hpp>
void	print_error(std::string message);

PhoneBook::PhoneBook()
{
	this->contact_nb = 0;
	this->oldest_contact = 0;
	return ;
}

PhoneBook::~PhoneBook() {return ;}

static void	print_message(int index)
{
	std::cout << "Please enter ";
	switch (index)
	{
		case 0:
			std::cout << "first name : "; break ;
		case 1:
			std::cout << "last name : "; break ;
		case 2:
			std::cout << "nickname : "; break ;
		case 3:
			std::cout << "phone_number : "; break ;
		case 4:
			std::cout << "darkest_secret : "; break ;
		default:
			break ;
	}
}

void	PhoneBook::add_contact()
{
	std::string	str;

	if (this->contact_nb == 8)
	{
		if (this->oldest_contact == 8)
			this->oldest_contact = 0;
		print_error("Maximum number of contact reached, replacing the oldest one");
		std::cout << "Currently replacing index " << this->oldest_contact << std::endl;
		for (int i = 0; i < 5; i++)
		{
			print_message(i);
			std::getline(std::cin, str);
			Contact[this->oldest_contact].set_string(str, i);
		}
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			print_message(i);
			std::getline(std::cin, str);
			Contact[this->contact_nb].set_string(str, i);
		}
		this->contact_nb++;
	}
}