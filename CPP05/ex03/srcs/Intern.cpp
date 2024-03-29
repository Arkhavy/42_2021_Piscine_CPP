/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:22:38 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/16 09:03:18 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Intern.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
Intern::Intern()
{
	std::cout << FAINT;
	std::cout << "Default Intern constructor called.";
	std::cout << FWHITE << std::endl;
}

Intern::Intern(Intern const& src)
{
	*this = src;
	std::cout << FAINT;
	std::cout << "Copy Intern constructor called.";
	std::cout << FWHITE << std::endl;
}

Intern::~Intern()
{
	std::cout << FAINT;
	std::cout << "Default Intern destructor called.";
	std::cout << FWHITE << std::endl;
}
/* ************************************************************************** */
/* Operator Overloads */
/* ************************************************************************** */
Intern&	Intern::operator=(Intern const& rhs)
{
	(void)rhs;
	return (*this);
}

/* ************************************************************************** */
/* Exceptions */
/* ************************************************************************** */
char const*	Intern::FormDoesNotExistException::what() const throw() {return ("The Form requested does not exist according to the Intern !");}

/* ************************************************************************** */
/* Public Member Functions */
/* ************************************************************************** */
static int	check_form_name(std::string const& form_name)
{
	std::string const	form_list[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	for (int i = 0; i < 3; i++)
	{
		if (form_name == form_list[i])
			return (i);
	}
	throw Intern::FormDoesNotExistException();
	// return (4);
}

AForm*	Intern::makeForm(std::string const form_name, std::string const target)
{
	int	form_to_create = check_form_name(form_name);
	AForm*	tmp;

	switch(form_to_create)
	{
		case 0:
			tmp = new PresidentialPardonForm(target); break ;
		case 1:
			tmp = new RobotomyRequestForm(target); break ;
		case 2:
			tmp = new ShrubberyCreationForm(target); break ;
		default:
			throw FormDoesNotExistException();
	}
	return (tmp);
}