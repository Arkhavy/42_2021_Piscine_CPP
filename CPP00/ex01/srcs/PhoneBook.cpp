/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:44:26 by ljohnson          #+#    #+#             */
/*   Updated: 2022/10/03 10:35:30 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <PhoneBook.hpp>

void	print_error(std::string message);
void	ft_getline(std::string& str);

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
PhoneBook::PhoneBook()
{
	std::cout << "\033[2m" << "PhoneBook constructor called" << "\033[0m" << std::endl;
	this->contact_nb = 0;
	this->oldest_contact = 0;
	return ;
}

PhoneBook::~PhoneBook()
{
	std::cout << "\033[2m" << "PhoneBook destructor called" << "\033[0m" << std::endl;
	return ;
}

/* ************************************************************************** */
/* Add Contact */
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

static int	check_phone_number(std::string str)
{
	if (str.size() != 10)
	{
		print_error("Phone number must be 10 character long, try again !");
		return (1);
	}
	else
	{
		for (int i = 0; str[i]; i++)
		{
			if (!isdigit(str[i]))
			{
				print_error("Phone number must have only digits, try again !");
				return (1);
			}
		}
	}
	return (0);
}

void	get_contact_informations(Contact& TmpContact)
{
	std::string	str;
	
	for (int i = 0; i < 5; i++)
	{
		print_message(i);
		ft_getline(str);
		if (i == 3 && check_phone_number(str))
			i--;
		else if (str.size() == 0 || str[0] == '\n')
		{
			print_error("Field must not be empty, try again !");
			i--;
		}
		else
			TmpContact.set_string(str, i);
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
		get_contact_informations(Contacts[this->oldest_contact]);
		this->oldest_contact++;
	}
	else
	{
		std::cout << "Currently adding contact at index : " << this->contact_nb << std::endl;
		get_contact_informations(Contacts[this->contact_nb]);
		this->contact_nb++;
	}
}

/* ************************************************************************** */
/* Search Contact */
/* ************************************************************************** */
static void	check_and_display_str(std::string str)
{
	std::cout << "|";
	if (str.size() > 10)
	{
		str.resize(9);
		str.resize(10, '.');
	}
	std::cout << std::setw(10) << str;
}

void	PhoneBook::display_phonebook() const
{
	std::cout << std::endl << "_____________________________________________";
	std::cout << std::endl << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
	for (int i = 0; i < this->contact_nb; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (j == 0)
				std::cout << "|" << std::setw(10) << i;
			else
				check_and_display_str(Contacts[i].get_string(j - 1));
		}
		std::cout << "|" << std::endl;
	}
	std::cout << "|__________|__________|__________|__________|" << std::endl << std::endl;
}

void	PhoneBook::search_contact() const
{
	std::string			str;
	std::string const	cmp = "0123456789";

	if (this->contact_nb == 0)
		return (print_error("There is no contact to display right now, try the ADD Command !"));
	this->display_phonebook();
	while (42)
	{
		std::cout << "Please enter an index to display the corresponding entry : ";
		ft_getline(str);
		if (str.size() != 1 || !isdigit(str[0]))
			print_error("The index given is invalid, try again !");
		else
		{
			for (int i = 0; i < this->contact_nb; i++)
			{
				if (str[0] == cmp[i])
					return (Contacts[i].display_info());
			}
			print_error("The index given is invalid, try again !");
		}
	}
}
