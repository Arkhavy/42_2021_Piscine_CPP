/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:38:30 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/15 13:25:56 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <PresidentialPardonForm.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
PresidentialPardonForm::PresidentialPardonForm() :
	AForm("PresidentialPardonForm", 25, 5), target("Default")
{
	std::cout << FAINT;
	std::cout << "Default PresidentialPardonForm constructor called.";
	std::cout << FWHITE << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) :
	AForm("PresidentialPardonForm", 25, 5), target(target)
{
	std::cout << FAINT;
	std::cout << "PresidentialPardonForm with target [" << this->target << "] constructor called.";
	std::cout << FWHITE << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src) :
	AForm(src)
{
	*this = src; //Need potential change later to check Shallow and Deep Copy
	std::cout << FAINT;
	std::cout << "Copy PresidentialPardonForm with target [" << this->target << "] constructor called.";
	std::cout << FWHITE << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << FAINT;
	std::cout << "Default PresidentialPardonForm with target ["<< this->target << "] destructor called.";
	std::cout << FWHITE << std::endl;
}

/* ************************************************************************** */
/* Operator Overloads */
/* ************************************************************************** */
PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const& rhs)
{
	this->target = rhs.target;
	return (*this);
}

/* ************************************************************************** */
/* Public Member Functions */
/* ************************************************************************** */
void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	//ouaf
}