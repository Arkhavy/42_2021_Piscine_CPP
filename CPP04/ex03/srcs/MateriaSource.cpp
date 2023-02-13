/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:31:01 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/13 18:44:36 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <MateriaSource.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	std::cout << FAINT;
	std::cout << "MateriaSource default constructor called.";
	std::cout << FWHITE << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const& src) : IMateriaSource(src)
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
	std::cout << "MateriaSource copy constructor called.";
	std::cout << FWHITE << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		delete this->inventory[i];
		this->inventory[i] = NULL;
	}
	std::cout << FAINT;
	std::cout << "MateriaSource default destructor called.";
	std::cout << FWHITE << std::endl;
}

/* ************************************************************************** */
/* Operator overloads */
/* ************************************************************************** */
MateriaSource&	MateriaSource::operator=(MateriaSource const& rhs)
{
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
void	MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
	{
		std::cerr << RED << BOLD;
		std::cerr << "The materia you are trying to learn does not exist !";
		std::cerr << FWHITE << std::endl;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			std::cout << "Materia " << m->getType() << " successfully learned !" << std::endl;
			return ;
		}
	}
	std::cerr << RED << BOLD;
	std::cerr << "There is not enough room to learn another Materia !";
	std::cerr << FWHITE << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	if (type != "cure" && type != "ice")
	{
		std::cerr << RED << BOLD;
		std::cerr << "The type given does not match any existing Materia type !";
		std::cerr << FWHITE << std::endl;
		return (NULL);
	}
	for (int i = 0; i < 4; i++)
	{
		if (type == this->inventory[i]->getType())
		{
			std::cout << "Materia " << type << " successfully created !" << std::endl;
			return (this->inventory[i]->clone());
		}
	}
	std::cerr << RED << BOLD;
	std::cerr << "The type given does not match any learned Materia type !";
	std::cerr << FWHITE << std::endl;
	return (NULL);
}
