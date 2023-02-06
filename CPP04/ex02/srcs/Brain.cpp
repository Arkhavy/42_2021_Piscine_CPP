/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:22:26 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/30 17:05:52 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Brain.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "EMPTY";
	std::cout << FAINT << GREEN;
	std::cout << "Brain default constructor called.";
	std::cout << FWHITE << std::endl;
}

Brain::Brain(Brain const& src)
{
	*this = src;
	std::cout << FAINT << GREEN;
	std::cout << "Brain copy constructor called.";
	std::cout << FWHITE << std::endl;
}

Brain::~Brain()
{
	std::cout << FAINT << GREEN;
	std::cout << "Brain default destructor called.";
	std::cout << FWHITE << std::endl;
}
/* ************************************************************************** */
/* Operator Overloads */
/* ************************************************************************** */
Brain&	Brain::operator=(Brain const& src)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
	return (*this);
}
/* ************************************************************************** */
/* Public Member Functions */
/* ************************************************************************** */
void	Brain::set_one_idea(unsigned int const index, std::string const& idea) {this->ideas[index] = idea;}

const std::string&	Brain::get_one_idea(unsigned int const index) const {return (this->ideas[index]);}