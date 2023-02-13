/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:11:51 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/13 13:15:21 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Cure.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
Cure::Cure()
{
	this->type = "cure";
	this->equipped = 0;
	std::cout << FAINT;
	std::cout << "Cure default constructor called.";
	std::cout << FWHITE << std::endl;
}

Cure::Cure(std::string const& type) : AMateria(type)
{
	this->type = type;
	this->equipped = 0;
	std::cout << FAINT;
	std::cout << "Materia" << this->type;
	std::cout << " constructor called.";
	std::cout << FWHITE << std::endl;
}

Cure::Cure(Cure const& src) : AMateria(src)
{
	*this = src;
	std::cout << FAINT;
	std::cout << "Materia" << this->type;
	std::cout << " copy constructor called.";
	std::cout << FWHITE << std::endl;
}

Cure::~Cure()
{
	std::cout << FAINT;
	std::cout << "Materia" << this->type;
	std::cout << " default destructor called.";
	std::cout << FWHITE << std::endl;
}

/* ************************************************************************** */
/* Operator Overloads */
/* ************************************************************************** */
Cure&	Cure::operator=(Cure const& rhs)
{
	this->type = rhs.type;
	this->equipped = rhs.equipped;
	return (*this);
}
/* ************************************************************************** */
/* Public Member Functions */
/* ************************************************************************** */
Cure*	Cure::clone() const {return (new Cure());}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << GREEN;
	std::cout << target.getName() << FWHITE;
	std::cout << "'s wounds *";
}