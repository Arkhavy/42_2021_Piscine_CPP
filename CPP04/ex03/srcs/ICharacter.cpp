/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:38:35 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/13 11:35:28 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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
	std::cout << FAINT;
	std::cout << "ICharacter " << this->name << " constructor called.";
	std::cout << FWHITE << std::endl;
}

ICharacter::ICharacter(ICharacter const& src)
{
	*this = src;
	for (int i = 0; i < 4; i++)
		*this->inventory[i] = new src.inventory[i];
	std::cout << FAINT;
	std::cout << "ICharacter copy constructor called.";
	std::cout << FWHITE << std::endl;
}

ICharacter::~ICharacter()
{
	for (int i = 0; i < 4; i++)
		delete this->inventory[i];
	std::cout << FAINT;
	std::cout << "ICharacter default destructor called.";
	std::cout << FWHITE << std::endl;
}

/* ************************************************************************** */
/* Operator Overloads */
/* ************************************************************************** */
ICharacter&	ICharacter::operator=(ICharacter const& rhs)
{
	this->name = rhs.name;
	for (int i = 0; i < 4; i++;)
		this->inventory[i] = rhs.inventory[i];
}
/* ************************************************************************** */
/* Public Member Functions */
/* ************************************************************************** */
//Interface is full of pure member function blblblbl
