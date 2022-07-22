/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 08:45:28 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/22 11:41:43 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
Fixed::Fixed()
{
	std::cout << "\033[2m" << "Fixed Default Constructor called." << "\033[0m" << std::endl;
	this->value = 0;
	return ;
}

Fixed::Fixed(Fixed const& src)
{
	std::cout << "\033[2m" << "Fixed Copy Constructor called." << "\033[0m" << std::endl;
	*this = src;
	return ;
}

Fixed::~Fixed()
{
	std::cout << "\033[2m" << "Fixed Destructor called." << "\033[0m" << std::endl;
	return ;
}

/* ************************************************************************** */
/* Operator overloads */
/* ************************************************************************** */
Fixed&	Fixed::operator=(Fixed const& rhs)
{
	std::cout << "\033[2m" << "Fixed Copy assignment operator called." << "\033[0m" << std::endl;
	this->value = rhs.getRawBits();
	return (*this);
}

/* ************************************************************************** */
/* Public member functions */
/* ************************************************************************** */
int	Fixed::getRawBits() const
{
	std::cout << "\033[2m" << "Fixed getRawBits member function called" << "\033[0m" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "\033[2m" << "Fixed setRawBits member function called" << "\033[0m" << std::endl;
	this->value = raw;
}