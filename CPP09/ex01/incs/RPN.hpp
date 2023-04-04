/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:20:38 by ljohnson          #+#    #+#             */
/*   Updated: 2023/04/04 11:53:14 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <deque>

# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define PURPLE		"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

# define ERASE		"\033[2K\r"
# define RESET		"\033[0m"
# define BOLD		"\033[1m"
# define FAINT		"\033[2m"
# define ITALIC		"\033[3m"
# define UNDERLINE	"\033[4m"

class	RPN
{
	private:
		std::deque<std::string>	value;
	
	public:
	//Constructors & Destructors
		RPN();
		RPN(RPN const& src);
		virtual	~RPN();

		void				push_front(std::string const value);
		void				push_back(std::string const value);
		void				pop_front();
		void				pop_back();
		std::string const&	get_front() const;
		std::string const&	get_back() const;
		std::string const&	get_value_idx(size_t const idx) const;
		size_t				get_size() const;

	//Operator overloads
		RPN&	operator=(RPN const& rhs);

	//Getter & Setters
};

std::ostream&	operator<<(std::ostream& out, RPN const& rhs);

/* ************************************************************************** */
/* Exceptions */
/* ************************************************************************** */
class InvalidProgramNameException : public std::exception {public: virtual char const*	what() const throw();};
class InvalidArgumentException : public std::exception {public: virtual char const*	what() const throw();};

/* ************************************************************************** */
/* Templates */
/* ************************************************************************** */
template<typename T>
T	ft_print_msg(std::string const& message, T const val);

#include <RPN.tpp>