/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:20:42 by ljohnson          #+#    #+#             */
/*   Updated: 2023/04/20 16:07:27 by ljohnson         ###   ########lyon.fr   */
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
	size_t	rhs_size = rhs.get_size();

	for (size_t i = 0; i < rhs_size; i++)
		this->data.push_back(rhs.data[i]);
	return (*this);
}

/* ************************************************************************** */
/* Exceptions */
/* ************************************************************************** */
char const*	InvalidProgramNameException::what()		const throw() {return ("ERROR: Invalid program name");}
char const*	InvalidArgumentException::what()		const throw() {return ("ERROR: Invalid argument given");}
char const*	NotEnoughElementException::what()		const throw() {return ("ERROR: Not enough element in numbers queue to process operation");}
char const*	DivisionByZeroException::what()			const throw() {return ("ERROR: Division by zero occured in operation");}
char const*	QueueNotEmptyException::what()			const throw() {return ("ERROR: Numbers Queue is not empty at the end of the operation");}
char const*	OutOfRangeException::what()				const throw() {return ("ERROR: Out of range number in operation");}

/* ************************************************************************** */
/* Member Functions */
/* ************************************************************************** */
int const&	RPN::get_front() const {return (this->data.front());}
size_t	RPN::get_size() const {return (this->data.size());}

/* ************************************************************************** */
/* MODULE : RPN OPERATION */
/* ************************************************************************** */
static int	rpn_op(char const symbol, long long int a, int const b)
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
	if (a > INT_MAX || a < (-INT_MAX - 1) || errno == ERANGE)
		throw OutOfRangeException();
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
				value.clear();
				continue ;
			}
			int nb = std::strtol(value.c_str(), NULL, 10);
			if (nb > INT_MAX || nb < (-INT_MAX - 1) || nb >= 10 || errno == ERANGE)
				throw OutOfRangeException();
			this->data.push_front(nb);
			value.clear();
		}
	}
	if (this->data.size() > 1)
		throw QueueNotEmptyException();
}