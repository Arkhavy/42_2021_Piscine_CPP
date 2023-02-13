/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:26:57 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/10 19:40:23 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Ice.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
Ice::Ice()
{
	this->type = "cure";
	std::cout << FAINT;
	std::cout << "Ice default constructor called.";
	std::cout << FWHITE << std::endl;
}

Ice::Ice(std::string const& type) : AMateria(type)
{
	std::cout << FAINT;
	std::cout << "Materia" << this->type;
	std::cout << " constructor called.";
	std::cout << FWHITE << std::endl;
}

Ice::Ice(Ice const& src) : AMateria(src)
{
	*this = src;
	std::cout << FAINT;
	std::cout << "Materia" << this->type;
	std::cout << " copy constructor called.";
	std::cout << FWHITE << std::endl;
}

Ice::~Ice()
{
	std::cout << FAINT;
	std::cout << "Materia" << this->type;
	std::cout << " default destructor called.";
	std::cout << FWHITE << std::endl;
}

/* ************************************************************************** */
/* Operator Overloads */
/* ************************************************************************** */
Ice&	Ice::operator=(Ice const& rhs)
{
	this->type = rhs.type;
	return (*this);
}

/* ************************************************************************** */
/* Public Member Functions */
/* ************************************************************************** */
Ice*	Ice::clone() const {return (new Ice());}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << GREEN;
	std::cout << target.getName() << FWHITE;
	std::cout << " *";
}