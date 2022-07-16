/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:12:03 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/16 14:42:29 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <HumanA.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
HumanA::HumanA(std::string name, Weapon weapon)
{
	this->name = name;
	this->weapon = &weapon;
	std::cout << "\033[2m" << "HumanA " << this->name << " Constructor called." << "\033[0m" << std::endl;
	return ;
}

HumanA::~HumanA()
{
	std::cout << "\033[2m" << "HumanA " << this->name << " Destructor called." << "\033[0m" << std::endl;
	return ;
}

/* ************************************************************************** */
/* Member functions */
/* ************************************************************************** */
void	HumanA::attack() const
{
	std::cout << this->name << "attacks with their " << this->weapon->getType() << std::endl;
}
