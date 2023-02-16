/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:59:40 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/16 08:32:47 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
Bureaucrat::Bureaucrat() : name("Default"), grade(150) //Private
{
	if (this->grade < 1)
		throw GradeTooHighException();
	else if (this->grade > 150)
		throw GradeTooLowException();
	std::cout << FAINT;
	std::cout << "Default Bureaucrat constructor called.";
	std::cout << FWHITE << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, unsigned int const grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
	std::cout << FAINT;
	std::cout << "Bureaucrat " << this->name << " constructor called.";
	std::cout << FWHITE << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const& src)
{
	if (src.grade < 1)
		throw GradeTooHighException();
	else if (src.grade > 150)
		throw GradeTooLowException();
	*this = src;
	std::cout << FAINT;
	std::cout << "Bureaucrat " << this->name << " copy constructor called.";
	std::cout << FWHITE << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << FAINT;
	std::cout << "Bureaucrat " << this->name << " destructor called.";
	std::cout << FWHITE << std::endl;
}

/* ************************************************************************** */
/* Operator Overloads */
/* ************************************************************************** */
Bureaucrat&	Bureaucrat::operator=(Bureaucrat const& rhs)
{
	this->~Bureaucrat();
	new(this) Bureaucrat(rhs.getName(), rhs.getGrade());
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, Bureaucrat const& rhs)
{
	out << rhs.getName();
	out << ", bureaucrat grade ";
	out << rhs.getGrade() << "." << std::endl;
	return (out);
}

/* ************************************************************************** */
/* Exceptions */
/* ************************************************************************** */
char const*	Bureaucrat::GradeTooHighException::what() const throw() {return ("Bureaucrat Grade is too High !");}
char const*	Bureaucrat::GradeTooLowException::what() const throw() {return ("Bureaucrat Grade is too low !");}
char const* Bureaucrat::AlreadySignedException::what() const throw() {return ("Bureaucrat saw the AForm is already signed !");}
char const*	Bureaucrat::NotSignedException::what() const throw() {return ("Bureaucrat saw the AForm is not signed yet !");}
char const*	Bureaucrat::CannotExecuteException::what() const throw() {return ("Bureaucrat cannot execute form given !");}

/* ************************************************************************** */
/* Public Member Functions */
/* ************************************************************************** */
std::string const	Bureaucrat::getName() const {return (this->name);}
unsigned int	Bureaucrat::getGrade() const {return (this->grade);}

void	Bureaucrat::increment_grade()
{
	if ((this->grade - 1) < 1)
		throw GradeTooHighException();
	this->grade--;
}

void	Bureaucrat::decrement_grade()
{
	if ((this->grade + 1) > 150)
		throw GradeTooLowException();
	this->grade++;
}

void	Bureaucrat::signForm(AForm& form) const
{
	if (form.get_is_signed())
	{
		std::cout << this->name << " couldn't sign " << form.get_name() << " because ";
		throw AlreadySignedException();
	}
	if (this->grade > form.get_sign_req())
	{
		std::cout << this->name << " couldn't sign " << form.get_name() << ", ";
		throw GradeTooLowException();
	}
	form.beSigned(*this);
	std::cout << this->name << " signed AForm ";
	std::cout << CYAN << BOLD << form.get_name() << FWHITE << std::endl;
}

void	Bureaucrat::executeForm(AForm const& form)
{
	if (!form.get_is_signed())
		throw NotSignedException();
	if (this->grade > form.get_exec_req())
		throw CannotExecuteException();
	form.execute(*this);
	std::cout << GREEN << BOLD << this->name << FWHITE;
	std::cout << " executed successfully AForm ";
	std::cout << CYAN << BOLD << form.get_name() << FWHITE << std::endl;
}