/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:13:17 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/14 18:20:57 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Form.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
Form::Form() : name("Default form"), is_signed(false), sign_req(150), exec_req(150)
{
	std::cout << FAINT;
	std::cout << "Default Form constructor called.";
	std::cout << FWHITE << std::endl;
}

Form::Form(std::string const name, unsigned int const sign_req, unsigned int const exec_req) :
	name(name), is_signed(false), sign_req(sign_req), exec_req(exec_req)
{
	std::cout << FAINT;
	std::cout << this->name << " Form constructor called.";
	std::cout << FWHITE << std::endl;
}

Form::Form(Form const& src) : sign_req(src.sign_req), exec_req(src.exec_req)
{
	*this = src;
	std::cout << FAINT;
	std::cout << this->name << " Form copy constructor called.";
	std::cout << FWHITE << std::endl;
}

Form::~Form()
{
	std::cout << FAINT;
	std::cout << this->name << " From default destructor called.";
	std::cout << FWHITE << std::endl;
}

/* ************************************************************************** */
/* Operator Overloads */
/* ************************************************************************** */
Form&	Form::operator=(Form const& rhs)
{
	this->~Form();
	new(this) Form(rhs.get_name(), rhs.get_sign_req(), rhs.get_exec_req());
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, Form const& rhs)
{
	out << "--------------------------------------------------" << std::endl;
	out << "Form: " << rhs.get_name() << std::endl;
	out << "Is signed: " << rhs.get_is_signed() << std::endl;
	out << "Sign Requirement grade: " << rhs.get_sign_req() << std::endl;
	out << "Execution Requirement grade: " << rhs.get_exec_req() << std::endl;
	out << "--------------------------------------------------" << std::endl;
	return (out);
}

/* ************************************************************************** */
/* Exceptions */
/* ************************************************************************** */
char const*	Form::GradeTooHighException::what() const throw() {return ("Form Grade is too High !");}
char const*	Form::GradeTooLowException::what() const throw() {return ("Form Grade is too Low !");}
char const* Form::AlreadySignedException::what() const throw() {return ("Form is already signed !");}

/* ************************************************************************** */
/* Public Member Functions */
/* ************************************************************************** */
std::string	Form::get_name() const {return (this->name);}
bool	Form::get_is_signed() const {return (this->is_signed);}
unsigned int	Form::get_sign_req() const {return (this->sign_req);}
unsigned int	Form::get_exec_req() const {return (this->exec_req);}

void	Form::beSigned(Bureaucrat const& worker)
{
	if (worker.getGrade() > this->sign_req)
		throw GradeTooLowException();
	if (this->is_signed)
		throw AlreadySignedException();
	this->is_signed = true;
}