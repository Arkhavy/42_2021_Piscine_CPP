/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:03:09 by ljohnson          #+#    #+#             */
/*   Updated: 2022/11/10 15:41:31 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Weapon.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
Weapon::Weapon(std::string type)
{
	this->type = type;
	std::cout << "\033[2m";
	std::cout << "Weapon " << this->type << " Constructor called.";
	std::cout << "\033[0m" << std::endl;
	return ;
}

Weapon::~Weapon()
{
	std::cout << "\033[2m";
	if (this->type.empty())
		std::cout << "Default Weapon Destructor called.";
	else
		std::cout << "Weapon " << this->type << " Destructor called.";
	std::cout << "\033[0m" << std::endl;
	return ;
}

/* ************************************************************************** */
/* Getters & Setters */
/* ************************************************************************** */
const std::string&	Weapon::getType() {return (this->type);}

void	Weapon::setType(std::string type) {this->type = type;}
