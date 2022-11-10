/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:20:50 by ljohnson          #+#    #+#             */
/*   Updated: 2022/11/10 15:35:00 by ljohnson         ###   ########lyon.fr   */
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
	std::cout << "Destructor of " << this->name << " called.";
	std::cout << "\033[0m" << std::endl;
	return ;
}

/* ************************************************************************** */
/* Member functions */
/* ************************************************************************** */
void	Zombie::announce() const
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name) {this->name = name;}
