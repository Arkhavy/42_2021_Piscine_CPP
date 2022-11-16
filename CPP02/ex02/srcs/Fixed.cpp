/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 08:40:04 by ljohnson          #+#    #+#             */
/*   Updated: 2022/11/16 17:06:20 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>

/* ************************************************************************** */
/* Constructor & Destructors */
/* ************************************************************************** */
Fixed::Fixed() : value(0)
{
	// std::cout << "\033[2m";
	// std::cout << "Default constructor called";
	// std::cout << "\033[0m" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const& src)
{
	// std::cout << "\033[2m";
	// std::cout << "Copy constructor called";
	// std::cout << "\033[0m" << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed(int const nb)
{
	// std::cout << "\033[2m";
	// std::cout << "Int constructor called";
	// std::cout << "\033[0m" << std::endl;
	this->value = nb << this->bitnb;
	return ;
}

Fixed::Fixed(float const nb)
{
	// std::cout << "\033[2m";
	// std::cout << "Float constructor called";
	// std::cout << "\033[0m" << std::endl;
	this->value = roundf(nb * (1 << this->bitnb));
	return ;
}

Fixed::~Fixed()
{
	// std::cout << "\033[2m";
	// std::cout << "Destructor called";
	// std::cout << "\033[0m" << std::endl;
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
	float	result = (this->toFloat() + rhs.toFloat());

	return (Fixed(result));
}

Fixed	Fixed::operator-(Fixed const& rhs) const
{
	float	result = (this->toFloat() - rhs.toFloat());

	return (Fixed(result));
}

Fixed	Fixed::operator/(Fixed const& rhs) const
{
	float	result = this->toFloat() / rhs.toFloat();

	return (Fixed(result));
}

Fixed	Fixed::operator*(Fixed const& rhs) const
{
	float	result = this->toFloat() * rhs.toFloat();

	return (Fixed(result));
}

/* ************************************************************************** */
/* Comparison Operator overloads */
/* ************************************************************************** */
bool	Fixed::operator>(Fixed const& rhs) const {return (this->value > rhs.getRawBits());}

bool	Fixed::operator<(Fixed const& rhs) const {return (this->value < rhs.getRawBits());}

bool	Fixed::operator>=(Fixed const& rhs) const {return (this->value >= rhs.getRawBits());}

bool	Fixed::operator<=(Fixed const& rhs) const {return (this->value <= rhs.getRawBits());}

bool	Fixed::operator==(Fixed const& rhs) const {return (this->value == rhs.getRawBits());}

bool	Fixed::operator!=(Fixed const& rhs) const {return (this->value != rhs.getRawBits());}

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
