/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:25:07 by ljohnson          #+#    #+#             */
/*   Updated: 2022/11/15 09:58:32 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>

/* ************************************************************************** */
/* Constructor & Destructors */
/* ************************************************************************** */
Fixed::Fixed() : value(0)
{
	std::cout << "\033[2m";
	std::cout << "Default constructor called";
	std::cout << "\033[0m" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const& src)
{
	std::cout << "\033[2m";
	std::cout << "Copy constructor called";
	std::cout << "\033[0m" << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed(int const nb)
{
	std::cout << "\033[2m";
	std::cout << "Int constructor called";
	std::cout << "\033[0m" << std::endl;
	this->value = nb << this->bitnb;
	return ;
}

Fixed::Fixed(float const nb)
{
	std::cout << "\033[2m";
	std::cout << "Float constructor called";
	std::cout << "\033[0m" << std::endl;
	this->value = roundf(nb * (1 << this->bitnb));
	return ;
}

Fixed::~Fixed()
{
	std::cout << "\033[2m";
	std::cout << "Destructor called";
	std::cout << "\033[0m" << std::endl;
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
	this->value = raw;
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
	std::cout << "\033[2m";
	std::cout << "Copy assignment operator called";
	std::cout << "\033[0m" << std::endl;
	this->value = rhs.getRawBits();
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, Fixed const& rhs)
{
	out << rhs.toFloat();
	return (out);
}
