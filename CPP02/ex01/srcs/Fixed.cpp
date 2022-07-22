/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:25:07 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/22 13:48:42 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>

/* ************************************************************************** */
/* Constructor & Destructors */
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

Fixed::Fixed(int const nb)
{
	std::cout << "\033[2m" << "Fixed int Constructor called." << "\033[0m" << std::endl;
	return ;
}

Fixed::Fixed(float const nb)
{
	std::cout << "\033[2m" << "Fixed float Constructor called." << "\033[0m" << std::endl;
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

Fixed	Fixed::operator<<(Fixed const& rhs)
{
	std::cout << "\033[2m" << "Fixed insertion operator called." << "\033[0m" << std::endl;
	return (*this);
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