/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:03:09 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/16 12:09:58 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Weapon.hpp>


/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
Weapon::Weapon(std::string type)
{
	this->type = type;
	std::cout << "\033[2m" << "Weapon " << this->type << " Constructor called." << "\033[0m" << std::endl;
	return ;
}

Weapon::~Weapon()
{
	if (!this->type.empty())
		std::cout << "\033[2m" << "Default Weapon Destructor called." << "\033[0m" << std::endl;
	else
		std::cout << "\033[2m" << "Weapon " << this->type << " Destructor called." << "\033[0m" << std::endl;
	return ;
}

/* ************************************************************************** */
/* Getters & Setters */
/* ************************************************************************** */
const std::string&	Weapon::getType() {return (this->type);}

void	Weapon::setType(std::string type) {this->type = type;}
