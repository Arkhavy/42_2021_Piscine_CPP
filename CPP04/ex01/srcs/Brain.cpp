/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:22:26 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/30 15:25:30 by ljohnson         ###   ########lyon.fr   */
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
	std::cout << FAINT;
	std::cout << "Brain default constructor called.";
	std::cout << FWHITE << std::endl;
}

Brain::Brain(Brain const& src)
{
	*this = src;
	std::cout << FAINT << CYAN;
	std::cout << "Brain copy constructor called.";
	std::cout << FWHITE << std::endl;
}

Brain::~Brain()
{
	std::cout << FAINT;
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
void	Brain::set_one_idea(const unsigned int index, const std::string& idea) {this->ideas[index] = idea;}

void	Brain::display_ideas() const
{
	for (int i = 0; i < 100; i++)
		std::cout << i << ": " << this->ideas[i] << std::endl;
}