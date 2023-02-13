/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:26:42 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/13 11:56:30 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Character.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
Character::Character() : name("Default Character name")
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	std::cout << FAINT;
	std::cout << "Character default constructor called.";
	std::cout << FWHITE << std::endl;
}

Character::Character(std::string name)
{
	this->name = name;
	std::cout << FAINT;
	std::cout << "Character " << this->name << " constructor called.";
	std::cout << FWHITE << std::endl;
}

Character::Character(Character const& src)
{
	*this = src;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = new src.inventory[i];
	std::cout << FAINT;
	std::cout << "Character Copy constructor called.";
	std::cout << FWHITE << std::endl;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		delete this->inventory[i];
		this->inventory[i] = NULL;
	}
	std::cout << FAINT;
	std::cout << this->name;
	std::cout << " default destructor called.";
	std::cout << FWHITE << std::endl;
}

/* ************************************************************************** */
/* Operator overloads */
/* ************************************************************************** */
Character&	Character::operator=(Character const& rhs)
{
	this->name = rhs.name;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = rhs.inventory[i];
}
/* ************************************************************************** */
/* Public Member Functions */
/* ************************************************************************** */
std::string const&	Character::getName() const {return (this->name);}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] = NULL)
			this->inventory[i] = m;
	}
}

void	Character::unequip(int idx)
{
	
}

void	Character::use(int idx, Character& target)
{
	
}
/*
Notes :
Materia can be given to equip() with clone() member function
	We need a way to delete those if unequip() is used
	unequip() can't delete the Materia
		idea 1 : get the address before calling unequip() in main()
		idea 2 : materia destructor can delete, but stack init materias will cause problems
		idea 3 : Character destructor can delete, we need to check if it works with NULL

inventory of character is empty at its construction
	It means that Materias have to be created before being equipped with equip()
		Clone gives a heap pointer, can still save it in a list ?

equip(AMateria* m) puts a materia in the first empty slot found
	if no empty slot is found, don't do anything
	if materia is already equipped, error message

unequip(int idx) removes a materia from the idx slot given
	if wrong idx or empty slot, don't do anything

use(int idx, ICharacter& target)
	if wrong idx or empty slot, don't do anything
	use() can delete the materia
		question : what happen if we delete a stack initialized materia ?
	this function has to call the Materia use() function
*/