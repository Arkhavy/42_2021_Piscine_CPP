/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:13:17 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/15 11:46:28 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>

#include <Bureaucrat.hpp>
class Bureaucrat;

#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define PURPLE "\033[35m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BOLD "\033[1m"
#define FAINT "\033[2m"
#define FWHITE "\033[0m"

class AForm
{
	private:
		AForm();
		std::string const	name;
		bool				is_signed;
		unsigned int const	sign_req; //range from highest 1 to lowest 150
		unsigned int const	exec_req; //range from highest 1 to lowest 150

	public:
		//Constructors & Destructors
		AForm(std::string const name, unsigned int const sign_req, unsigned int const exec_req);
		AForm(AForm const& src);
		virtual ~AForm();

		void			beSigned(Bureaucrat const& worker);
		virtual void	execute(Bureaucrat const& executor) const = 0;


		//Getters & Setters
		std::string		get_name() const;
		bool			get_is_signed() const;
		unsigned int	get_sign_req() const;
		unsigned int	get_exec_req() const;

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

		class NotSignedException : public std::exception
		{
			public:
				virtual char const* what() const throw();
		};

		//Operator overloads
		AForm&	operator=(AForm const& rhs);
};

std::ostream&	operator<<(std::ostream& out, AForm const& rhs);