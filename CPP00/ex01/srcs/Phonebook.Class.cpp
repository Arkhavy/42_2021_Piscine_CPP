/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.Class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:44:49 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/13 15:19:55 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <PhoneBook.Class.hpp>
void	print_error(std::string message);

PhoneBook::PhoneBook()
{
	this->contact_nb = 0;
	return ;
}

PhoneBook::~PhoneBook() {return ;}

void	PhoneBook::add_contact()
{
	if (this->contact_nb == 8)
	{
		print_error("Maximum number of contact reached, replacing the first one");
		
	}
}