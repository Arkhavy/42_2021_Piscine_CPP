/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:44:37 by ljohnson          #+#    #+#             */
/*   Updated: 2022/11/10 15:09:52 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Contact.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
Contact::Contact()
{
	std::cout << "\033[2m";
	std::cout << "Contact constructor called";
	std::cout << "\033[0m" << std::endl;
	return ;
}

Contact::~Contact()
{
	std::cout << "\033[2m";
	std::cout << "Contact destructor called";
	std::cout << "\033[0m" << std::endl;
	return ;
}

/* ************************************************************************** */
/* Getters & Setters */
/* ************************************************************************** */
std::string	Contact::get_str(int index) const
{
	switch (index)
	{
		case 0:
			return (this->first_name);
		case 1:
			return (this->last_name);
		case 2:
			return (this->nickname);
		case 3:
			return (this->phone_number);
		case 4:
			return (this->darkest_secret);
		default:
			return (NULL);
	}
	return (NULL);
}

void	Contact::set_str(std::string str, int index)
{
	switch (index)
	{
		case 0:
			this->first_name = str; break ;
		case 1:
			this->last_name = str; break ;
		case 2:
			this->nickname = str; break ;
		case 3:
			this->phone_number = str; break ;
		case 4:
			this->darkest_secret = str; break ;
		default:
			break ;
	}
}

/* ************************************************************************** */
/* Member functions */
/* ************************************************************************** */
void	Contact::display_info() const
{
	std::cout << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "First name : " << this->first_name << std::endl;
	std::cout << "Last name : " << this->last_name << std::endl;
	std::cout << "Nickname : " << this->nickname << std::endl;
	std::cout << "Phone Number : " << this->phone_number << std::endl;
	std::cout << "Darkest Secret : " << this->darkest_secret << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;
}