/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:13:17 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/15 13:24:36 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <AForm.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
AForm::AForm() : name("Default AForm"), is_signed(false), sign_req(150), exec_req(150)
{
	if (this->sign_req < 1 || this->exec_req < 1)
		throw GradeTooHighException();
	else if (this->sign_req > 150 || this->exec_req > 150)
		throw GradeTooLowException();
	std::cout << FAINT;
	std::cout << "Default AForm constructor called.";
	std::cout << FWHITE << std::endl;
}

AForm::AForm(std::string const name, unsigned int const sign_req, unsigned int const exec_req) :
	name(name), is_signed(false), sign_req(sign_req), exec_req(exec_req)
{
	if (sign_req < 1 || exec_req < 1)
		throw GradeTooHighException();
	else if (sign_req > 150 || exec_req > 150)
		throw GradeTooLowException();
	std::cout << FAINT;
	std::cout << this->name << " AForm constructor called.";
	std::cout << FWHITE << std::endl;
}

AForm::AForm(AForm const& src) : sign_req(src.sign_req), exec_req(src.exec_req)
{
	if (src.sign_req < 1 || src.exec_req < 1)
		throw GradeTooHighException();
	else if (src.sign_req > 150 || src.exec_req > 150)
		throw GradeTooLowException();
	*this = src;
	std::cout << FAINT;
	std::cout << this->name << " AForm copy constructor called.";
	std::cout << FWHITE << std::endl;
}

AForm::~AForm()
{
	std::cout << FAINT;
	std::cout << this->name << " AForm default destructor called.";
	std::cout << FWHITE << std::endl;
}

/* ************************************************************************** */
/* Operator Overloads */
/* ************************************************************************** */
AForm&	AForm::operator=(AForm const& rhs)
{
	(void)rhs;
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, AForm const& rhs)
{
	out << FAINT << "----------" << FWHITE << std::endl;

	out << "AForm: " << CYAN << BOLD;
	out << rhs.get_name();
	out << FWHITE << std::endl;

	out << "Is signed: " << CYAN << BOLD;
	out << rhs.get_is_signed();
	out << FWHITE << std::endl;

	out << "Sign Requirement grade: " << CYAN << BOLD;
	out << rhs.get_sign_req();
	out << FWHITE << std::endl;

	out << "Execution Requirement grade: " << CYAN << BOLD;
	out << rhs.get_exec_req();
	out << FWHITE << std::endl;

	out << FAINT << "----------" << FWHITE << std::endl;
	return (out);
}

/* ************************************************************************** */
/* Exceptions */
/* ************************************************************************** */
char const*	AForm::GradeTooHighException::what() const throw() {return ("AForm Grade is too High !");}
char const*	AForm::GradeTooLowException::what() const throw() {return ("AForm Grade is too Low !");}
char const* AForm::AlreadySignedException::what() const throw() {return ("AForm is already signed !");}
char const*	AForm::NotSignedException::what() const throw() {return ("AForm is not signed yet !");}

/* ************************************************************************** */
/* Public Member Functions */
/* ************************************************************************** */
std::string	AForm::get_name() const {return (this->name);}
bool	AForm::get_is_signed() const {return (this->is_signed);}
unsigned int	AForm::get_sign_req() const {return (this->sign_req);}
unsigned int	AForm::get_exec_req() const {return (this->exec_req);}

void	AForm::beSigned(Bureaucrat const& worker)
{
	if (worker.getGrade() > this->sign_req)
		throw GradeTooLowException();
	if (this->is_signed)
		throw AlreadySignedException();
	this->is_signed = true;
}