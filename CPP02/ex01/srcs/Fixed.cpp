/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:25:07 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/24 10:02:38 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>

/* ************************************************************************** */
/* Constructor & Destructors */
/* ************************************************************************** */
Fixed::Fixed() : value(0)
{
	std::cout << "\033[2m" << "Default constructor called" << "\033[0m" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const& src)
{
	std::cout << "\033[2m" << "Copy constructor called" << "\033[0m" << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed(int const nb)
{
	std::cout << "\033[2m" << "Int constructor called" << "\033[0m" << std::endl;
	this->value = nb << this->bitnb;
	return ;
}

Fixed::Fixed(float const nb)
{
	std::cout << "\033[2m" << "Float constructor called" << "\033[0m" << std::endl;
	this->value = roundf(nb * (1 << this->bitnb));
	return ;
}

Fixed::~Fixed()
{
	std::cout << "\033[2m" << "Destructor called" << "\033[0m" << std::endl;
	return ;
}

/* ************************************************************************** */
/* Public member functions */
/* ************************************************************************** */
int	Fixed::getRawBits() const
{
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw << this->bitnb;
	return ;
}

float	Fixed::toFloat() const
{
	return ((float)(this->value) / (float)(1 << this->bitnb));
}

int	Fixed::toInt() const
{
	return (this->value >> this->bitnb);
}

/* ************************************************************************** */
/* Operator overloads */
/* ************************************************************************** */
Fixed&	Fixed::operator=(Fixed const& rhs)
{
	std::cout << "\033[2m" << "Copy assignment operator called" << "\033[0m" << std::endl;
	this->value = rhs.getRawBits();
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, Fixed const& rhs)
{
	out << rhs.toFloat();
	return (out);
}
