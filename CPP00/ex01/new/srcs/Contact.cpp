/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:21:15 by ljohnson          #+#    #+#             */
/*   Updated: 2022/10/06 10:30:28 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Contact.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
Contact::Contact()
{
	std::cout << "\033[2m" << "Contact constructor called" << "\033[0m" << std::endl;
	return ;
}

Contact::~Contact()
{
	std::cout << "\033[2m" << "Contact destructor called" << "\033[0m" << std::endl;
	return ;
}

/* ************************************************************************** */
/* Getters */
/* ************************************************************************** */
std::string	Contact::get_first_name(void) const { return (this->first_name); }

std::string	Contact::get_last_name(void) const { return (this->last_name); }

std::string	Contact::get_nickname(void) const { return (this->nickname); }

std::string	Contact::get_phone_number(void) const { return (this->phone_number); }

std::string	Contact::get_darkest_secret(void) const { return (this->darkest_secret); }

/* ************************************************************************** */
/* Setters */
/* ************************************************************************** */
void	Contact::set_first_name(std::string str) { this->first_name = str; }

void	Contact::set_last_name(std::string str) { this->last_name = str; }

void	Contact::set_nickname(std::string str) { this->nickname = str; }

void	Contact::set_phone_number(std::string str) { this->phone_number = str; }

void	Contact::set_darkest_secret(std::string str) { this->darkest_secret = str; }

/* ************************************************************************** */
/* Member functions */
/* ************************************************************************** */
void	Contact:display_info() const
{
	std::cout << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "First name : " << this->first_name << std::endl;
	std::cout << "Last name : " << this->last_name << std::endl;
	std::cout << "Nickname : " << this->nickname << std::endl;
	std::cout << "Phone number : " << this->phone_number << std::endl;
	std::cout << "Darkest secret : " << this->darkest_secret << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;
}
