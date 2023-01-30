/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:44:56 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/30 13:39:19 by ljohnson         ###   ########lyon.fr   */
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

WrongAnimal::WrongAnimal(std::string type) : type(type)
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
void	WrongAnimal::makeSound() const
{
	std::cout << RED << BOLD;
	std::cout << this->type;
	std::cout << FWHITE;
	std::cout << " is making a WrongAnimal sound ! OUI OUI BAGUETTE !" << std::endl;
}

const std::string&	WrongAnimal::getType() const {return (this->type);}
void	WrongAnimal::setType(std::string type) {this->type = type;}