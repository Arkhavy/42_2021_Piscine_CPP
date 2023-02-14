/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:21:34 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/14 10:52:10 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <IMateriaSource.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
IMateriaSource::IMateriaSource()
{
	std::cout << FAINT;
	std::cout << "IMateriaSource default constructor called.";
	std::cout << FWHITE << std::endl;
}

IMateriaSource::IMateriaSource(IMateriaSource const& src)
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
	std::cout << "IMateriaSource copy constructor called.";
	std::cout << FWHITE << std::endl;
}

IMateriaSource::~IMateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		delete this->inventory[i];
		this->inventory[i] = NULL;
	}
	std::cout << FAINT;
	std::cout << "IMateriaSource default destructor called.";
	std::cout << FWHITE << std::endl;
}

/* ************************************************************************** */
/* Operator overloads */
/* ************************************************************************** */
IMateriaSource&	IMateriaSource::operator=(IMateriaSource const& rhs)
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
//Interface is full of pure member function blblblbl