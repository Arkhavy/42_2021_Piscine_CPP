/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:32:47 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/06 15:14:33 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <AAnimal.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
AAnimal::AAnimal() : type("AAnimal")
{
	std::cout << FAINT;
	std::cout << "AAnimal default constructor called.";
	std::cout << FWHITE << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type)
{
	std::cout << FAINT;
	std::cout << "AAnimal " << this->type << " constructor called.";
	std::cout << FWHITE << std::endl;
}

AAnimal::AAnimal(AAnimal const& src)
{
	*this = src;
	std::cout << FAINT << CYAN;
	std::cout << "AAnimal " << this->type << " copy constructor called.";
	std::cout << FWHITE << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << FAINT;
	std::cout << "AAnimal " << this->type << " destructor called.";
	std::cout << FWHITE << std::endl;
}

/* ************************************************************************** */
/* Operator Overloads */
/* ************************************************************************** */
AAnimal&	AAnimal::operator=(AAnimal const& rhs)
{
	this->type = rhs.type;
	return (*this);
}

/* ************************************************************************** */
/* Public Member Functions */
/* ************************************************************************** */
void	AAnimal::makeSound() const
{
	std::cout << GREEN << BOLD;
	std::cout << this->type;
	std::cout << FWHITE;
	std::cout << " is making an AAnimal sound ! GRAOU !" << std::endl;
}

const std::string&	AAnimal::getType() const {return (this->type);}
void	AAnimal::setType(std::string type) {this->type = type;}