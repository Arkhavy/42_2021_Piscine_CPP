/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:44:56 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/30 11:45:28 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <WrongAnimal.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << FAINT;
	std::cout << "WrongAnimal default constructor called.";
	std::cout << FWHITE << std::endl;
}

WrongAnimal::WrongAnimal(std::tring type) : type(type)
{
	std::cout << FAINT;
	std::cout << "WrongAnimal " << this->type << " constructor called.";
	std::cout << FWHITE << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& src)
{
	*this = src;
	std::cout << FAINT << CYAN;
	std::cout << "WrongAnimal " << this->type << " copy constructor called.";
	std::cout << FWHITE << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << FAINT;
	std::cout << "WrongAnimal " << this->type << " destructor called.";
	std::cout << FWHITE << std::endl;
}

/* ************************************************************************** */
/* Operator Overloads */
/* ************************************************************************** */
WrongAnimal&	WrongAnimal::operator=(WrongAnimal const& rhs)
{
	this->type = rhs.type;
	return (*this);
}

/* ************************************************************************** */
/* Public Member Functions */
/* ************************************************************************** */
void	WrongAnimal::makeSound()
{
	std::cout << RED << BOLD;
	std::cout << this->type;
	std::cout << FWHITE;
	std::cout << " is making a WrongAnimal sound ! OUI OUI BAGUETTE !" << std::endl;
}
