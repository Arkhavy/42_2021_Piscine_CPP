/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:31:01 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/13 16:48:55 by ljohnson         ###   ########lyon.fr   */
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
		this->inventory[i] = NULL;
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
	return (*this);
}

/* ************************************************************************** */
/* Public Member Functions */
/* ************************************************************************** */
void	MateriaSource::learnMateria(AMateria* m)
{
	//ouaf
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	//ouaf
	return (NULL);
}
