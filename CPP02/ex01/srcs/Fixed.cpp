/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:25:07 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/23 17:22:36 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>

/* ************************************************************************** */
/* Constructor & Destructors */
/* ************************************************************************** */
Fixed::Fixed() : value(0)
{
	std::cout << "\033[2m" << "Fixed Default Constructor called." << "\033[0m" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const& src)
{
	std::cout << "\033[2m" << "Fixed Copy Constructor called." << "\033[0m" << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed(int const nb)
{
	std::cout << "\033[2m" << "Fixed int Constructor called." << "\033[0m" << std::endl;
	this->value = nb << this->bitnb;
	return ;
}

Fixed::Fixed(float const nb)
{
	std::cout << "\033[2m" << "Fixed float Constructor called." << "\033[0m" << std::endl;
	this->value = roundf(nb);
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
	this->value = rhs.getRawBits();
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, Fixed const& rhs)
{
	out << rhs.toFloat();
	return (out);
}

/* ************************************************************************** */
/* Public member functions */
/* ************************************************************************** */
int	Fixed::getRawBits() const
{
	std::cout << "\033[2m" << "Fixed getRawBits member function called." << "\033[0m" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "\033[2m" << "Fixed setRawBits member function called." << "\033[0m" << std::endl;
	this->value = raw;
	return ;
}

float	Fixed::toFloat() const
{
	return ((float)this->value);
}

int	Fixed::toInt() const
{
	return ((int)this->value);
}
