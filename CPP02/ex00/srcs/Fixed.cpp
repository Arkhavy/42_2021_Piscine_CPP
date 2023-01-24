/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 08:45:28 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/24 08:11:03 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
Fixed::Fixed() : value(0)
{
	std::cout << "\033[2m";
	std::cout << "Fixed Default Constructor called.";
	std::cout << "\033[0m" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const& src)
{
	std::cout << "\033[2m";
	std::cout << "Fixed Copy Constructor called.";
	std::cout << "\033[0m" << std::endl;
	*this = src;
	return ;
}

Fixed::~Fixed()
{
	std::cout << "\033[2m";
	std::cout << "Fixed Destructor called.";
	std::cout << "\033[0m" << std::endl;
	return ;
}

/* ************************************************************************** */
/* Operator overloads */
/* ************************************************************************** */
Fixed&	Fixed::operator=(Fixed const& rhs)
{
	std::cout << "\033[2m";
	std::cout << "Fixed Copy assignment operator called.";
	std::cout << "\033[0m" << std::endl;
	this->value = rhs.getRawBits();
	return (*this);
}

/* ************************************************************************** */
/* Public member functions */
/* ************************************************************************** */
int	Fixed::getRawBits() const
{
	std::cout << "\033[2m";
	std::cout << "Fixed getRawBits member function called";
	std::cout << "\033[0m" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "\033[2m";
	std::cout << "Fixed setRawBits member function called";
	std::cout << "\033[0m" << std::endl;
	this->value = raw;
	return ;
}