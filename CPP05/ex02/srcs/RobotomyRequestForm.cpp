/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:53:54 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/15 13:25:56 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <RobotomyRequestForm.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
RobotomyRequestForm::RobotomyRequestForm() :
	AForm("RobotomyRequestForm", 25, 5), target("Default")
{
	std::cout << FAINT;
	std::cout << "Default RobotomyRequestForm constructor called.";
	std::cout << FWHITE << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) :
	AForm("RobotomyRequestForm", 25, 5), target(target)
{
	std::cout << FAINT;
	std::cout << "RobotomyRequestForm with target [" << this->target << "] constructor called.";
	std::cout << FWHITE << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src) :
	AForm(src)
{
	*this = src; //Need potential change later to check Shallow and Deep Copy
	std::cout << FAINT;
	std::cout << "Copy RobotomyRequestForm with target [" << this->target << "] constructor called.";
	std::cout << FWHITE << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << FAINT;
	std::cout << "Default RobotomyRequestForm with target ["<< this->target << "] destructor called.";
	std::cout << FWHITE << std::endl;
}

/* ************************************************************************** */
/* Operator Overloads */
/* ************************************************************************** */
RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs)
{
	this->target = rhs.target;
	return (*this);
}

/* ************************************************************************** */
/* Public Member Functions */
/* ************************************************************************** */
void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	//ouaf
}