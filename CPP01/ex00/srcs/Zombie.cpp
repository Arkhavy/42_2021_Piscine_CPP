/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:44:50 by ljohnson          #+#    #+#             */
/*   Updated: 2022/11/10 15:09:06 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
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
