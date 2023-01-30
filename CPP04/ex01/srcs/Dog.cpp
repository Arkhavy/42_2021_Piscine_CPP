/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:43:57 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/30 12:16:10 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include <Dog.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
Dog::Dog()
{
	this->type = "Dog";
	std::cout << FAINT;
	std::cout << "Dog default constructor called.";
	std::cout << FWHITE << std::endl;
}

Dog::Dog(std::string type)
{
	this->type = type;
	std::cout << FAINT;
	std::cout << "Dog " << this->type << " constructor called.";
	std::cout << FWHITE << std::endl;
}

Dog::Dog(Dog const& src)
{
	*this = src;
	std::cout << FAINT << CYAN;
	std::cout << "Dog " << this->type << " copy constructor called.";
	std::cout << FWHITE << std::endl;
}

Dog::~Dog()
{
	std::cout << FAINT;
	std::cout << "Dog " << this->type << " destructor called.";
	std::cout << FWHITE << std::endl;
}

/* ************************************************************************** */
/* Operator Overloads */
/* ************************************************************************** */
Dog&	Dog::operator=(Dog const& rhs)
{
	this->type = rhs.type;
	return (*this);
}

/* ************************************************************************** */
/* Public Member Functions */
/* ************************************************************************** */
void	Dog::makeSound() const
{
	std::cout << PURPLE << BOLD;
	std::cout << this->type;
	std::cout << FWHITE;
	std::cout << " is making a Dog sound ! OUAF !" << std::endl;
}
