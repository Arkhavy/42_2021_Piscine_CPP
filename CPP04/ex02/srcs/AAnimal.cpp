/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:32:47 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/08 18:07:30 by ljohnson         ###   ########lyon.fr   */
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
const std::string&	AAnimal::getType() const {return (this->type);}

void	AAnimal::setType(std::string type) {this->type = type;}