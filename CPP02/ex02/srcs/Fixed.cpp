/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 08:40:04 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/24 11:54:27 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>

/* ************************************************************************** */
/* Constructor & Destructors */
/* ************************************************************************** */
Fixed::Fixed() : value(0)
{
	// std::cout << "\033[2m" << "Default constructor called" << "\033[0m" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const& src)
{
	// std::cout << "\033[2m" << "Copy constructor called" << "\033[0m" << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed(int const nb)
{
	// std::cout << "\033[2m" << "Int constructor called" << "\033[0m" << std::endl;
	this->value = nb << this->bitnb;
	return ;
}

Fixed::Fixed(float const nb)
{
	// std::cout << "\033[2m" << "Float constructor called" << "\033[0m" << std::endl;
	this->value = roundf(nb * (1 << this->bitnb));
	return ;
}

Fixed::~Fixed()
{
	// std::cout << "\033[2m" << "Destructor called" << "\033[0m" << std::endl;
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
}

float	Fixed::toFloat() const
{
	return ((float)(this->value) / (float)(1 << this->bitnb));
}

int	Fixed::toInt() const
{
	return (this->value >> this->bitnb);
}

const Fixed&	Fixed::min(Fixed const& lhs, Fixed const& rhs)
{
	if (lhs < rhs)
		return (lhs);
	return (rhs);
}

const Fixed&	Fixed::max(Fixed const& lhs, Fixed const& rhs)
{
	if (lhs > rhs)
		return (lhs);
	return (rhs);
}

const Fixed&	Fixed::min(Fixed& lhs, Fixed& rhs)
{
	if (lhs < rhs)
		return (lhs);
	return (rhs);
}

const Fixed&	Fixed::max(Fixed& lhs, Fixed& rhs)
{
	if (lhs > rhs)
		return (lhs);
	return (rhs);
}


/* ************************************************************************** */
/* Operator overloads */
/* ************************************************************************** */

Fixed&	Fixed::operator=(Fixed const& rhs)
{
	this->value = rhs.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(Fixed const& rhs) const
{
	return (Fixed((this->value + rhs.getRawBits()) >> this->bitnb));
}

Fixed	Fixed::operator-(Fixed const& rhs) const
{
	return (Fixed((this->value - rhs.getRawBits()) >> this->bitnb));
}

Fixed	Fixed::operator/(Fixed const& rhs) const
{
	float	lhsval = this->value >> this->bitnb;
	float	rhsval = rhs.getRawBits() >> this->bitnb;

	if (rhs.getRawBits() == 0)
		return (0);
	return (Fixed((lhsval / rhsval)));
}

Fixed	Fixed::operator*(Fixed const& rhs) const
{
	float	lhsval = this->value >> this->bitnb;
	float	rhsval = rhs.getRawBits() >> this->bitnb;

	return (Fixed((lhsval * rhsval)));
}

int	Fixed::operator>(Fixed const& rhs) const
{
	if (this->value > rhs.getRawBits())
		return (1);
	return (0);
}

int	Fixed::operator<(Fixed const& rhs) const
{
	if (this->value < rhs.getRawBits())
		return (1);
	return (0);
}

int	Fixed::operator>=(Fixed const& rhs) const
{
	if (this->value >= rhs.getRawBits())
		return (1);
	return (0);
}

int	Fixed::operator<=(Fixed const& rhs) const
{
	if (this->value <= rhs.getRawBits())
		return (1);
	return (0);
}

int	Fixed::operator==(Fixed const& rhs) const
{
	if (this->value == rhs.getRawBits())
		return (1);
	return (0);
}

int	Fixed::operator!=(Fixed const& rhs) const
{
	if (this->value != rhs.getRawBits())
		return (1);
	return (0);
}

std::ostream&	operator<<(std::ostream& out, Fixed const& rhs)
{
	out << rhs.toFloat();
	return (out);
}
