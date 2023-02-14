/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:26:42 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/14 08:13:38 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Character.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
Character::Character()
{
	this->name = "Default character name";
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	std::cout << FAINT;
	std::cout << "Character default constructor called.";
	std::cout << FWHITE << std::endl;
}

Character::Character(std::string name)
{
	this->name = name;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	std::cout << FAINT;
	std::cout << "Character " << this->name << " constructor called.";
	std::cout << FWHITE << std::endl;
}

Character::Character(Character const& src) : ICharacter(src)
{
	*this = src;
	for (int i = 0; i < 4; i++)
	{
		delete this->inventory[i];
		if (src.inventory[i] == NULL)
			this->inventory[i] = NULL;
		else
			this->inventory[i] = src.inventory[i]->clone();
	}
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
	{
		delete this->inventory[i];
		if (rhs.inventory[i] == NULL)
			this->inventory[i] = NULL;
		else
			this->inventory[i] = rhs.inventory[i]->clone();
	}
	return (*this);
}
/* ************************************************************************** */
/* Public Member Functions */
/* ************************************************************************** */
std::string const&	Character::getName() const {return (this->name);}

void	Character::equip(AMateria* m)
{
	if (m->getEquipped() == true)
	{
		std::cerr << RED << BOLD;
		std::cerr << "ERROR: The Materia " << m->getType() << " is already equipped !";
		std::cerr << FWHITE << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			m->setEquipped(true);
			std::cout << "Materia" << m->getType() << " successfully equipped !" << std::endl;
			return ;
		}
	}
	std::cerr << RED << BOLD;
	std::cerr << "ERROR: " << this->name << "'s inventory does not have any empty Materia slot !";
	std::cerr << FWHITE << std::endl;
}

void	Character::unequip(int idx)
{
	std::string	tmp_type;

	if (idx < 0 || idx > 3)
	{
		std::cerr << RED << BOLD;
		std::cerr << "ERROR: " << this->name << "cannot unequip something out of the range of the inventory !";
		std::cerr << FWHITE << std::endl;
		return ;
	}
	if (this->inventory[idx] == NULL)
	{
		std::cerr << RED << BOLD;
		std::cerr << "ERROR: There is no Materia in the inventory slot given for " << this->name << " !";
		std::cerr << FWHITE << std::endl;
		return ;
	}
	tmp_type = this->inventory[idx]->getType();
	this->inventory[idx]->setEquipped(false);
	this->inventory[idx] = NULL;
	std::cout << this->name << " successfully unequipped " << tmp_type << " Materia !" << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cerr << RED << BOLD;
		std::cerr << "ERROR: " << this->name << " cannot use something out of the range of the inventory !";
		std::cerr << FWHITE << std::endl;
		return ;
	}
	if (this->inventory[idx] == NULL)
	{
		std::cerr << RED << BOLD;
		std::cerr << "ERROR: There is no Materia in the inventory slot given for " << this->name << " !";
		std::cerr << FWHITE << std::endl;
		return ;
	}
	std::cout << this->name << " ";
	this->inventory[idx]->use(target);
	delete this->inventory[idx];
	this->inventory[idx] = NULL;
}

/*
Notes :
Materia can be given to equip() with clone() member function
	We need a way to delete those if unequip() is used
	unequip() can't delete the Materia
		idea 1 : get the address before calling unequip() in main() and delete in main
		idea 2 : materia destructor can delete, but stack init materias might cause problems
		idea 3 : Character destructor can delete, but we need to check if it works with NULL

inventory of character is empty at its construction
	It means that Materias have to be created before being equipped with equip()
		Clone gives a heap pointer, can still save it in a list ?

equip(AMateria* m) puts a materia in the first empty slot found
	if no empty slot is found, don't do anything OK
	if materia is already equipped, error message OK

unequip(int idx) removes a materia from the idx slot given
	if wrong idx or empty slot, don't do anything OK

use(int idx, ICharacter& target)
	if wrong idx or empty slot, don't do anything OK
	use() can delete the materia
		question : what happen if we delete a stack initialized materia ?
	this function has to call the Materia use() function
*/