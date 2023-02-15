/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:54:13 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/15 13:30:48 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ShrubberyCreationForm.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("ShrubberyCreationForm", 25, 5), target("Default")
{
	std::cout << FAINT;
	std::cout << "Default ShrubberyCreationForm constructor called.";
	std::cout << FWHITE << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) :
	AForm("ShrubberyCreationForm", 25, 5), target(target)
{
	std::cout << FAINT;
	std::cout << "ShrubberyCreationForm with target [" << this->target << "] constructor called.";
	std::cout << FWHITE << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src) :
	AForm(src)
{
	*this = src; //Need potential change later to check Shallow and Deep Copy
	std::cout << FAINT;
	std::cout << "Copy ShrubberyCreationForm with target [" << this->target << "] constructor called.";
	std::cout << FWHITE << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << FAINT;
	std::cout << "Default ShrubberyCreationForm with target ["<< this->target << "] destructor called.";
	std::cout << FWHITE << std::endl;
}

/* ************************************************************************** */
/* Operator Overloads */
/* ************************************************************************** */
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& rhs)
{
	this->~ShrubberyCreationForm();
	new(this) ShrubberyCreationForm(rhs.target);
	return (*this);
}

/* ************************************************************************** */
/* Public Member Functions */
/* ************************************************************************** */
void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	(void)executor;
	//ouaf
}