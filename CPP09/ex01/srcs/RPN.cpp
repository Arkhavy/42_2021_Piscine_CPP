/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:20:42 by ljohnson          #+#    #+#             */
/*   Updated: 2023/04/04 15:18:15 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
RPN::RPN() {}

RPN::RPN(RPN const& src) {*this = src;}

RPN::~RPN() {}

/* ************************************************************************** */
/* Operator Overloads */
/* ************************************************************************** */
RPN&	RPN::operator=(RPN const& rhs)
{
	for (size_t i = 0; i < rhs.get_size(); i++)
		this->data.push_back(rhs.data[i]);
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, RPN const& rhs)
{
	std::cout << "---RPN CONTENT BEGIN---" << std::endl;
	for (size_t i = 0; i < rhs.get_size(); i++)
	{
		out << rhs.get_value_idx(i);
		out << "\n";
	}
	std::cout << "---RPN CONTENT END---" << std::endl;
	return (out);
}

/* ************************************************************************** */
/* Exceptions */
/* ************************************************************************** */
char const*	InvalidProgramNameException::what()		const throw() {return ("ERROR: Invalid program name");}
char const*	InvalidArgumentException::what()		const throw() {return ("ERROR: Invalid argument given");}
char const*	NotEnoughElementException::what()		const throw() {return ("ERROR: Not enough element in queue to process operation");}
char const*	ImpossibleConversionException::what()	const throw() {return ("ERROR: Impossible conversion occured in operation");}
char const*	DivisionByZeroException::what()			const throw() {return ("ERROR: Division by zero occured in operation");}
char const*	QueueNotEmptyException::what()			const throw() {return ("ERROR: Queue is not empty at the end of the operation");}
char const*	OutOfRangeException::what()				const throw() {return ("ERROR: Out of range number in operation");}

/* ************************************************************************** */
/* Member Functions */
/* ************************************************************************** */
void	RPN::push_front(int const value) {this->data.push_front(value);}
void	RPN::push_back(int const value) {this->data.push_back(value);}
void	RPN::pop_front() {this->data.pop_front();}
void	RPN::pop_back() {this->data.pop_back();}

int const&	RPN::get_front() const {return (this->data.front());}
int const&	RPN::get_back() const {return (this->data.back());}
int const&	RPN::get_value_idx(size_t const idx) const
{
	if (idx >= this->data.size())
		return (this->data[0]);
	return (this->data[idx]);
}
size_t	RPN::get_size() const {return (this->data.size());}

/* ************************************************************************** */
/* MODULE : RPN OPERATION */
/* ************************************************************************** */
static int	rpn_op(char const symbol, int a, int const b)
{
	if (symbol == '+')
		a += b;
	else if (symbol == '-')
		a -= b;
	else if (symbol == '*')
		a *= b;
	else if (symbol == '/')
	{
		if (b == 0)
			throw DivisionByZeroException();
		a /= b;
	}
	return (a);
}

void	RPN::operation(std::string const& input)
{
	std::string	value;
	
	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i] != ' ')
		{
			value = input[i];
			if ((input[i] == '-' || input[i] == '+') && isdigit(input[i + 1]))
			{
				value += input[i + 1];
				i++;
			}
			else if (is_symbol(input[i]))
			{
				if (this->data.size() < 2)
					throw NotEnoughElementException();
				this->data[1] = rpn_op(input[i], this->data[1], this->data[0]);
				this->data.pop_front();
			}
			else
			{
				int nb = std::strtol(value.c_str(), NULL, 10);
				if (nb > INT_MAX || nb < (-INT_MAX - 1) || nb >= 10 || errno == ERANGE)
					throw OutOfRangeException();
				this->data.push_front(nb);
			}
			value.clear();
		}
	}
	if (this->data.size() > 1)
		throw QueueNotEmptyException();
}