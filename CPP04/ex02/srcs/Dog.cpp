/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:43:57 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/16 18:15:01 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Dog.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << FAINT << PURPLE;
	std::cout << "Dog default constructor called.";
	std::cout << FWHITE << std::endl;
}

Dog::Dog(std::string type)
{
	this->type = type;
	this->brain = new Brain();
	std::cout << FAINT << PURPLE;
	std::cout << "Dog " << this->type << " constructor called.";
	std::cout << FWHITE << std::endl;
}

Dog::Dog(Dog const& src) : AAnimal(src)
{
	*this = src;
	delete this->brain;
	this->brain = new Brain(*src.brain);
	std::cout << FAINT << PURPLE;
	std::cout << "Dog " << this->type << " copy constructor called.";
	std::cout << FWHITE << std::endl;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << FAINT << PURPLE;
	std::cout << "Dog " << this->type << " destructor called.";
	std::cout << FWHITE << std::endl;
}

/* ************************************************************************** */
/* Operator Overloads */
/* ************************************************************************** */
Dog&	Dog::operator=(Dog const& rhs)
{
	this->type = rhs.type;
	this->brain = new Brain(*rhs.brain);
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

void	Dog::display_ideas() const
{
	for (int i = 0; i < 100; i++)
		std::cout << i << ": " << this->brain->get_one_idea(i) << std::endl;
}

void	Dog::set_brain_idea(unsigned int const index, std::string const& idea)
{
	if (index < 100)
		this->brain->set_one_idea(index, idea);
}