/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:20:16 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/24 15:34:36 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>

/* ************************************************************************** */
/* Constructor & Destructors */
/* ************************************************************************** */
Fixed::Fixed() : value(0)
{
	// std::cout << "\033[2m" << "Default Fixed constructor called" << "\033[0m" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const& src)
{
	// std::cout << "\033[2m" << "Copy Fixed constructor called" << "\033[0m" << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed(int const nb)
{
	// std::cout << "\033[2m" << "Int Fixed constructor called" << "\033[0m" << std::endl;
	this->value = nb << this->bitnb;
	return ;
}

Fixed::Fixed(float const nb)
{
	// std::cout << "\033[2m" << "Float Fixed constructor called" << "\033[0m" << std::endl;
	this->value = roundf(nb * (1 << this->bitnb));
	return ;
}

Fixed::~Fixed()
{
	// std::cout << "\033[2m" << "Fixed Destructor called" << "\033[0m" << std::endl;
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
/* Arithmetic Operator overloads */
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
	if (rhs.getRawBits() == 0)
		return (0);
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed	Fixed::operator*(Fixed const& rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

/* ************************************************************************** */
/* Comparison Operator overloads */
/* ************************************************************************** */
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

/* ************************************************************************** */
/* Incrementation & Decrementation Operator overloads */
/* ************************************************************************** */
Fixed&	Fixed::operator++()
{
	this->value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	++*this;
	return (tmp);
}

Fixed&	Fixed::operator--()
{
	this->value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;
	++*this;
	return (tmp);
}

/* ************************************************************************** */
/* Stream Operator overloads */
/* ************************************************************************** */
std::ostream&	operator<<(std::ostream& out, Fixed const& rhs)
{
	out << rhs.toFloat();
	return (out);
}
