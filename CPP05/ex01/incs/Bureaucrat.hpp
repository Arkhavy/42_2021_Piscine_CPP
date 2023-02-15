/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:34:11 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/15 11:33:10 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>

#include <Form.hpp>
class Form;

#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define PURPLE "\033[35m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BOLD "\033[1m"
#define FAINT "\033[2m"
#define FWHITE "\033[0m"

class Bureaucrat
{
	private:
		Bureaucrat();
		std::string const	name;
		unsigned int		grade; //range from highest 1 to lowest 150

	public:
		//Constructors & Destructors
		Bureaucrat(std::string const name, unsigned int const grade);
		Bureaucrat(Bureaucrat const& src);
		~Bureaucrat();

		void				signForm(Form& form) const;

		//Getters & Setters
		std::string const	getName() const;
		unsigned int		getGrade() const;
		void				increment_grade();
		void				decrement_grade();

		//Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual char const* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual char const* what() const throw();
		};

		class AlreadySignedException : public std::exception
		{
			public:
				virtual char const* what() const throw();
		};

		//Operator overloads
		Bureaucrat&	operator=(Bureaucrat const& rhs);
};

std::ostream&	operator<<(std::ostream& out, Bureaucrat const& rhs);