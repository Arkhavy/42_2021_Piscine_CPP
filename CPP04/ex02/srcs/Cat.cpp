/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:42:58 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/14 16:21:48 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Cat.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
Cat::Cat()
{
	this->brain = new Brain();
	this->type = "Cat";
	std::cout << FAINT << CYAN;
	std::cout << "Cat default constructor called.";
	std::cout << FWHITE << std::endl;
}

Cat::Cat(std::string type)
{
	this->brain = new Brain();
	this->type = type;
	std::cout << FAINT << CYAN;
	std::cout << "Cat " << this->type << " constructor called.";
	std::cout << FWHITE << std::endl;
}

Cat::Cat(Cat const& src) : AAnimal(src)
{
	*this = src;
	delete this->brain;
	this->brain = new Brain(*src.brain);
	std::cout << FAINT << CYAN;
	std::cout << "Cat " << this->type << " copy constructor called.";
	std::cout << FWHITE << std::endl;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << FAINT << CYAN;
	std::cout << "Cat " << this->type << " destructor called.";
	std::cout << FWHITE << std::endl;
}

/* ************************************************************************** */
/* Operator Overloads */
/* ************************************************************************** */
Cat&	Cat::operator=(Cat const& rhs)
{
	this->type = rhs.type;
	delete this->brain;
	this->brain = new Brain(*rhs.brain);
	return (*this);
}

/* ************************************************************************** */
/* Public Member Functions */
/* ************************************************************************** */
void	Cat::makeSound() const
{
	std::cout << YELLOW << BOLD;
	std::cout << this->type;
	std::cout << FWHITE;
	std::cout << " is making a Cat sound ! MIAOU !" << std::endl;
}

void	Cat::display_ideas() const
{
	for (int i = 0; i < 100; i++)
		std::cout << i << ": " << this->brain->get_one_idea(i) << std::endl;
}

void	Cat::set_brain_idea(unsigned int const index, std::string const& idea)
{
	if (index < 100)
		this->brain->set_one_idea(index, idea);
}