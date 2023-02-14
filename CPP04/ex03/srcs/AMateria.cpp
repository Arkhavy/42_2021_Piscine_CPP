/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:22:26 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/14 08:21:02 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <AMateria.hpp>
#include <ICharacter.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
AMateria::AMateria() : type("AMateria"), equipped(false)
{
	std::cout << FAINT;
	std::cout << "AMateria default constructor called.";
	std::cout << FWHITE << std::endl;
}

AMateria::AMateria(std::string const& type) : type(type), equipped(false)
{
	std::cout << FAINT;
	std::cout << "Materia" << this->type;
	std::cout << " constructor called.";
	std::cout << FWHITE << std::endl;
}

AMateria::AMateria(AMateria const& src)
{
	*this = src;
	std::cout << FAINT;
	std::cout << "Materia" << this->type;
	std::cout << " copy constructor called.";
	std::cout << FWHITE << std::endl;
}

AMateria::~AMateria()
{
	std::cout << FAINT;
	std::cout << "Materia" << this->type;
	std::cout << " default destructor called.";
	std::cout << FWHITE << std::endl;
}

/* ************************************************************************** */
/* Operator Overloads */
/* ************************************************************************** */
AMateria&	AMateria::operator=(AMateria const& rhs)
{
	this->type = rhs.type;
	this->equipped = rhs.equipped;
	return (*this);
}

/* ************************************************************************** */
/* Public Member Functions */
/* ************************************************************************** */
std::string const&	AMateria::getType() const {return (this->type);}
bool	const&	AMateria::getEquipped() const {return (this->equipped);}

void	AMateria::setEquipped(bool equipped) {this->equipped = equipped;}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* use an Abstract Materia on " << GREEN;
	std::cout << target.getName() << FWHITE;
	std::cout << " *" << std::endl;
}