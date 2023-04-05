/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:20:38 by ljohnson          #+#    #+#             */
/*   Updated: 2023/04/05 11:17:52 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <cerrno>
#include <climits>
#include <deque>
#include <cstdlib>

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
		std::deque<int>	data;
	
	public:
	//Constructors & Destructors
		RPN();
		RPN(RPN const& src);
		virtual	~RPN();

	//Operator overloads
		RPN&	operator=(RPN const& rhs);

	//Getter & Setters
		void		push_front(int const value);
		void		push_back(int const value);
		void		pop_front();
		void		pop_back();
		int const&	get_front() const;
		int const&	get_back() const;
		int const&	get_value_idx(size_t const idx) const;
		size_t		get_size() const;

	//Member functions
		void	operation(std::string const& input);
};

std::ostream&	operator<<(std::ostream& out, RPN const& rhs);
bool	is_symbol(char c);

/* ************************************************************************** */
/* Exceptions */
/* ************************************************************************** */
class InvalidProgramNameException	: public std::exception {public: virtual char const*	what() const throw();};
class InvalidArgumentException		: public std::exception {public: virtual char const*	what() const throw();};
class NotEnoughElementException		: public std::exception {public: virtual char const*	what() const throw();};
class ImpossibleConversionException	: public std::exception {public: virtual char const*	what() const throw();}; 
class DivisionByZeroException		: public std::exception {public: virtual char const*	what() const throw();};
class QueueNotEmptyException		: public std::exception {public: virtual char const*	what() const throw();};
class OutOfRangeException			: public std::exception {public: virtual char const*	what() const throw();};

/* ************************************************************************** */
/* Templates */
/* ************************************************************************** */
template<typename T>
T	ft_print_msg(char const* color, std::string const& message, T const val);

#include <RPN.tpp>