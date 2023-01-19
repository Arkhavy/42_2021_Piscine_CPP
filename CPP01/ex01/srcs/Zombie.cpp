/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:20:50 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/19 13:38:56 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
Zombie::Zombie()
{
	std::cout << "\033[2m";
	std::cout << "Default Zombie Constructor called.";
	std::cout << "\033[0m" << std::endl;
	return ;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "\033[2m";
	std::cout << "Constructor of " << this->name << " called.";
	std::cout << "\033[0m" << std::endl;
	return ;
}

Zombie::~Zombie()
{
	std::cout << "\033[2m";
	if (this->name.empty())
		std::cout << "Default Zombie Destructor called.";
	else
		std::cout << "Destructor of " << this->name << " called.";
	std::cout << "\033[0m" << std::endl;
	return ;
}

/* ************************************************************************** */
/* Member functions */
/* ************************************************************************** */
void	Zombie::announce() const
{
	if (this->name.empty())
		std::cout << "Default: BraiiiiiiinnnzzzZ..." << std::endl;
	else
		std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name) {this->name = name;}
