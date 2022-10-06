/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:39:40 by ljohnson          #+#    #+#             */
/*   Updated: 2022/10/06 10:59:53 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <PhoneBook.hpp>

void	print_error(std::string msg);
void	ft_getline(std::string& str);

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
PhoneBook::PhoneBook()
{
	this->contact_nb = 0;
	this->oldest_contact = 0;
	std::cout << "\033[2m" << "PhoneBook constructor called" << "\033[2m" << std::endl;
	return ;
}

PhoneBook::~PhoneBook()
{
	std::cout << "\033[2m" << "Phonebook destructor called" << "\033[2m" << std::endl;
	return ;
}

/* ************************************************************************** */
/* Member Functions : add_contact() */
/* ************************************************************************** */
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

static void	set_contact_data(Contact& tmp_contact, std::string str, int i)
{
	switch (i)
	{
		case 0:
			tmp_contact.set_first_name(str); break ;
		case 1:
			tmp_contact.set_last_name(str); break ;
		case 2:
			tmp_contact.set_nickname(str); break ;
		case 3:
			tmp_contact.set_phone_number(str); break ;
		case 4:
			tmp_contact.set_darkest_secret(str); break ;
		default:
			break ;
	}
}

static bool	check_phone_number(std::string str)
{
	if (str.size() != 10)
	{
		print_error("Phone number must be 10 digits long, try again !");
		return (false);
	}
	else
	{
		for (int i = 0; str[i]; i++)
		{
			if (!isdigit(str[i]))
			{
				print_error("Phone number must have only digits, try again !");
				return (false);
			}
		}
	}
	return (true);
}

static void	set_contact_informations(Contact& tmp_contact)
{
	std::string	str;

	for (int i = 0; i < 5; i++)
	{
		print_message(i);
		ft_getline(str);
		if (i == 3 && !check_phone_number(str))
			i--;
		else if (str.size() == 0 || str[0] == '\n')
		{
			print_error("Field must not be empty, try again !");
			i--;
		}
		else
			set_contact_data(tmp_contact, str, i);
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
		std::cout << "Currently replacing contact at index : " << this->oldest_contact << std::endl;
		set_contact_informations(contact_list[this->oldest_contact]);
		this->oldest_contact++;
	}
	else
	{
		std::cout << "Currently adding contact at index : " << this->contact_nb << std::endl;
		set_contact_informations(contact_list[this->contact_nb]);
		this->contact_nb++;
	}
}

/* ************************************************************************** */
/* Member Functions : search_contact() const */
/* ************************************************************************** */