/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:20:42 by ljohnson          #+#    #+#             */
/*   Updated: 2023/04/04 11:53:11 by ljohnson         ###   ########lyon.fr   */
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
		this->value.push_back(rhs.value[i]);
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, RPN const& rhs)
{
	for (size_t i = 0; i < rhs.get_size(); i++)
		out << rhs.get_value_idx(i);
	return (out);
}

/* ************************************************************************** */
/* Exceptions */
/* ************************************************************************** */
char const*	InvalidProgramNameException::what()	const throw() {return ("ERROR: Invalid program name");}
char const*	InvalidArgumentException::what()	const throw() {return ("ERROR: Invalid argument given");}

/* ************************************************************************** */
/* Member Functions */
/* ************************************************************************** */
void	RPN::push_front(std::string const value) {this->value.push_front(value);}
void	RPN::push_back(std::string const value) {this->value.push_back(value);}
void	RPN::pop_front() {this->value.pop_front();}
void	RPN::pop_back() {this->value.pop_back();}

std::string const&	RPN::get_front() const {return (this->value.front());}
std::string const&	RPN::get_back() const {return (this->value.back());}
std::string const&	RPN::get_value_idx(size_t const idx) const
{
	if (idx >= this->value.size())
		return (this->value[0]);
	return (this->value[idx]);
}
size_t	RPN::get_size() const {return (this->value.size());}