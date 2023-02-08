/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:22:26 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/08 18:31:53 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <AMateria.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
AMateria::AMateria() : type("Default Materia type")
{
	std::cout << FAINT;
	std::cout << "AMateria default constructor called.";
	std::cout << FWHITE << std::endl;
}

AMateria::AMateria(std::string const& type) : type(type)
{
	std::cout << FAINT;
	std::cout << "AMateria" << this->type;
	std::cout << " constructor called.";
	std::cout << FWHITE << std::endl;
}

AMateria::AMateria(AMateria const& src)
{
	*this = src;
	std::cout << FAINT << CYAN;
	std::cout << "AMateria" << this->type;
	std::cout << " copy constructor called.";
	std::cout << FWHITE << std::endl;
}

AMateria::~AMateria()
{
	std::cout << FAINT;
	std::cout << "AMateria" << this->type;
	std::cout << " default destructor called.";
	std::cout << FWHITE << std::endl;
}

/* ************************************************************************** */
/* Operator Overloads */
/* ************************************************************************** */
AMateria&	AMateria::operator=(AMateria const& rhs)
{
	this->type = rhs.type;
	return (*this);
}

/* ************************************************************************** */
/* Public Member Functions */
/* ************************************************************************** */
std::string const&	AMateria::getType() const {return (this->type);}

void	AMateria::use(ICharacter& target)
{
	//ouaf
	return ;
}