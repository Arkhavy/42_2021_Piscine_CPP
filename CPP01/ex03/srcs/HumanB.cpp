/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:57:10 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/19 13:42:24 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <HumanB.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
	std::cout << "\033[2m";
	std::cout << "HumanB " << this->name << " Constructor called.";
	std::cout << "\033[0m" << std::endl;
	return ;
}

HumanB::~HumanB()
{
	std::cout << "\033[2m";
	std::cout << "HumanB " << this->name << " Destructor called.";
	std::cout << "\033[0m" << std::endl;
	return ;
}

/* ************************************************************************** */
/* Getters & Setters */
/* ************************************************************************** */
void	HumanB::setWeapon(Weapon& weapon) {this->weapon = &weapon;}

/* ************************************************************************** */
/* Member functions */
/* ************************************************************************** */
void	HumanB::attack() const
{
	if (!this->weapon)
		std::cout << this->name << " attacks with their bare fists" << std::endl;
	else
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}
