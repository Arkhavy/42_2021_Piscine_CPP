/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:07:07 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/28 11:18:12 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ClapTrap.hpp>

/* ************************************************************************** */
/* Constructors & Destructors */
/* ************************************************************************** */
ClapTrap::ClapTrap() : name("CL4P-TP"), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "\033[2m" << "ClapTrap " << this->name << " default constructor called" << "\033[0m" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "\033[2m" << "ClapTrap " << this->name << " constructor called" << "\033[0m" << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const& src)
{
	*this = src;
	std::cout << "\033[2m" << "ClapTrap " << this->name << " copy constructor called" << "\033[0m" << std::endl;
	return ;
}

ClapTrap::~ClapTrap()
{
	std::cout << "\033[2m" << "ClapTrap " << this->name << " destructor called" << "\033[0m" << std::endl;
	return ;
}

/* ************************************************************************** */
/* Public member functions */
/* ************************************************************************** */
void	ClapTrap::attack(const std::string& target)
{
	if (this->hit_points == 0)
	{
		std::cout << "\033[31m\033[1mA dead " << this->name << " cannot attack " << target << "\033[0m" << std::endl;
		return ;
	}
	if (this->energy_points == 0)
	{
		std::cout << "\033[31m\033[1mAn exhausted " << this->name << " cannot attack " << target << "\033[0m" << std::endl;
		return ;
	}
	this->energy_points--;
	std::cout << "ClapTrap \033[32m\033[1m" << this->name << "\033[0m attacks \033[32m\033[1m" << target << "\033[0m, causing \033[31m\033[1m" << this->attack_damage << "\033[0m damages !" << std::endl;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points == 0)
	{
		std::cout << "\033[31m\033[1mA dead " << this->name << " cannot lose more HP, calm down !" << "\033[0m" << std::endl;
		return ;
	}
	std::cout << "ClapTrap \033[32m\033[1m" << this->name << "\033[0m just took \033[31m\033[1m" << amount << "\033[0m damages !" << std::endl;
	if ((int)(this->hit_points - amount) < 0)
	{
		std::cout << "That one might be a little overkill ... But deserved !" << std::endl; 
		this->hit_points = 0;
		return ;
	}
	this->hit_points -= amount;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit_points == 0)
	{
		std::cout << "\033[31m\033[1mFortunately, a dead " << this->name << " cannot repair itself !\033[0m" << std::endl;
		return ;
	}
	if (this->hit_points == 10)
	{
		std::cout << "\033[31m\033[1mFortunately, a fully repaired " << this->name << " cannot repair itself even more !\033[0m" << std::endl;
		return ;
	}
	if (this->energy_points == 0)
	{
		std::cout << "\033[31m\033[1mAn exhausted " << this->name << " cannot repair itself\033[0m" << std::endl;
		return ;
	}
	std::cout << "ClapTrap \033[32m\033[1m" << this->name << "\033[0m is repairing itself \033[32m\033[1m" << amount << "\033[0m HP" << std::endl;
	this->energy_points--;
	if ((int)(this->hit_points + amount) > 10)
	{
		std::cout << "ClapTrap " << this->name << " is a little bit sad to not be able to repair itself even more..." << std::endl;
		this->hit_points = 10;
		return ;
	}
	this->hit_points += amount;
	return ;
}

/* ************************************************************************** */
/* Arithmetic Operator Overloads */
/* ************************************************************************** */
ClapTrap&	ClapTrap::operator=(ClapTrap const& rhs)
{
	this->name = rhs.name;
	this->hit_points = rhs.hit_points;
	this->energy_points = rhs.energy_points;
	this->attack_damage = rhs.attack_damage;
	return (*this);
}
