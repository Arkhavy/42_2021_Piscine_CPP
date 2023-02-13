/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:38:35 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/13 16:07:10 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ICharacter.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
ICharacter::ICharacter() : name("Default ICharacter name")
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	std::cout << FAINT;
	std::cout << "ICharacter default constructor called.";
	std::cout << FWHITE << std::endl;
}

ICharacter::ICharacter(std::string name) : name(name)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	std::cout << FAINT;
	std::cout << "ICharacter " << this->name << " constructor called.";
	std::cout << FWHITE << std::endl;
}

ICharacter::ICharacter(ICharacter const& src)
{
	*this = src;
	for (int i = 0; i < 4; i++)
	{
		delete this->inventory[i];
		this->inventory[i] = new AMateria(src.inventory[i]);
	}
	std::cout << FAINT;
	std::cout << "ICharacter " << this->name << " copy constructor called.";
	std::cout << FWHITE << std::endl;
}

ICharacter::~ICharacter()
{
	for (int i = 0; i < 4; i++)
	{
		delete this->inventory[i];
		this->inventory[i] = NULL;
	}
	std::cout << FAINT;
	std::cout << "ICharacter " << this->name << " default destructor called.";
	std::cout << FWHITE << std::endl;
}

/* ************************************************************************** */
/* Operator Overloads */
/* ************************************************************************** */
ICharacter&	ICharacter::operator=(ICharacter const& rhs)
{
	this->name = rhs.name;
	for (int i = 0; i < 4; i++)
	{
		delete this->inventory[i];
		this->inventory[i] = new AMateria(rhs.inventory[i]);
	}
	return (*this);
}
/* ************************************************************************** */
/* Public Member Functions */
/* ************************************************************************** */
//Interface is full of pure member function blblblbl
