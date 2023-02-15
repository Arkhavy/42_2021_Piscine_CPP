/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:53:54 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/15 15:23:44 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <RobotomyRequestForm.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
RobotomyRequestForm::RobotomyRequestForm() :
	AForm("RobotomyRequestForm", 72, 45), target("Default")
{
	std::cout << FAINT;
	std::cout << "Default RobotomyRequestForm constructor called.";
	std::cout << FWHITE << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) :
	AForm("RobotomyRequestForm", 72, 45), target(target)
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
	this->~RobotomyRequestForm();
	new(this) RobotomyRequestForm(rhs.target);
	return (*this);
}

/* ************************************************************************** */
/* Public Member Functions */
/* ************************************************************************** */
void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	static int	nb_lol = 0;

	if (!this->get_is_signed())
		throw NotSignedException();
	if (executor.getGrade() > this->get_exec_req())
		throw GradeTooLowException();
	nb_lol++;
	std::cout << ITALIC << BOLD << "BRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR...." << FWHITE << std::endl;
	if ((nb_lol % 2) == 0)
	{
		std::cout << YELLOW << BOLD << this->target << FWHITE;
		std::cout << " has been robotomized succesfully !" << std::endl;
	}
	else
	{
		std::cout << "Robotomy of ";
		std::cout << YELLOW << BOLD << this->target << FWHITE;
		std::cout << " failed, try again !" << std::endl;
	}
}