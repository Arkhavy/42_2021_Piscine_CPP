/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:21:34 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/13 16:31:38 by ljohnson         ###   ########lyon.fr   */
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
	std::cout << FAINT;
	std::cout << "IMateriaSource copy constructor called.";
	std::cout << FWHITE << std::endl;
}

IMateriaSource::~IMateriaSource()
{
	std::cout << FAINT;
	std::cout << "IMateriaSource default destructor called.";
	std::cout << FWHITE << std::endl;
}

/* ************************************************************************** */
/* Operator overloads */
/* ************************************************************************** */
AMateria&	AMateria::operator=(AMateria const& rhs)
{
	return (*this);
}

/* ************************************************************************** */
/* Public Member Functions */
/* ************************************************************************** */
//Interface is full of pure member function blblblbl