/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:22:38 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/15 17:45:06 by ljohnson         ###   ########lyon.fr   */
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
Intern&	operator=(Intern const& rhs)
{
	this->~Intern();
	new(this) Intern();
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
	throw FormDoesNotExistException();
	// return (4);
}

AForm&	Intern::makeForm(std::string const form_name, std::string const target)
{
	int	form_to_create = check_form_name(form_name);

	switch(form_to_create)
	{
		case 0:
			return (new PresidentialPardonForm(target)); break ;
		case 1:
			return (new RobotomyRequestForm(target)); break ;
		case 2:
			return (new ShrubberyCreationForm(target)); break ;
		default:
			throw FormDoesNotExistException();
	}
}