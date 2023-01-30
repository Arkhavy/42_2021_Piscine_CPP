/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:42:58 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/30 15:19:08 by ljohnson         ###   ########lyon.fr   */
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
	std::cout << FAINT;
	std::cout << "Cat default constructor called.";
	std::cout << FWHITE << std::endl;
}

Cat::Cat(std::string type)
{
	this->brain = new Brain();
	this->type = type;
	std::cout << FAINT;
	std::cout << "Cat " << this->type << " constructor called.";
	std::cout << FWHITE << std::endl;
}

Cat::Cat(Cat const& src)
{
	*this = src;
	this->brain = new Brain(*src.brain);
	std::cout << FAINT << CYAN;
	std::cout << "Cat " << this->type << " copy constructor called.";
	std::cout << FWHITE << std::endl;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << FAINT;
	std::cout << "Cat " << this->type << " destructor called.";
	std::cout << FWHITE << std::endl;
}

/* ************************************************************************** */
/* Operator Overloads */
/* ************************************************************************** */
Cat&	Cat::operator=(Cat const& rhs)
{
	this->type = rhs.type;
	this->brain = rhs.brain;
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
