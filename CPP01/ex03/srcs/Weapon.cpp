/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:03:09 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/16 11:07:18 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Weapon.hpp>


/* ************************************************************************** */
/* Constructors & Destructors Section */
/* ************************************************************************** */
Weapon::Weapon()
{
	std::cout << "\033[2m" << "Default Weapon Constructor called." << "\033[0m" << std::endl;
	return ;
}

Weapon::~Weapon()
{
	std::cout << "\033[2m" << "Default Weapon Desstructor called." << "\033[0m" << std::endl;
	return ;
}

/* ************************************************************************** */
/* Getters & Setters Section */
/* ************************************************************************** */
const std::string&	Weapon::get_type() {return (this->type);}

void	Weapon::set_type(std::string type) {this->type = type;}
