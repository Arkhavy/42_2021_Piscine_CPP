/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:32:47 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/30 13:27:44 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Animal.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
Animal::Animal() : type("Animal")
{
	std::cout << FAINT;
	std::cout << "Animal default constructor called.";
	std::cout << FWHITE << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << FAINT;
	std::cout << "Animal " << this->type << " constructor called.";
	std::cout << FWHITE << std::endl;
}

Animal::Animal(Animal const& src)
{
	*this = src;
	std::cout << FAINT << CYAN;
	std::cout << "Animal " << this->type << " copy constructor called.";
	std::cout << FWHITE << std::endl;
}

Animal::~Animal()
{
	std::cout << FAINT;
	std::cout << "Animal " << this->type << " destructor called.";
	std::cout << FWHITE << std::endl;
}

/* ************************************************************************** */
/* Operator Overloads */
/* ************************************************************************** */
Animal&	Animal::operator=(Animal const& rhs)
{
	this->type = rhs.type;
	return (*this);
}

/* ************************************************************************** */
/* Public Member Functions */
/* ************************************************************************** */
void	Animal::makeSound() const
{
	std::cout << GREEN << BOLD;
	std::cout << this->type;
	std::cout << FWHITE;
	std::cout << " is making an Animal sound ! GRAOU !" << std::endl;
}

const std::string&	Animal::getType() const {return (this->type);}
void	Animal::setType(std::string type) {this->type = type;}