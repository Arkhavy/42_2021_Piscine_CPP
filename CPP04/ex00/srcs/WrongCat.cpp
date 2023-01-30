/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:45:40 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/30 11:52:39 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <WrongCat.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << FAINT;
	std::cout << "WrongCat default constructor called.";
	std::cout << FWHITE << std::endl;
}

WrongCat::WrongCat(std::string type)
{
	this->type = type;
	std::cout << FAINT;
	std::cout << "WrongCat " << this->type << " constructor called.";
	std::cout << FWHITE << std::endl;
}

WrongCat::WrongCat(WrongCat const& src)
{
	*this = src;
	std::cout << FAINT << CYAN;
	std::cout << "WrongCat " << this->type << " copy constructor called.";
	std::cout << FWHITE << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << FAINT;
	std::cout << "WrongCat " << this->type << " destructor called.";
	std::cout << FWHITE << std::endl;
}

/* ************************************************************************** */
/* Operator Overloads */
/* ************************************************************************** */
WrongCat&	WrongCat::operator=(WrongCat const& rhs)
{
	this->type = rhs.type;
	return (*this);
}

/* ************************************************************************** */
/* Public Member Functions */
/* ************************************************************************** */
void	WrongCat::makeSound()
{
	std::cout << RED << BOLD;
	std::cout << this->type;
	std::cout << FWHITE;
	std::cout << " is making a WrongCat sound ! ROAR !" << std::endl;
}
